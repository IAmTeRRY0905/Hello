
#include<stdio.h>	/*I/O函数*/
#include<stdlib.h>	/*其它说明*/
#include<string.h>	/*字符串函数*/
#define LEN 9		/* 居民编号和姓名最大字符数*/
#define N 10		/* 最大居民人数*/

int k = 1, n = 0, m = 0, x =0;/* n代表当前记录的居民人数*/

//函数声明
void login();
void help();
void format();
void seek();
void modify();
void insert();
void del();
void display();
void save();
void menu();

//结构体保存居民信息║
struct resident
{

	char ResidentId[LEN+1];
	//居民编号
	char ResidentName[LEN+1];
	//居民姓名

	int ResidentAge;
	//居民年龄
	char ResidentSex[LEN+1];
	//居民性别
	int number[4];
	//居民楼各项参数
}res[N];


//主函数
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}


//登录函数
void login()
/*插入函数*/
{
    int i,j,flag = 0;
    char r1[LEN + 1];
    printf("请输入账号:\n");
    scanf("%s", r1);
    for (i = 0; i < n; i++)
    {
    if(strcmp(res[i].ResidentId,r1)==0)

    {
        flag = 1;
        j = i;



    }
    else
    {
        flag = 0;
    }
    }
    //通过flag的值来判断账号是否存在
    if (0 == flag)
        {
			printf("该编号不存在!!!\n");
		}

		if (1 == flag)
            {
			printf("登录成功！！！\n");
			printf("祝您出行顺利\n");
            x++;
            res[j].number[3]= x;

		    }
		system("pause");

}


//系统帮助函数
void help()
/*插入函数*/
{
	printf("\n  欢迎使用系统帮助！\n");
	printf("\n  初次进入系统请先注册居民信息;\n");
	printf("\n  按照菜单提示选择数字编号进行操作;\n");
	printf("\n  注册居民信息后,切记保存;\n");
	printf("\n  感谢您的使用！\n");
}


//格式化信息函数
void format()
/*插入函数*/
{
	char filename[LEN + 1];
	int i = 0;
	printf("请输入要格式化居民信息的文件名：\n");
	scanf("%s", filename);
	int j = 0;
	FILE * fp;
	if ((fp = fopen(filename, "r")) == NULL) return 0;
	//从文件读取信息
	while (fscanf(fp, "%s %s %d %s %d %d %d  ", &res[j].ResidentId, &res[j].ResidentName, &res[j].ResidentAge, &res[j].ResidentSex, &res[j].number[0], &res[j].number[1], &res[j].number[2]) == 7)
    {

		j++;

    }
	n = j;
	printf("格式化成功!!!");
	return n;
}


//查找居民信息函数
void seek()
/*插入函数*/
{
	int i, item, flag;
	char r1[21]; /* 以姓名和编号最长长度+1为准*/
	printf("╔════════════════════════╗\n");
	printf("║                        ║\n");
	printf("║     1.居民编号查询     ║\n");
	printf("║     2.居民姓名查询     ║\n");
	printf("║     3.返回初始菜单     ║\n");
	printf("║                        ║\n");
	printf("╚════════════════════════╝\n");
	while (1)
	{
		printf("请选择子菜单编号:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("请输入要查询的居民的编号:\n");
			scanf("%s", r1);
			for (i = 0; i<n; i++)
			if (strcmp(r1,res[i].ResidentId) == 0)
                /*通过比较字符串的值是否相等判断账号是否已保存*/
			{

				flag = 1;
				printf("①居民编号:\n  %s\n",res[i].ResidentId);
				printf("②居民姓名:\n  %s\n",res[i].ResidentName);
				printf("③居民年龄:\n  %d\n",res[i].ResidentAge);
				printf("④居民性别:\n  %s\n",res[i].ResidentSex);
				printf("⑤小区楼栋编号:\n  %d\n",res[i].number[0]);
				printf("⑥居民楼单元编号:\n  %d\n",res[i].number[1]);
				printf("⑦居民居住房编号:\n  %d\n",res[i].number[2]);
				printf("⑧出行次数:\n  %d\n",res[i].number[3]);

			}
			if (0 == flag)
				printf("该编号不存在！\n");
				break;
				/*通过flag的值判断编号是否存在*/
		case 2:
			    printf("请输入要查询的居民的姓名:\n");
                scanf("%s", r1);
			for (i = 0; i<n; i++)
			if (strcmp(res[i].ResidentName, r1) == 0)
                /*通过比较字符串的值是否相等判断账号是否已保存*/
			{

				flag = 1;
				printf("①居民编号:\n  %s\n",res[i].ResidentId);
				printf("②居民姓名:\n  %s\n",res[i].ResidentName);
				printf("③居民年龄:\n  %d\n",res[i].ResidentAge);
				printf("④居民性别:\n  %s\n",res[i].ResidentSex);
				printf("⑤居民楼栋编号:\n  %d\n",res[i].number[0]);
				printf("⑥居民楼单元编号:\n  %d\n",res[i].number[1]);
				printf("⑦居民居住房编号:\n  %d\n",res[i].number[2]);
				printf("⑧出行次数:\n  %d\n",x);

			}
			if (0 == flag)
				printf("该姓名不存在！\n");
				break;
				/*通过flag的值判断此姓名是否存在*/
		case 3:
		        return;
		default:printf("请在1-3之间选择\n");
		}
	}
}


//修改居民信息函数
void modify()
/*插入函数*/
{
	int i, item, num = -1;
	char sex1, r1[LEN + 1], r2[LEN + 1]; /* 以姓名和编号最长长度+1为准*/
	float number1;
	printf("请输入要要修改的居民的编号:\n");
	scanf("%s", r1);
	for (i = 0; i < n; i++)
    {
		if (strcmp(res[i].ResidentId, r1) == 0)
            /*比较字符串是否相等*/
		{
			num = i;
			printf("╔══════════════════════════╗\n");
			printf("║                          ║\n");
			printf("║   1.修改姓名             ║\n");
			printf("║   2.修改年龄             ║\n");
			printf("║   3.修改性别             ║\n");
			printf("║   4.修改居民楼栋编号     ║\n");
			printf("║   5.修改居民楼单元编号   ║\n");
			printf("║   6.修改居民居住房编号   ║\n");
			printf("║   7.返回初始菜单         ║\n");
			printf("║                          ║\n");
			printf("╚══════════════════════════╝\n");
			while (1)
			{
				printf("请选择子菜单编号:");
				scanf("%d", &item);
				switch (item)
				{

				case 1:
					printf("请输入新的姓名:\n");
					scanf("%s", r2);
					strcpy(res[num].ResidentName, r2);
					break;
				case 2:
					printf("请输入新的年龄:\n");
					scanf("%d", res[num].ResidentAge);
					break;
				case 3:
					printf("请输入新的性别:\n");
					scanf("%s", res[num].ResidentSex);

					break;
				case 4:
					printf("请输入新的居民楼栋编号:\n");
					scanf("%d", &number1);
					res[num].number[0] = number1;
					break;
				case 5:
					printf("请输入新的居民楼单元编号:\n");
					scanf("%d", &number1);
					res[num].number[1] = number1;
					break;
				case 6:
					printf("请输入新的居民居住房编号:\n");
					scanf("%d", &number1);
					res[num].number[2] = number1;
					break;
				case 7:
				    return;
				default:
				    printf("请在1-7之间选择\n");

				}
			}
			printf("修改完毕！请及时保存！\n");
		}
		else
        {

			printf("没有该居民编号!!!");

		}
	}
}


//注册居民信息函数
void insert()
 /*插入函数*/
{
	int i = n, j, flag;
	printf("请输入待增加的居民数:\n");
	scanf("%d", &m);
	if (m > 0){
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("请输入第%d位居民的编号:\n", i + 1);
				scanf("%s", res[i].ResidentId);
				for (j = 0; j < i; j++)
                {
					if (strcmp(res[i].ResidentId, res[j].ResidentId) == 0)
                    {

						printf("该编号已存在，请重新输入！\n");
						flag = 1;
						break;

					}
				}
			}
			printf("请输入第%d 个居民的姓名:\n", i+1);
			scanf("%s", res[i].ResidentName);
			printf("请输入第%d 个居民的年龄:\n", i+1);
			scanf("%d", &res[i].ResidentAge);
			printf("请输入第%d 个居民的性别:\n", i+1);
			scanf("%s", &res[i].ResidentSex);
			printf("请输入第%d 个居民的居民楼编号\n",i+1);
			scanf("%d", &res[i].number[0]);
			printf("请输入第%d 个居民的居民楼单元编号:\n", i+1);
			scanf("%d", &res[i].number[1]);
			printf("请输入第%d 个居民的居住房编号:\n", i+1);
			scanf("%d", &res[i].number[2]);
			if (0 == flag){
				i++;
			}
		} while (i<n + m);
	}
		n += m;
		printf("居民信息增加完毕！！！\n");
		system("pause");
}

//注销居民信息函数
void del()
/*插入函数*/
{
	int i, j, flag = 0;
	char r1[LEN + 1];
	printf("请输入要注销居民的编号:\n");
	scanf("%s", r1);
	for (i = 0; i < n; i++)
	{
		if (strcmp(res[i].ResidentId, r1) == 0)
            /*比较字符串是否相等*/
        {
			flag = 1;

			for (j = i; j < n - 1; j++)
            {
				res[j] = res[j + 1];
				//要注销的居民之后的居民往前移一位
			}
        }
	}

		if (0 == flag){
			printf("该编号不存在!!!\n");
		}
		//查找失败
		if (1 == flag)
            {
			printf("注销成功！！！\n");
			n--;
			//注销成功，居民人数减1
		    }
		system("pause");
}


//显示居民数据信息函数
void display()
/*插入函数*/
{
	int i;
	printf("共有%d位居民的信息:\n", n);
	if (0 != n)
	{   printf("  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
		printf("  ║  居民编号 \t居民姓名 \t居民年龄 \t居民性别 \t居民楼栋编号 \t居民楼单元编号 \t居民居住房编号 \t出行次数║\n");
		printf("  ╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
		for (i = 0; i<n; i++)
		{
		printf("  ║  %s \t%s \t\t%d \t%s \t\t%d \t\t%d  \t\t%d \t\t%d \t║ ", res[i].ResidentId, res[i].ResidentName, res[i].ResidentAge, res[i].ResidentSex, res[i].number[0], res[i].number[1], res[i].number[2], res[i].number[3]);
		}
		printf("  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
	}
	system("pause");
}

//保存居民信息函数
void save()
/*插入函数*/
{

	int i;
	FILE *fp;
	char filename[LEN + 1];
	printf("请输入要保存的文件名：\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	for (i = 0; i < n; i++)
    {

		fprintf(fp, "%s%s%d%s%d%d%d\n", res[i].ResidentId, res[i].ResidentName, res[i].ResidentAge, res[i].ResidentSex,
			res[i].number[0], res[i].number[1], res[i].number[2]);

	}
	printf("保存成功！！！\n");
	fclose(fp);
	system("pause");

}

void menu()
/*插入函数*/
{
	int num;
	printf(" \n                    \n");
	printf("  ╔════════════════════════════════════════════════════════════╗\n");
	printf("  ║                                                            ║\n");
	printf("  ║                    居民出入信息管理系统                    ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
	printf("  ║                                                            ║\n");
	printf("  ║                          系统菜单                          ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
    printf("  ║                                                            ║\n");
	printf("  ║                     * 1.出入记录登记                       ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
	printf("  ║                                                            ║\n");
	printf("  ║                     * 2.系统帮助说明                       ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
    printf("  ║                                                            ║\n");
	printf("  ║                     * 3.格式化居民信息                     ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
	printf("  ║                                                            ║\n");
	printf("  ║                     * 4.查询居民信息                       ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
	printf("  ║                                                            ║\n");
	printf("  ║                     * 5.修改居民信息                       ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
	printf("  ║                                                            ║\n");
	printf("  ║                     * 6.注册居民信息                       ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
    printf("  ║                                                            ║\n");
	printf("  ║                     * 7.按编号删除信息                     ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
    printf("  ║                                                            ║\n");
	printf("  ║                     * 8.显示当前信息                       ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
    printf("  ║                                                            ║\n");
	printf("  ║                     * 9.保存当前居民信息                   ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╠════════════════════════════════════════════════════════════╣\n");
	printf("  ║                                                            ║\n");
	printf("  ║                     * 10.退出系统                          ║\n");
	printf("  ║                                                            ║\n");
	printf("  ╚════════════════════════════════════════════════════════════╝\n");
	printf("  请选择菜单编号:");
	scanf("%d", &num);
	switch (num)
	{
    case 1:login();
    break;
	case 2:help();
    break;
	case 3:format();
	break;
	case 4:seek();
	break;
	case 5:modify();
	break;
	case 6:insert();
	break;
	case 7:del();
	break;
	case 8:display();
	break;
	case 9:save();
	break;
	case 10:
		k = 0;
		printf("即将退出程序!\n");
		break;
	default:printf("请在1-10之间选择\n");
	}
}