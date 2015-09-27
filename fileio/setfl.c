#include "apue.h"
#include <fcntl.h>

void
set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
    int val;

    /* 必须先取得现有的标志值, 然后根据需求修改它, 最后设置新的标志值 */
    /* 不能只是执行F_SETFD/F_SETFL命令, 这样会关闭以前设置的标志位 */
    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");

    val |= flags;        /* turn on flags */

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}
