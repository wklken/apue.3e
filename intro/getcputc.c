#include "apue.h"


/* stdin/stdout -> apue.h -> stdio.h 标准输入文件/标准输出文件 */
/* EOF为stdio.h中定义的常量 */

int
main(void)
{
    int c;

    /* 从标准输入中读入一个字符 */
    while ((c = getc(stdin)) != EOF)
        /* 输出到标准输出 */
        if (putc(c, stdout) == EOF)
            err_sys("output error");

    if (ferror(stdin))
        err_sys("input error");

    exit(0);
}
