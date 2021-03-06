/*
 * Copyright 2018 Intel Corporation, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
import java.security.*;
import sun.security.pkcs11.*;
import javax.crypto.spec.SecretKeySpec;
import java.util.*;
import sun.security.pkcs11.*;
import java.security.interfaces.*;
import javax.net.ssl.*;
import javax.crypto.spec.*;
import java.io.*;
import java.security.cert.*;
import java.security.spec.*;
import sun.security.x509.*;
import java.security.KeyStore.PrivateKeyEntry;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.security.InvalidKeyException;
import java.security.Key;
import java.security.KeyManagementException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.SecureRandom;
import java.security.Security;
import java.security.SignatureException;
import java.security.UnrecoverableKeyException;
import java.security.cert.Certificate;
import java.security.cert.CertificateException;
import java.security.cert.X509Certificate;
import java.util.Date;
import java.util.Random;

import org.bouncycastle.pkcs.PKCS10CertificationRequest;
import org.bouncycastle.asn1.ASN1EncodableVector;
import org.bouncycastle.asn1.ASN1InputStream;
import org.bouncycastle.asn1.ASN1Sequence;
import org.bouncycastle.asn1.DERSequence;
import org.bouncycastle.asn1.x500.X500Name;
import org.bouncycastle.asn1.x500.X500NameBuilder;
import org.bouncycastle.asn1.x500.style.BCStyle;
import org.bouncycastle.asn1.x509.BasicConstraints;
import org.bouncycastle.asn1.x509.Extension;
import org.bouncycastle.asn1.x509.KeyPurposeId;
import org.bouncycastle.asn1.x509.KeyUsage;
import org.bouncycastle.asn1.x509.SubjectKeyIdentifier;
import org.bouncycastle.asn1.x509.SubjectPublicKeyInfo;
import org.bouncycastle.cert.CertIOException;
import org.bouncycastle.cert.X509CertificateHolder;
import org.bouncycastle.cert.X509v3CertificateBuilder;
import org.bouncycastle.cert.bc.BcX509ExtensionUtils;
import org.bouncycastle.cert.jcajce.JcaX509CertificateConverter;
import org.bouncycastle.cert.jcajce.JcaX509v3CertificateBuilder;
import org.bouncycastle.jce.provider.BouncyCastleProvider;
import org.bouncycastle.operator.ContentSigner;
import org.bouncycastle.operator.OperatorCreationException;
import org.bouncycastle.operator.jcajce.JcaContentSignerBuilder;
import org.bouncycastle.asn1.x509.SubjectPublicKeyInfo;
import org.bouncycastle.util.io.pem.PemReader;
import org.bouncycastle.util.io.pem.PemObject;
import org.bouncycastle.asn1.pkcs.CertificationRequest;
import org.bouncycastle.asn1.x509.ExtendedKeyUsage;
import org.bouncycastle.asn1.x509.Extension;
import org.bouncycastle.asn1.x509.GeneralName;
import org.bouncycastle.asn1.x509.GeneralNames;
import org.bouncycastle.cert.jcajce.JcaX509ExtensionUtils;

import javax.xml.bind.DatatypeConverter;
import java.security.cert.X509Certificate;
import java.io.StringWriter;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import static java.nio.file.StandardCopyOption.*;

class ThreadDemo extends Thread {
    private String threadName;
    private PrivateKey key;
    private X509Certificate caCert;

    ThreadDemo( String name, PrivateKey privateKey, X509Certificate cacert) {
        threadName = name;
        key = privateKey;
        caCert = cacert;
    }

    public static final KeyPurposeId[] ASN_WebUsage = new KeyPurposeId[] {
            KeyPurposeId.id_kp_serverAuth,
            KeyPurposeId.id_kp_clientAuth};

    public void run() {

        System.out.println("Running " + threadName);
        try {
            String threadname = threadName+".csr";
            System.out.println(threadName);
            File csrf = new File(threadname);
            Reader pemcsr = new FileReader(csrf);
            PemReader reader = new PemReader(pemcsr);
            PemObject pem = reader.readPemObject();
            PKCS10CertificationRequest csr = new PKCS10CertificationRequest(pem.getContent());

            X500NameBuilder x500NameBld = new X500NameBuilder(BCStyle.INSTANCE);
            x500NameBld.addRDN(BCStyle.C, "US");
            x500NameBld.addRDN(BCStyle.ST, "CA");
            x500NameBld.addRDN(BCStyle.L, "local");
            x500NameBld.addRDN(BCStyle.O, "onap");
            x500NameBld.addRDN(BCStyle.CN, "test.onap.ca");
            X500Name issuer = x500NameBld.build();

            GregorianCalendar gc = new GregorianCalendar();
            Date start = gc.getTime();
            gc.add(GregorianCalendar.DAY_OF_MONTH, 1000);
            Date end = gc.getTime();

            X509Certificate x509;
            byte[] serialish = new byte[24];
            SecureRandom random = new SecureRandom();
            BigInteger bi;
            bi = new BigInteger(serialish);
            X509v3CertificateBuilder xcb = new X509v3CertificateBuilder(issuer, bi,
                    start, end, csr.getSubject(), csr.getSubjectPublicKeyInfo());

            JcaX509ExtensionUtils extUtils = new JcaX509ExtensionUtils();
            xcb.addExtension(Extension.basicConstraints,
                    false, new BasicConstraints(false))
                    .addExtension(Extension.keyUsage,
                            true, new KeyUsage(KeyUsage.digitalSignature
                                    | KeyUsage.keyEncipherment))
                    .addExtension(Extension.extendedKeyUsage,
                            true, new ExtendedKeyUsage(ASN_WebUsage))

                    .addExtension(Extension.authorityKeyIdentifier,
                            false, extUtils.createAuthorityKeyIdentifier(caCert))
                    .addExtension(Extension.subjectKeyIdentifier,
                            false, extUtils.createSubjectKeyIdentifier(caCert.getPublicKey()));

            ContentSigner sigGen = new JcaContentSignerBuilder("SHA256WithRSA").build(key);

            x509 = new JcaX509CertificateConverter().getCertificate(xcb.build(sigGen));
            StringWriter sw = new StringWriter();
            sw.write("-----BEGIN CERTIFICATE-----\n");
            sw.write(DatatypeConverter.printBase64Binary(x509.getEncoded()).replaceAll("(.{64})", "$1\n"));
            sw.write("\n-----END CERTIFICATE-----\n");
            FileWriter fw = new FileWriter(threadName +".cert");
            fw.write(sw.toString());
            fw.close();

            System.out.println("Done - Signed certificate is "+ threadName  +".cert");
            System.out.println("Thread: " + threadName);
        }
        catch (Exception e) {
            System.out.println("Thread " +  threadName + " interrupted.");
            e.printStackTrace();
            System.exit(-1);
        }
        System.out.println("Thread " +  threadName + " exiting." + " upon Successful completion");
    }
}

public class CaSignMultiThread {

    public static void main(String[] args) throws Exception {

        if ( args.length < 2 )
            System.out.println("Arguments mismatch, Usage: CaSign  <pin> <alias>");
        for(int i = 0; i < args.length; i++) {
            System.out.println(args[i]);
        }
        // Set up the Sun PKCS 11 provider
        String configName = "pkcs11.cfg";
        Provider p = new SunPKCS11(configName);
        //Provider p = Security.getProvider("SunPKCS11-pkcs11Test");
        if (p==null) {
            throw new RuntimeException("could not get security provider for");
        }
        Security.addProvider(p);
        // Load the key store
        char[] pin = args[0].toCharArray();
        KeyStore keyStore = KeyStore.getInstance("PKCS11", p);
        keyStore.load(null, pin);

        Enumeration<String> aliases = keyStore.aliases();
        while(aliases.hasMoreElements()){
            String alias = aliases.nextElement();
            System.out.println(alias + ": " + keyStore.getKey(alias,args[0].toCharArray()));
        }
        PrivateKeyEntry privateKeyEntry = (PrivateKeyEntry) keyStore.getEntry(args[1], null);
        PrivateKey privateKey = privateKeyEntry.getPrivateKey();

        X509Certificate caCert = (X509Certificate) privateKeyEntry.getCertificate();
        RSAPublicKey publicKey = (RSAPublicKey) caCert.getPublicKey();

        Security.addProvider(new BouncyCastleProvider());

        // Set the number of thread that application need to create
        int threadCount = 9;
        ThreadDemo[] T = new ThreadDemo[threadCount];

        for (int i = 0; i<threadCount; i++) {

            String command0 = "./gencsr.sh "+ i;
            System.out.println(command0);
            try {
                Process p0 = Runtime.getRuntime().exec(command0);
                BufferedReader stdInput = new BufferedReader(new
                        InputStreamReader(p0.getInputStream()));
                BufferedReader stdError = new BufferedReader(new
                        InputStreamReader(p0.getErrorStream()));
            } catch (IOException e) {
                System.out.println("The Error is : ");
                e.printStackTrace();
            }
        }

        String command1 = "chmod 777 *.csr";
        System.out.println(command1);
        try {
            Process p1 = Runtime.getRuntime().exec(command1);
            BufferedReader stdInput = new BufferedReader(new
                    InputStreamReader(p1.getInputStream()));
            BufferedReader stdError = new BufferedReader(new
                    InputStreamReader(p1.getErrorStream()));
        } catch (IOException e) {
            System.out.println("The Error is : ");
            e.printStackTrace();
        }

        for (int i = 0; i<threadCount; i++) {

            T[i] = new ThreadDemo("Thread" + Integer.toString(i), privateKey, caCert);
            T[i].start();
            System.out.println("THe threads are started with execution");
        }

        int count = Thread.activeCount();
        System.out.println("-------------currently active threads = " + count);

        for (int i = 0; i<threadCount; i++) {
            T[i].join();
            System.out.println("The Threads are being joined");
        }

        String command2 =  "chmod 777 *.cert";
        System.out.println(command2);
        try {

            Process p2 = Runtime.getRuntime().exec(command2);
            BufferedReader stdInput = new BufferedReader(new
                    InputStreamReader(p2.getInputStream()));
            BufferedReader stdError = new BufferedReader(new
                    InputStreamReader(p2.getErrorStream()));
        }
        catch (IOException e) {
            System.out.println("The Error is : ");
            e.printStackTrace();
        }

        for (int i = 0; i<threadCount; i++) {

            String command3 = "openssl verify -verbose -CAfile ca.cert " + "Thread" + Integer.toString(i) + ".cert";
            try {
                Process p3 = Runtime.getRuntime().exec(command3);

                BufferedReader stdInput = new BufferedReader(new
                        InputStreamReader(p3.getInputStream()));

                BufferedReader stdError = new BufferedReader(new
                        InputStreamReader(p3.getErrorStream()));

                // read the output from the command
                while ((command3 = stdInput.readLine()) != null) {
                    System.out.println(command3);
                }
                // read any errors from the attempted command
                while ((command3 = stdError.readLine()) != null) {
                    System.out.println(command3);
                    System.out.println("Here is the standard error of the command (if any):\n");
                }
            } catch (IOException e) {
                System.out.println("The exception is ");
                e.printStackTrace();
            }
        }
    }
}

