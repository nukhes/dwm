#!/bin/sh
cp /home/ph/src/dwm/.xinitrc /home/ph/
cp /home/ph/src/dwm/.profile /home/ph/
cd /home/ph/src/dwm
rm -rf ./config.h
doas make clean install
cd /home/ph/src/slstatus
doas make clean install
echo "finished compiling dwm and slstatus"
