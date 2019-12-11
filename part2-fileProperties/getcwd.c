#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
	// 获取当前线程所在的工作路径
	// 返回值：成功返回缓存buf的地址
	//         失败返回空，错误号errno被设置
	char buf[100] = {0};
	char *p = getcwd(buf, sizeof(buf));

	printf("buf -> %s\n", buf);
	printf("p -> %p\n", p);
	printf("buf -> %p\n", buf);
	return 0;
}
