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

	// O_RDWR 只写方式
	// O_CRESAT 如果文件存在直接打开，如果不存在则创建该文件
	// 0664
	//fd = open ("./file.txt", O_RDWR|O_CREAT, 0664);


	// O_RDWR 只写方式
	// O_CRESAT 如果文件存在直接打开，如果不存在则创建该文件
	// O_EXCL 当O_EXCL和O_CREAT同时被指定，打开文件时，如果文件之前就存在话，就会报错
	fd = open ("./file.txt", O_RDWR|O_CREAT|O_EXCL, 0664);

	if (-1 == fd) {
		printf("open fail\n");
		return 0;
	}
	else {
		printf("open ok\n");
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
	printf("buf2->%s", buf2);
	close(fd);
}
