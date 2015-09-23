#include "apue.h"
#include <dirent.h>

// 可编译执行
// apue.h, 包含某些标准头文件, 定义了很多常量及库函数

int
main(int argc, char *argv[])
{
    DIR                *dp;
    // 结构体
    struct dirent    *dirp;

    // 需要至少一个参数
    if (argc != 2)
        // apue.h自定义函数
        err_quit("usage: ls directory_name");

    // 赋值后判断, opendir返回指向 DIR 结构体的指针
    if ((dp = opendir(argv[1])) == NULL)
        // apue.h自定义函数err_sys
        err_sys("can't open %s", argv[1]);

    // 赋值后判断, 读每一项, 返回指向readdir结构的指针或null(没有目录项可读时)
    while ((dirp = readdir(dp)) != NULL)
        // 取出每个目录的名字
        printf("%s\n", dirp->d_name);

    closedir(dp);

    // 终止程序, 0正常结束, 1-255出错
    exit(0);
}
