#!/bin/sh
# ensure we have slstatus
cd /home/pedro/src && git clone --depth 1 https://git.suckless.org/slstatus

cp /home/pedro/src/dwm/.xinitrc /home/pedro
cp /home/pedro/src/dwm/.profile /home/pedro
cd /home/pedro/src/dwm
rm -rf ./config.h
sudo make clean install
cd /home/pedro/src/slstatus
sudo make clean install

echo "finished compiling dwm and slstatus"
