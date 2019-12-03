#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_NAME "./file.txt"




void print_error(char * chars){

	perror(chars);
	exit(-1);
}
int main(void) {
	int fd1 = 0;
	int fd2 = 0;
	int ret = 0;

	/**
	 * 同一个进程内，多个端同时操作同一个文件
	 * 需要用到追加，因为操作统一个文件，虽然文件描述文件不同，
	 * 但是共享同一个v文件，用O_APPEND这个参数，每次写的时候，会把v文件
	 * 的文件长度同步到文件描述符文件的偏移量，所以可以达到同时写一个文件的效果
	 * */

	fd1 = open(FILE_NAME, O_RDWR|O_TRUNC|O_APPEND);
	if (-1 == fd1) print_error("fd1 open fail");

	// 复制一个文件描述符
	fd2 = dup(fd1);

	printf("fd1->%d\n", fd1);
	printf("fd2->%d\n", fd2);

	return 0;
}
