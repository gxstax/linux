#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
	// 创建符号连接
	/**
	 * 符号链接实际上是一个快捷方式，它有自己的inode节点和数据区，
	 * 数据区存放的是它指向的文件名信息，大小就是指向文件的文件名大小
	 * */
	symlink("./file.txt", "pfile.txt");
	return 0;
}
