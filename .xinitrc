pipewire &
pipewire-pulse &
wireplumber &
xset m 0 0 &
sudo /home/pedro/scripts/aspm-tuning.sh &
exec dbus-run-session sh -c "slstatus & dwm"

if test -z "$DBUS_SESSION_BUS_ADDRESS" ; then
	eval "dbus-launch --sh-syntax"
fi

