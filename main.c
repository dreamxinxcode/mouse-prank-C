#include <stdlib.h>
#include <time.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>

int main()
{
    //Get system window
    Display *dpy;
    Window root_window;

    dpy = XOpenDisplay(0);
    root_window = XRootWindow(dpy, 0);
    XSelectInput(dpy, root_window, KeyReleaseMask);

    while(True)
    {
        int width = rand() % 1600;
        int height = rand() % 900;
        XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, width, height);

        XFlush(dpy);
        sleep(0.1);
    } 
    return 0;
}

//gcc -Wall mouse.c -o main -lX11

