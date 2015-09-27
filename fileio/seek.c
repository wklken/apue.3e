#include "apue.h"

int
main(void)
{
    /* lseek, 标准输入, offset=0, 置偏移量为当前位置+0 */
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    exit(0);
}
