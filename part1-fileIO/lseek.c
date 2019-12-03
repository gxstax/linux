#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){


	int fd = 0;
	int ret = 0;

	fd = open("./file.txt", O_RDWR);
	if (-1 == fd) {
		perror("open fail");
		exit(-1);
	}

	// SEEK_END 偏移量，SEEK_END表示移到文件末尾
        //ret = lseek(fd, 0, SEEK_END);

	// 从文件末尾往前挪动5个字节
	// 第二个参数是起始位置
        //ret = lseek(fd, -5, SEEK_END);


	// SEEK_SET:  偏移量 SEEK_SET表示从文件头开始往后偏移5个字符
        //ret = lseek(fd, 5, SEEK_SET);


	// SEEK_CUR 和设置SEEK_SET一样，因为文件打开默认就是在文件头
        ret = lseek(fd, 5, SEEK_CUR);
	if(-1 == ret) {
		perror("lseek fail");
		exit(-1);
	}

	char buf[30] = {0};
       	read(fd, buf, sizeof(buf));

        printf("buf->%s\n", buf);
	printf("size= %d\n", ret);

}
