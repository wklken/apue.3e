#include "apue.h"

int
main(void)
{
    /* getpid得到进程pid */
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}
