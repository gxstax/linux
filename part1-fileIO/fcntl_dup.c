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
	int ret = 0;

	/**
	 * 同一个进程内，多个端同时操作同一个文件
	 * 需要用到追加，因为操作统一个文件，虽然文件描述文件不同，
	 * 但是共享同一个v文件，用O_APPEND这个参数，每次写的时候，会把v文件
	 * 的文件长度同步到文件描述符文件的偏移量，所以可以达到同时写一个文件的效果
	 * */
	fd1 = open(FILE_NAME, O_RDWR|O_TRUNC|O_APPEND);
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

	/** 模拟dup() */
	// close(1);
	// dup(fd1);

       	//close(1);
	//fd2 = fcntl(fd1, F_DUPFD, 0);
	//printf("hello ant!!\n");

	/** 模拟dup2() */
	//dup2(fd1, 1);

	close(1);
	fd2 = fcntl(fd1, F_DUPFD, 1);
	printf("hahahha\n");

	printf("fd1->%d\n", fd1);
	printf("fd2->%d\n", fd2);

	return 0;
}
