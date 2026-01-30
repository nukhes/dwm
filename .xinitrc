setxkbmap -model abnt2 -layout br
rclone mount dropbox: ~/dropbox  --vfs-cache-mode full --buffer-size 128M --dir-cache-time 1h --vfs-re
ad-ahead 64M --dropbox-batch-mode async
killall -9 pipewire wireplumber pipewire-pulse 2>/dev/null
pipewire &
sleep 1
pipewire-pulse &
sleep 1
wireplumber &
sleep 1
slstatus &
exec dbus-run-session dwm

if test -z "$DBUS_SESSION_BUS_ADDRESS" ; then
	eval "dbus-launch --sh-syntax"
fi


