#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>

#define FILE_NAME "./file.txt"

void print_error(char *str)
{
        perror(str);
        exit(-1);
}
int main(int argc, char **argv)
{
	// 首先创建一个file.txt的符号链接
	symlink("./file.txt", "pfile");

	// 读符号链接的信息
	char sym_buf[30] = {0};
	readlink(argv[1], sym_buf, sizeof(sym_buf));
	printf("sym_buf -> %s\n", sym_buf);

	struct stat sta =
        {
                0
        };

        // 获取文件属性
	int retSts = 0;
        retSts = lstat(argv[1], &sta);
        if(-1 == retSts)
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

	// 获取文件属性
        int ret = lstat(argv[1], &sta);
        if(-1 == ret)
        {
                printf("stat fail\n");
		exit(0);
        }

	char buf[10] = {0};
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
                //printf("%c", buf[i]);
        }
        printf("%s", buf);

	/* 获取文件属性信息*/
	struct passwd *p = NULL;
	p = getpwuid(sta.st_uid);

	/* 获取组信息*/
	struct group *gp = NULL;
	gp = getgrgid(sta.st_gid);

        // 打印文件属性
        printf(" %lu %s %s %ld %ld %s", sta.st_nlink, p->pw_name, gp->gr_name, sta.st_size, sta.st_atime, argv[1]);

	// 如果是链接文件，则打印出来链接文件的信息
	if(file_type == 'l')
        {
                char sym_buf[30] = {0};
                readlink(argv[1], sym_buf, sizeof(sym_buf));
                printf("-> %s\n", sym_buf);
        } else
	{
		printf("\n");
	}

	return 0;
}
