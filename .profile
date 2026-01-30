# Create a local runtime dir if it doesn't exist
if [ ! -d "$HOME/.local/run" ]; then
    mkdir -p "$HOME/.local/run"
    chmod 700 "$HOME/.local/run"
fi

export XDG_RUNTIME_DIR="$HOME/.local/run"

if [ -z "$DBUS_SESSION_BUS_ADDRESS" ]; then
  eval $(dbus-launch --sh-syntax)
fi

exec startx
