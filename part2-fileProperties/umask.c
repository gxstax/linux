#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
        int fd = 0;

        mode_t ret = 0;

	// 设置文件权限掩码，返回值是旧的文件权限掩码
	ret = umask(0);
	printf("old umask->%d\n", ret);

        // 以只写方式打开
        fd = open ("./new_file.txt", O_RDWR|O_CREAT, 0777);
	if (-1 == fd)
	{
		printf("open fial!\n");
		return 0;
	}

	// 把文件权限掩码设置回去
	ret = umask(ret);
	printf("new Umask -> %d\n", ret);
	return 0;
}
