#!/bin/sh
slstatus &
pulseaudio --start &
sudo /home/pedro/scripts/fix-wifi-wl.sh &
sudo /home/pedro/scripts/aspm-tuning.sh &
setxkbmap -layout us -variant intl &
picom &

exec dbus-run-session -- dwm
