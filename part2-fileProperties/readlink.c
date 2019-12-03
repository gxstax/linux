#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
	// 首先创建一个file.txt的符号链接
	symlink("./file.txt", "pfile");

	// 读符号链接的信息
	char sym_buf[30] = {0};
	readlink("./pfile", sym_buf, sizeof(sym_buf));
	printf("sym_buf -> %s\n", sym_buf);

	return 0;
}
