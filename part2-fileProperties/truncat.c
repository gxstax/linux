#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
        int fd = 0;

        mode_t ret = 0;

	truncate("./new_file.txt", 10);

        // 以只写方式打开
        fd = open ("./new_file.txt", O_RDWR|O_CREAT, 0777);
	if (-1 == fd)
	{
		printf("open fial!\n");
		return 0;
	}

	// 截取指定文件描述符指定的文件长度
	// 如果截取的文件超出了文件的长度，则会产生空洞文件
	ftruncate(fd, 8);
	return 0;
}
