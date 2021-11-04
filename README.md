# geled
labs to control LED on GDK8

Steps to compile and run in termimmal:
geduer@gdk8:~/projects$ cd geled
geduer@gdk8:~/projects/geled$ gcc -o geled main.c
geduer@gdk8:~/projects/geled$ ls
bin  geled  led_ht1628.h  main.c  main.cpp  obj
geduer@gdk8:~/projects/geled$ ./geled
GDK8-geled向你问好!
missing arguments
geled: a utility to talk with LED on GDK8
        geled <cmd> [filename]
        c <4 chars to display>
        f - turn off
        n - turn on
for example: geled c 8888
geduer@gdk8:~/projects/geled$ ./geled f
GDK8-geled向你问好!
Can't open device file: /dev/char/241:0
geduer@gdk8:~/projects/geled$ sudo ./geled f
GDK8-geled向你问好!
device is opened with fd = 3
ioctl returne 0, errno 0
geduer@gdk8:~/projects/geled$ sudo ./geled n
GDK8-geled向你问好!
device is opened with fd = 3
ioctl returne 0, errno 0
