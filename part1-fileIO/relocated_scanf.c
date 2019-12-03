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
	fd1 = open(FILE_NAME, O_RDWR|O_APPEND);
	if (-1 == fd1) print_error("fd1 open fail");

	fd2 = dup2(fd1, 0);

	char buf[30] = {0};
	read(fd2, buf, sizeof(fd2));
	printf("buf->%s\n", buf);
	printf("fd1->%d\n", fd1);
	printf("fd2->%d\n", fd2);


	// 功能同dup，只不过在dup2里面，我们可以自己指定新文件描述符
	// 如果这个新文件符已经被打开了，dup2会把它给关闭，然后再使用
	// 这里就是从fd1 复制出fd2，如果fd2之前被打开过，dup2会关闭它，然后再使用

	// 这里并不会出现内容相互覆盖的情况，因为通过dup复制的文件描述符
	// 是指向的同一个文件表，所以的文件位移量是共享的同一个，所以不会出现覆盖

	return 0;
}
