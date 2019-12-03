#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
        int fd = 0;

        mode_t ret = 0;

        // 以只写方式打开
        fd = open ("./hole_file.txt", O_RDWR|O_CREAT, 0664);
	if (-1 == fd)
	{
		printf("open fial!\n");
		return 0;
	}

	// 截取指定文件描述符指定的文件长度
	// 如果截取的文件超出了文件的长度，则会产生空洞文件
	// 这个空洞文件只是理论大小
	// 我们可以适用 du filename 命令查看它在块设备上占用的实际大小是 0
	//ftruncate(fd, 8000);

	/** 适用lseek函数制作空洞文件 */
	// 首先用lseek设置的文件的偏移量
	// 然后在偏移量位置写一些东西，那么中间的文件就全部是空洞
	lseek(fd, 8000, SEEK_SET);
	write(fd, "ant", 3);


	return 0;
}
