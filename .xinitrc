setxkbmap -model abnt2 -layout br
rclone mount dropbox: ~/Dropbox --vfs-cache-mode full --buffer-size 128M --dir-cache-time 1h
ad-ahead 64M --dropbox-batch-mode async --vfs-read-chunk-size=32M --vfs-cache-max-age 336h &
pipewire &
pipewire-pulse &
wireplumber &
xset m 0 0 &
exec dbus-run-session sh -c "slstatus & dwm"

if test -z "$DBUS_SESSION_BUS_ADDRESS" ; then
	eval "dbus-launch --sh-syntax"
fi


