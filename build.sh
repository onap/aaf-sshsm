#!/etc/bash

#set -e
#sudo ps -A | grep apt > apt-process
#cat apt-process

sudo rm /var/lib/dpkg/lock
sudo rm /var/lib/apt/lists/lock
sudo rm /var/cache/apt/archives/lock

sudo dpkg --configure -a
sudo apt -y autoremove

sudo apt -y upgrade
echo "upgrade done ..."
sudo apt-get -y install autoconf
#sudo apt-get -y install automake
sudo apt-get -y install libtool
#sudo apt-get -y install autotools-dev
sudo apt -y autoremove
sudo apt -y install tpm2-tools


echo "Build SoftHSMv2..."
cd SoftHSMv2
sh autogen.sh
./configure
make
cd ..

echo "Build TPM2_plugin..."
cd TPM2-Plugin
./bootstrap
./configure
make
cd ..


