#include "apue.h"
#include <sys/wait.h>


/* fork创建一个新进程, 它被调用一次(由父进程调用), 返回两次(在父进程中返回子进程的进程ID, 在子进程中返回0) */

int
main(void)
{
    char    buf[MAXLINE];    /* from apue.h */
    pid_t    pid;
    int        status;

    printf("%% ");    /* print prompt (printf requires %% to print %) */

    /* 读入一行, 每一行命令会产生一个子进程用于执行 */
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        /* 去掉换行符 */
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */

        /* 执行读入的命令 */
        /* fork创建一个子进程, 返回<0则表示fork发生了错误 */
        if ((pid = fork()) < 0) {
            err_sys("fork error");

        /* 对于子进程, fork返回的pid=0(父进程fork返回的pid>0) */
        } else if (pid == 0) {        /* child */

            /* 调用execlp以执行从标准输入读入的命令 */
            /* fork+exec组合, 是某些操作系统所称的产生(spawn)一个新的进程 */
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            /* 退出 */
            exit(127);
        }

        /* 父进程, 等待子进程终止 */
        /* pid为子进程id, status为子进程终止状态(用于判断其实如何终止的) */
        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }
    exit(0);
}
