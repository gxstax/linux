#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_NAME "./file.txt"




void print_error(char * chars){

	perror(chars);
	exit(-1);
}
int main(void) {
	int fd1 = 0;
	int fd2 = 0;
	int flg = 0;

	fd1 = open(FILE_NAME, O_RDWR);
	if (-1 == fd1) print_error("fd1 open fail");

	fd2 = open(FILE_NAME, O_RDWR);
	if (-1 == fd1) print_error("fd1 open fail");

	/**
         * fcntl函数
         * fd: 指向打开的文件
	 * cmd:控制命令，通过指定不同的宏来修改fd所指向文件的性质
	 * （a）F_DUPFD
	 * 	复制描述符，可以用来模拟dup和dup2
	 * 	返回值：返回复制后的新文件描述符
	 * （b）F_GETFL、F_SETFL
	 * 	获取、设置文件状态标志，比如在open时没有指定O_APPEND，可以用fcntl函数来补设置
	 * 	返回值：返回文件的状态标志
	 *
	 * 	什么时候需要fcntl来补设？
	 * 	 当文件描述符不是你自己open得到，而是调用别人给的函数，别人的函数去open某个文件，然后再将文件
	 * 	 描述符返回给你用，在这种情况下，我们是没办法去修改别人的函数，在他调用open函数里补加文件状态标志。
	 * 	 此时就需要fcntl来补设了，使用fcntl补设时，你只需要知道文件描述符即可。
	 *
	 * （c）F_GETFD、F_SETFD
	 *
	 * （d）F_GETOWN、FSETOWN
	 *
	 * （e）F_GETLK、F_SETLK、F_SETLKW
	 * 	加锁/解锁
         **/
       	 //int fcntl(int fd, int cmd, ... /* arg */ );

	/** 模拟两个文件描述符同时写一个文件
	 *  这时候我们就可以用fcntl修改我们open时定义的文件描述标志
	 * */
	flg = O_WRONLY|O_TRUNC|O_APPEND;
	fcntl(fd1, F_SETFL, flg);

	/* 保留原有标志，然后在原有的标志上，叠加新标志 */
	flg = fcntl(fd2, F_GETFL, 0);// 获取原来的
	flg = flg |O_TRUNC | O_APPEND;// 叠加
	fcntl(fd2, F_SETFL, flg);


	while(1) {
		write(fd1, "hello\n", 6);
		sleep(1);
		write(fd2, "world\n", 6);

	}


	printf("fd1->%d\n", fd1);
	printf("fd2->%d\n", fd2);

	return 0;
}
