#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void){

	int fd = 0;
	int ret = 0;

	fd = open("./file.txt", O_RDONLY);
	if (-1 == fd) {
		perror("open fail");
		exit(-1);
	}

	// 当我们前面定义了只读的时候
	// 如果我们尝试去写，那么会去判断进程表里的文件描述所指向的文件表的文件状态标志位
	// 因为文件标志位是只读，所以这里会报错
	ret = write(fd, "this is Ant\n", 11);
	if (-1 == ret) {
		perror("write fail");
		return -1;
	}

	return 0;
}
