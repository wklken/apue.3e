#include "apue.h"

int
main(void)
{
    /* getuid / getgid */
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}
