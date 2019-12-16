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
	 * 功能：将time返回的总秒数，转为国际时间的年 月 日 时 分 秒
	 *       然后开辟一个struct tm 结构体变量，将年 月 日 时 分 秒 放到 tm 结构体中
	 *       struct tm {
         *      int tm_sec;    //Seconds (0-60)
         *      int tm_min;    // Minutes (0-59)
         *      int tm_hour;   // Hours (0-23)
         *      int tm_mday;   // Day of the month (1-31)
         *      int tm_mon;    // Month (0-11)
         *      int tm_year;   // Year - 1900
         *      int tm_wday;   // Day of the week (0-6, Sunday = 0)
         *      int tm_yday;   // Day in the year (0-365, 1 Jan = 0)
         *      int tm_isdst;  // Daylight saving time
         *  };
	 * 参数：保存总秒数的缓存地址，这个总秒数，我们需要调用time函数得到
	 * 返回值：转换后的时间字符串的指针
	 *         失败-返回NULL
	 */
        //struct tm *gmtime(const time_t *timep);

	time_t  timet;
	time(&timet);

	printf("%ld\n", timet);

	struct tm *tmStruct = {0};
	tmStruct = gmtime(&timet);

	printf("%d 年 %d 月 %d 日 %d 时 %d 分  %d 秒\n", tmStruct->tm_year+1900, tmStruct->tm_mon,
			tmStruct->tm_mday, tmStruct->tm_hour,  tmStruct->tm_min, tmStruct->tm_sec);
	// 将结构体转回秒数
        //time_t mktime(struct tm *tm);

	timet = mktime(tmStruct);
	printf("%ld\n", timet);
	return 0;
}
