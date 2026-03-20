#!/bin/sh
slstatus &
syncthing &
setxkbmap -layout us -variant intl &
exec -- dwm
