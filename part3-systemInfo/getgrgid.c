#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>

int main(void)
{
	/**
	 * 利用组名搜索组文件，获取对应组的信息
	 * 结果：成功-struct group 结构体指针
	 *       失败-返回NULL errno被设置
	 * */
       	//struct group *getgrnam(const char *name);

	/**
	 * 利用组ID搜索组文件，获取对应的组信息
	 * 结果：成功-struct group 结构体指针
	 *       失败-返回NULL，errno被设置
	 * */
       	//struct group *getgrgid(gid_t gid);


	struct group *gp = NULL;

	gp = getgrnam("root");

	/** 组名：x： 组ID */
	printf("%s %s %d ", gp->gr_name, gp->gr_passwd, gp->gr_gid);

	/* 打印组员*/
	int i = 0;
	for(i=0; gp->gr_mem[i] != NULL; i++)
	{
		printf("%s", gp->gr_mem[i]);
	}
	printf("\n");

	return 0;
}
