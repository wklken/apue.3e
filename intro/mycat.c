#include "apue.h"

/* 缓冲区大小, 常量 */
#define    BUFFSIZE    4096

int
main(void)
{
    int     n;
    char    buf[BUFFSIZE];

    /* STDIN_FILENO/STDOUT_FILENO -> apue.h -> unisted.h, 标准输入文件描述符0/标准输出文件描述符1 */

    /* 从标准输入读, read返回读得的字节数, 读到末端返回0, 发生错误返回-1 */
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        /* 写到标准输入 */
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    /* 发生错误 */
    if (n < 0)
        err_sys("read error");

    exit(0);
}
