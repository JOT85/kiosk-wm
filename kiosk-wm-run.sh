#!/bin/sh

# Full path to this executable
SELF="$(readlink -f "$0")"

# If we're not in an X session, start one.
if [ "$DISPLAY" == "" ]; then
	exec startx $SELF $@
	exit
fi

# Start kiosk-wm and store its PID
$(dirname "$SELF")/kiosk-wm &
WM_PID=@!

# Execute the argument
$@

# When it's terminated, kill kiosk-wm
kill $WM_PID
