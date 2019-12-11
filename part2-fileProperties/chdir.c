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
	//printf("p -> %p\n", p);
	//printf("buf -> %p\n", buf);


	/**
	 * chdir函数功能：切换进程当前的工作目录到path
	 * 返回值：
	 * 	成功返回 0
	 * 	失败返回 -1 errno被设置
	 */
	chdir("../");
	getcwd(buf, sizeof(buf));
	printf("buf -> %s\n", buf);

	return 0;
}
