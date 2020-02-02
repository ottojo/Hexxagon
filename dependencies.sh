#!/usr/bin/env bash

sudo apt install git cmake g++ libssl-dev libudev-dev libopenal-dev libvorbis-dev libflac-dev libxrandr-dev libfreetype6-dev

git clone https://github.com/warmcat/libwebsockets.git
cd libwebsockets
cmake .
make -j$(nproc)
sudo make install
sudo ldconfig
cd ..

git clone https://github.com/ottojo/WebsocketCPP.git
cd WebsocketCPP
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
sudo ldconfig
cd ..

git clone https://github.com/SFML/SFML.git
cd SFML
cmake .
make -j$(nproc)
sudo make install
sudo ldconfig
cd ..

git clone https://github.com/texus/TGUI.git
cd TGUI
cmake .
make -j$(nproc)
sudo apt-get update
sudo apt-get install libtgui-dev
sudo ldconfig
cd ..