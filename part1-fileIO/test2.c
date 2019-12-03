#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
	int fd = 0;

	int ret = 0;
	// 以只写方式打开
	//fd = open ("./file.txt", O_RDWR);

	// 以只读方式打开
	//fd = open ("./file.txt", O_RDONLY);

	// 打开的时候如果文件里面有内容，则删除文件内容
	//fd = open ("./file.txt", O_RDWR|O_TRUNC);


	// 打开的时候如果文件里面有内容，则下次再写的时候内容追加到原来的内容后面
	// 注意：如果不加后面的 O_APPEND参数，则在写的时候会从头部，把文件原来的内容覆盖掉
	//fd = open ("./file.txt", O_RDWR|O_APPEND);

	fd = open ("./file.txt", O_RDWR);

	if (-1 == fd) {
		printf("open fail\n");
		return 0;
	}
	else {
		printf("open ok\n");
		printf("文件描述符fd->%d\n", fd);
	}

	char buf1[]  = "hello world\n";

	 ret = write(fd, (void *)buf1, 12);
	 if (ret == -1) {
	 	printf("write fail\n");
	 }

	 lseek(fd, SEEK_SET, 0);


	char buf2[30] = {0};
	ret = read(fd, buf2, sizeof(buf2));
	if (-1 == ret) {
		printf("read fail\n");
	}

	close(fd);

	fd = open ("./file1.txt", O_RDWR|O_CREAT);
	if (-1 == fd) {
		printf("open file1 fail!!\n");
	} else {
		printf("file1 fd-> %d\n", fd);
	}

	close(fd);
}
