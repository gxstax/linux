#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_NAME "./file.txt"

void print_error(char *str)
{
	perror(str);
        exit(-1);
}
int main(int argc, char **argv)
{
	// stat 函数原型
	//int stat(const char *pathname, struct stat *statbuf);

	if(argc != 2)
	{
		printf("./my_ls fileName\n\n");
		exit(-1);
	}

	printf("argv[0]=%s, argv[1]=%s\n", argv[0], argv[1]);

	int ret = 0;

	struct stat sta =
	{
		0
	};

	// 获取文件属性
	ret = lstat(argv[1], &sta);
	if(-1 == ret)
	{
		print_error("stat fail");
	}

	/*     打印文件类型   */
	char file_type = '0';
	switch (sta.st_mode & S_IFMT) {
           case S_IFBLK:  file_type = 'b';                     break;
           case S_IFCHR:  file_type = 'c';                     break;
           case S_IFDIR:  file_type = 'd';                     break;
           case S_IFIFO:  file_type = 'p';                     break;
           case S_IFLNK:  file_type = 'l';                     break;
           case S_IFREG:  file_type = '-';                     break;
           case S_IFSOCK: file_type = 's';                     break;
           default:       file_type = 'u';                     break;
         }
	printf("%c ", file_type);


	/*  打印文件类型  */
	char buf[] = {};
	char tmp_buf[] = "rwxrwxrwx";
	int i = 0;
	for(i=0; i<9; i++)
	{
		if(sta.st_mode & (1<<(8-i)))
		{
		       	buf[i] = tmp_buf[i];
		} else
		{
			buf[i] = '-';
		}
		printf("%c", buf[i]);
	}
	//printf("%s", buf);

	// 打印文件属性
	printf(" %lu %d %d %ld %ld %s\n", sta.st_nlink, sta.st_uid, sta.st_gid, sta.st_size, sta.st_atime, argv[1]);

	return 0;
}
