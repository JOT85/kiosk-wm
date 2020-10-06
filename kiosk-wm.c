#include <X11/Xlib.h>

int main() {
    Display *display = XOpenDisplay(0x0);
    if (!display) return 1;

    Window root = DefaultRootWindow(display);

    // This allows us to receive CreateNotify and ConfigureNotify events.
    XSelectInput(display, root, SubstructureNotifyMask);

    for(;;) {
        XEvent ev;
        XNextEvent(display, &ev);

        if (ev.type == CreateNotify) {
            // MoveResize all created windows.
            XMoveResizeWindow(display, ev.xcreatewindow.window, 0, 0, 1920, 1080);
        } else if (ev.type == ConfigureNotify) {
            // We may also need to catch windows that move or resize themselves.
            // A lot of applications resize their windows immediately after creating them.
            XConfigureEvent ce = ev.xconfigure;
            // Only MoveResize if it's not correct already.
            if (
                ce.x != 0
                || ce.y != 0
                || ce.width != 1920
                || ce.height != 1080
            ) {
                XMoveResizeWindow(display, ce.window, 0, 0, 1920, 1080);
            }
        }
    }

    return 0;
}
