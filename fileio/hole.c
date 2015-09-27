#include "apue.h"
#include <fcntl.h>

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";

int
main(void)
{
    int fd;

    /* 创建一个文件 */
    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("creat error");

    /* 写入第一部分内容 */
    if (write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    /* offset now = 10 */

    /* 重设当前偏移量, 超过文件长度 */
    if (lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");
    /* offset now = 16384 */

    /* 写入第二部分 */
    if (write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    /* offset now = 16394 */

    exit(0);
}
