#!/bin/bash

sudo apt update
sudo apt install build-essential gcc-6 g++-6

pushd /tmp/

curl -LO https://developer.nvidia.com/compute/cuda/9.1/Prod/local_installers/cuda_9.1.85_387.26_linux
curl -LO https://developer.nvidia.com/compute/cuda/9.1/Prod/patches/1/cuda_9.1.85.1_linux
curl -LO https://developer.nvidia.com/compute/cuda/9.1/Prod/patches/2/cuda_9.1.85.2_linux
curl -LO https://developer.nvidia.com/compute/cuda/9.1/Prod/patches/3/cuda_9.1.85.3_linux

# do not install driver or samples
sudo sh cuda_9.1.85_387.26_linux --silent --override --toolkit

# install the patches
sudo sh cuda_9.1.85.1_linux --silent --accept-eula
sudo sh cuda_9.1.85.2_linux --silent --accept-eula
sudo sh cuda_9.1.85.3_linux --silent --accept-eula

# set system wide paths
echo 'PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/local/cuda/bin"' | sudo tee /etc/environment
echo /usr/local/cuda-9.1/lib64 | sudo tee /etc/ld.so.conf.d/cuda-9.1.conf
sudo ldconfig

rm /tmp/cuda_9.1.85*_linux
popd
