#!/bin/sh
slstatus &
exec dbus-run-session -- dwm
