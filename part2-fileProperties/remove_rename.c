#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
	//remove("./file1.txt");
	//remove("./file2.txt");
	//remove("./kk");
	rename("./file.txt", "../file2.txt");
	rename("./kk", "../kk");
	return 0;
}
