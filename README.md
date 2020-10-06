# kiosk-wm
A super simple X11 window manager that centres and full-screens all windows. That's it! No
keybindings, no dragging windows.

## kiosk-wm-run.sh
A simple utility script to start kiosk-wm and run a command.

### Usage
```
kiosk-wm-run.sh command
```

Start kiosk-wm (or exec `startx $0 $@` if `"$DISPLAY" == ""`) and execute `command`.

When `command` terminates, kiosk-wm will also be terminated.


## Building
```
gcc -lX11 -o kiosk-wm kiosk-wm.c
```

## Other Resources
### TinyWM
If you'd like a slightly more sophisticated, but still incredibly simple, window manager to start
hacking on, I'd recommend [tinywm](https://github.com/mackstann/tinywm) - that's where I started!
### libX11 Reference
[www.x.org/releases/current/doc/libX11/libX11/libX11.html](https://www.x.org/releases/current/doc/libX11/libX11/libX11.html)
