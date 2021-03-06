#!/bin/bash
#
# Copyright 2018 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

CASERVICE_DATA="$(pwd)/data/caservice"

echo -n "aaf_cm container ca key import: "
docker run -v $CASERVICE_DATA/host_testnode:/tmp/files \
     -v /tmp/run/dbus:/var/run/dbus:rw \
     -v $CASERVICE_DATA/local:/opt/app/osaaf/local \
     --entrypoint /sshsm/bin/import.sh \
     --name aafca nexus3.onap.org:10001/onap/aaf/aaf_cm >& runaafca.log
grep -q "swKeyImport success: 0x0 !" runaafca.log
if [ "$?" -eq 0 ]; then
    echo Success
    rm -f runaafca.log
else
    grep -q "Created certificate:" runaafca.log
    if [ "$?" -eq 0 ]; then
        echo Success
        rm -f runaafca.log
    else
        echo Failed
        exit 1
    fi
fi
