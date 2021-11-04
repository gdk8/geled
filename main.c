/*
* A simple utility to talk with LED on GDK8 by RaymondZ
* https://www.nanocode.cn/#/gdk8/index 
* Compile on terminal:
* gcc -o geled main.c
* Or you can build using Visual Studio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      /* open */ 
#include <unistd.h>     /* exit */
#include <sys/ioctl.h>  /* ioctl */
#include "led_ht1628.h"
#include <errno.h>

#define DEVICE_FILE_NAME "/dev/char/241:0"

int usage(const char * msg)
{
    printf("%s\n", msg);
    printf("geled: a utility to talk with LED on GDK8\n"
        "\tgeled <cmd> [para] [filename]\n"
        "\tc <4 chars to display>\n"
        "\tf - turn off\n"
        "\tn - turn on\n"
        "for example: geled c 8888\n");
    return -1;
}
int main(int argc, char* argv[])
{
    int ret, fd;
    char* name = DEVICE_FILE_NAME;
    printf("GDK8-%s向你问好!\n", "geled");
    if (argc < 2) {
        return usage("missing arguments");
    }
    if (argc > 3)
        name = argv[3];
    else if (argc > 2 && argv[1][0] != 'c')
        name = argv[2];
    fd = open(name, 0);
    if (fd < 0) {
        printf("Can't open device file: %s\n", name);
        exit(-1);
    }
    printf("device is opened with fd = %d\n", fd);
    switch (argv[1][0]) {
    case 'f':
        ret = ioctl(fd, IOCTL_LED_OFF, 0);
        break;
    case 'n':
        ret = ioctl(fd, IOCTL_LED_ON, 0);
        break;
    case 'c':
        if (argc < 3)
            return usage("missing chars to display");

        ret = ioctl(fd, IOCTL_CHAR_DISPLAY, argv[2]);
        break;
    }
    //
    printf("ioctl returne %d, errno %d\n", ret, errno);

    close(fd);

    return 0;
}