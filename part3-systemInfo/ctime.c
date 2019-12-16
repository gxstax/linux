#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
#include <time.h>
int main(void)
{
	/*
	 * 功能：将time返回的总秒数，转为固定的格式时间，不过这个时间是国际时间，并不是本地时间
	 * 参数：保存总秒数的缓存地址，这个总秒数，我们需要调用time函数得到
	 * 返回值：转换后的时间字符串的指针
	 *         失败-返回NULL
	 */
        //char *ctime(const time_t *timep);

	time_t  timet;
	time(&timet);

	printf("%ld\n", timet);

	char *timeP = NULL;
	timeP = ctime(&timet);

	printf("%s\n", timeP);
	return 0;
}
