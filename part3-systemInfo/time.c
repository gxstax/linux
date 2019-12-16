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
	 * 功能：返回总秒数
	 * 参数：存放总秒数的缓存地址
	 */
        //time_t time(time_t *tloc);


	time_t  timet;
	time(&timet);

	printf("%ld\n", timet);


	return 0;
}
