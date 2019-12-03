#include <stdio.h>
#include <unistd.h>

int main(void){

	int ret = 0;

	char buf[30] = {0};

#if 0
	//close(0);

	//scanf("%s", buf);
	ret = read(0, (void *)buf, sizeof(buf));

	printf("EOF->%d\n", EOF);

	if (EOF == ret) {
		perror("read fail");
		return -1;
	}

	printf("read buf->%s\n", buf);
        //	close(0);
#endif

#if 1
	/** **************标准输出函数************** */
	int val = 65;
	// 1 标准输出文件描述符
	// &val 取地址
	//write(1, &val, 4);
	//write(1, "\n", 1);

	char buf2[10] = {0};
	buf2[0] = val/10 + '0';
	buf2[1] = val%10 + '0';
	write(1, buf2, 2);
	write(1, "\n", 1);

	// 直接使用printf进行输出
	// printf其实是封装了write
	//printf("%d\n", 65);



	/** **************标准出错函数************** */
	int val3 = 65;

	char buf3[3] = {0};

	// 2 标准出错文件描述符
	write(STDERR_FILENO, "hello world\n", 12);

	// perror函数也是封装了write函数
	// 不过和printf不同的是它是指向2文件描述符
	// 如果我们把2关闭，这里perror就不会输出信息了
	//close(STDIN_FILENO);
	perror("fail");


	// 注意系统为标准文件定义了3个宏,可以使用这3个函数分别代表 0/1/2
	// STDIN_FILENO  标准输入文件描述符
	// STDOUT_FILENO 标准输出文件描述符
	// STDERR_FILENO 标准出错文件描述符

#endif
}
