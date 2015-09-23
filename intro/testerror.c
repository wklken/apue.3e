#include "apue.h"
#include <errno.h>


/* strerror, 将errnum映射为一个出错信息字符串, 并且返回此字符串的指针 */
/* perror, 基于errno的当前值, 在标准出错上产生一条出错信息, 然后返回 */

int
main(int argc, char *argv[])
{
    /* 常量 EACCES / ENOENT */
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}
