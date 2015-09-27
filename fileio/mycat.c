#include "apue.h"

/* 缓冲大小 */
#define    BUFFSIZE    4096

int
main(void)
{
    int        n;
    char    buf[BUFFSIZE];

    /* STDIN_FILENO / STDOUT_FILENO 表示标准输入, 标准输出 */
    /* 所有常用UNIX系统的shell都提供一种方法, 在标准输入上打开一个文件用于读, 在标准输出上创建/重写一个文件, 所以不用自行打开 */
    /* 进程结束, 内核会自动关闭该进程的所有打开的文件描述符 */

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if (n < 0)
        err_sys("read error");

    exit(0);
}
