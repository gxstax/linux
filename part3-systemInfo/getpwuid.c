#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main(void)
{
	/**
	 * 功能：使用用户ID，到etc/passwd 中搜索，并获取对应的账户信息。
	 *
	 * 返回值：成功-返回struct passwd结构体变量的指针
	 *         失败-返回NULL，errno被设置
	 *
	 * */
	//struct passwd *getpwuid(uid_t uid);

	struct passwd *p = NULL;
	p = getpwuid(1000);
	p = getpwnam("ant");

	printf("%s %s %d %d %s %s %s\n",p->pw_name, p->pw_passwd, p->pw_uid, p->pw_gid, p->pw_gecos, p->pw_dir, p->pw_shell );


	return 0;
}
