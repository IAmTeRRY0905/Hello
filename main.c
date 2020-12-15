
#include<stdio.h>	/*I/O����*/
#include<stdlib.h>	/*����˵��*/
#include<string.h>	/*�ַ�������*/
#define LEN 9		/* �����ź���������ַ���*/
#define N 10		/* ����������*/

int k = 1, n = 0, m = 0, x =0;/* n����ǰ��¼�ľ�������*/

//��������
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

//�ṹ�屣�������Ϣ�U
struct resident
{

	char ResidentId[LEN+1];
	//������
	char ResidentName[LEN+1];
	//��������

	int ResidentAge;
	//��������
	char ResidentSex[LEN+1];
	//�����Ա�
	int number[4];
	//����¥�������
}res[N];


//������
int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}


//��¼����
void login()
/*���뺯��*/
{
    int i,j,flag = 0;
    char r1[LEN + 1];
    printf("�������˺�:\n");
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
    //ͨ��flag��ֵ���ж��˺��Ƿ����
    if (0 == flag)
        {
			printf("�ñ�Ų�����!!!\n");
		}

		if (1 == flag)
            {
			printf("��¼�ɹ�������\n");
			printf("ף������˳��\n");
            x++;
            res[j].number[3]= x;

		    }
		system("pause");

}


//ϵͳ��������
void help()
/*���뺯��*/
{
	printf("\n  ��ӭʹ��ϵͳ������\n");
	printf("\n  ���ν���ϵͳ����ע�������Ϣ;\n");
	printf("\n  ���ղ˵���ʾѡ�����ֱ�Ž��в���;\n");
	printf("\n  ע�������Ϣ��,�мǱ���;\n");
	printf("\n  ��л����ʹ�ã�\n");
}


//��ʽ����Ϣ����
void format()
/*���뺯��*/
{
	char filename[LEN + 1];
	int i = 0;
	printf("������Ҫ��ʽ��������Ϣ���ļ�����\n");
	scanf("%s", filename);
	int j = 0;
	FILE * fp;
	if ((fp = fopen(filename, "r")) == NULL) return 0;
	//���ļ���ȡ��Ϣ
	while (fscanf(fp, "%s %s %d %s %d %d %d  ", &res[j].ResidentId, &res[j].ResidentName, &res[j].ResidentAge, &res[j].ResidentSex, &res[j].number[0], &res[j].number[1], &res[j].number[2]) == 7)
    {

		j++;

    }
	n = j;
	printf("��ʽ���ɹ�!!!");
	return n;
}


//���Ҿ�����Ϣ����
void seek()
/*���뺯��*/
{
	int i, item, flag;
	char r1[21]; /* �������ͱ�������+1Ϊ׼*/
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("�U                        �U\n");
	printf("�U     1.�����Ų�ѯ     �U\n");
	printf("�U     2.����������ѯ     �U\n");
	printf("�U     3.���س�ʼ�˵�     �U\n");
	printf("�U                        �U\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	while (1)
	{
		printf("��ѡ���Ӳ˵����:");
		scanf("%d", &item);
		flag = 0;
		switch (item)
		{
		case 1:
			printf("������Ҫ��ѯ�ľ���ı��:\n");
			scanf("%s", r1);
			for (i = 0; i<n; i++)
			if (strcmp(r1,res[i].ResidentId) == 0)
                /*ͨ���Ƚ��ַ�����ֵ�Ƿ�����ж��˺��Ƿ��ѱ���*/
			{

				flag = 1;
				printf("�پ�����:\n  %s\n",res[i].ResidentId);
				printf("�ھ�������:\n  %s\n",res[i].ResidentName);
				printf("�۾�������:\n  %d\n",res[i].ResidentAge);
				printf("�ܾ����Ա�:\n  %s\n",res[i].ResidentSex);
				printf("��С��¥�����:\n  %d\n",res[i].number[0]);
				printf("�޾���¥��Ԫ���:\n  %d\n",res[i].number[1]);
				printf("�߾����ס�����:\n  %d\n",res[i].number[2]);
				printf("����д���:\n  %d\n",res[i].number[3]);

			}
			if (0 == flag)
				printf("�ñ�Ų����ڣ�\n");
				break;
				/*ͨ��flag��ֵ�жϱ���Ƿ����*/
		case 2:
			    printf("������Ҫ��ѯ�ľ��������:\n");
                scanf("%s", r1);
			for (i = 0; i<n; i++)
			if (strcmp(res[i].ResidentName, r1) == 0)
                /*ͨ���Ƚ��ַ�����ֵ�Ƿ�����ж��˺��Ƿ��ѱ���*/
			{

				flag = 1;
				printf("�پ�����:\n  %s\n",res[i].ResidentId);
				printf("�ھ�������:\n  %s\n",res[i].ResidentName);
				printf("�۾�������:\n  %d\n",res[i].ResidentAge);
				printf("�ܾ����Ա�:\n  %s\n",res[i].ResidentSex);
				printf("�ݾ���¥�����:\n  %d\n",res[i].number[0]);
				printf("�޾���¥��Ԫ���:\n  %d\n",res[i].number[1]);
				printf("�߾����ס�����:\n  %d\n",res[i].number[2]);
				printf("����д���:\n  %d\n",x);

			}
			if (0 == flag)
				printf("�����������ڣ�\n");
				break;
				/*ͨ��flag��ֵ�жϴ������Ƿ����*/
		case 3:
		        return;
		default:printf("����1-3֮��ѡ��\n");
		}
	}
}


//�޸ľ�����Ϣ����
void modify()
/*���뺯��*/
{
	int i, item, num = -1;
	char sex1, r1[LEN + 1], r2[LEN + 1]; /* �������ͱ�������+1Ϊ׼*/
	float number1;
	printf("������ҪҪ�޸ĵľ���ı��:\n");
	scanf("%s", r1);
	for (i = 0; i < n; i++)
    {
		if (strcmp(res[i].ResidentId, r1) == 0)
            /*�Ƚ��ַ����Ƿ����*/
		{
			num = i;
			printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("�U                          �U\n");
			printf("�U   1.�޸�����             �U\n");
			printf("�U   2.�޸�����             �U\n");
			printf("�U   3.�޸��Ա�             �U\n");
			printf("�U   4.�޸ľ���¥�����     �U\n");
			printf("�U   5.�޸ľ���¥��Ԫ���   �U\n");
			printf("�U   6.�޸ľ����ס�����   �U\n");
			printf("�U   7.���س�ʼ�˵�         �U\n");
			printf("�U                          �U\n");
			printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			while (1)
			{
				printf("��ѡ���Ӳ˵����:");
				scanf("%d", &item);
				switch (item)
				{

				case 1:
					printf("�������µ�����:\n");
					scanf("%s", r2);
					strcpy(res[num].ResidentName, r2);
					break;
				case 2:
					printf("�������µ�����:\n");
					scanf("%d", res[num].ResidentAge);
					break;
				case 3:
					printf("�������µ��Ա�:\n");
					scanf("%s", res[num].ResidentSex);

					break;
				case 4:
					printf("�������µľ���¥�����:\n");
					scanf("%d", &number1);
					res[num].number[0] = number1;
					break;
				case 5:
					printf("�������µľ���¥��Ԫ���:\n");
					scanf("%d", &number1);
					res[num].number[1] = number1;
					break;
				case 6:
					printf("�������µľ����ס�����:\n");
					scanf("%d", &number1);
					res[num].number[2] = number1;
					break;
				case 7:
				    return;
				default:
				    printf("����1-7֮��ѡ��\n");

				}
			}
			printf("�޸���ϣ��뼰ʱ���棡\n");
		}
		else
        {

			printf("û�иþ�����!!!");

		}
	}
}


//ע�������Ϣ����
void insert()
 /*���뺯��*/
{
	int i = n, j, flag;
	printf("����������ӵľ�����:\n");
	scanf("%d", &m);
	if (m > 0){
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				printf("�������%dλ����ı��:\n", i + 1);
				scanf("%s", res[i].ResidentId);
				for (j = 0; j < i; j++)
                {
					if (strcmp(res[i].ResidentId, res[j].ResidentId) == 0)
                    {

						printf("�ñ���Ѵ��ڣ����������룡\n");
						flag = 1;
						break;

					}
				}
			}
			printf("�������%d �����������:\n", i+1);
			scanf("%s", res[i].ResidentName);
			printf("�������%d �����������:\n", i+1);
			scanf("%d", &res[i].ResidentAge);
			printf("�������%d ��������Ա�:\n", i+1);
			scanf("%s", &res[i].ResidentSex);
			printf("�������%d ������ľ���¥���\n",i+1);
			scanf("%d", &res[i].number[0]);
			printf("�������%d ������ľ���¥��Ԫ���:\n", i+1);
			scanf("%d", &res[i].number[1]);
			printf("�������%d ������ľ�ס�����:\n", i+1);
			scanf("%d", &res[i].number[2]);
			if (0 == flag){
				i++;
			}
		} while (i<n + m);
	}
		n += m;
		printf("������Ϣ������ϣ�����\n");
		system("pause");
}

//ע��������Ϣ����
void del()
/*���뺯��*/
{
	int i, j, flag = 0;
	char r1[LEN + 1];
	printf("������Ҫע������ı��:\n");
	scanf("%s", r1);
	for (i = 0; i < n; i++)
	{
		if (strcmp(res[i].ResidentId, r1) == 0)
            /*�Ƚ��ַ����Ƿ����*/
        {
			flag = 1;

			for (j = i; j < n - 1; j++)
            {
				res[j] = res[j + 1];
				//Ҫע���ľ���֮��ľ�����ǰ��һλ
			}
        }
	}

		if (0 == flag){
			printf("�ñ�Ų�����!!!\n");
		}
		//����ʧ��
		if (1 == flag)
            {
			printf("ע���ɹ�������\n");
			n--;
			//ע���ɹ�������������1
		    }
		system("pause");
}


//��ʾ����������Ϣ����
void display()
/*���뺯��*/
{
	int i;
	printf("����%dλ�������Ϣ:\n", n);
	if (0 != n)
	{   printf("  �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("  �U  ������ \t�������� \t�������� \t�����Ա� \t����¥����� \t����¥��Ԫ��� \t�����ס����� \t���д����U\n");
		printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
		for (i = 0; i<n; i++)
		{
		printf("  �U  %s \t%s \t\t%d \t%s \t\t%d \t\t%d  \t\t%d \t\t%d \t�U ", res[i].ResidentId, res[i].ResidentName, res[i].ResidentAge, res[i].ResidentSex, res[i].number[0], res[i].number[1], res[i].number[2], res[i].number[3]);
		}
		printf("  �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	}
	system("pause");
}

//���������Ϣ����
void save()
/*���뺯��*/
{

	int i;
	FILE *fp;
	char filename[LEN + 1];
	printf("������Ҫ������ļ�����\n");
	scanf("%s", filename);
	fp = fopen(filename, "w");
	for (i = 0; i < n; i++)
    {

		fprintf(fp, "%s%s%d%s%d%d%d\n", res[i].ResidentId, res[i].ResidentName, res[i].ResidentAge, res[i].ResidentSex,
			res[i].number[0], res[i].number[1], res[i].number[2]);

	}
	printf("����ɹ�������\n");
	fclose(fp);
	system("pause");

}

void menu()
/*���뺯��*/
{
	int num;
	printf(" \n                    \n");
	printf("  �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("  �U                                                            �U\n");
	printf("  �U                    ���������Ϣ����ϵͳ                    �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("  �U                                                            �U\n");
	printf("  �U                          ϵͳ�˵�                          �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
    printf("  �U                                                            �U\n");
	printf("  �U                     * 1.�����¼�Ǽ�                       �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("  �U                                                            �U\n");
	printf("  �U                     * 2.ϵͳ����˵��                       �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
    printf("  �U                                                            �U\n");
	printf("  �U                     * 3.��ʽ��������Ϣ                     �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("  �U                                                            �U\n");
	printf("  �U                     * 4.��ѯ������Ϣ                       �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("  �U                                                            �U\n");
	printf("  �U                     * 5.�޸ľ�����Ϣ                       �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("  �U                                                            �U\n");
	printf("  �U                     * 6.ע�������Ϣ                       �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
    printf("  �U                                                            �U\n");
	printf("  �U                     * 7.�����ɾ����Ϣ                     �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
    printf("  �U                                                            �U\n");
	printf("  �U                     * 8.��ʾ��ǰ��Ϣ                       �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
    printf("  �U                                                            �U\n");
	printf("  �U                     * 9.���浱ǰ������Ϣ                   �U\n");
	printf("  �U                                                            �U\n");
	printf("  �d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("  �U                                                            �U\n");
	printf("  �U                     * 10.�˳�ϵͳ                          �U\n");
	printf("  �U                                                            �U\n");
	printf("  �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("  ��ѡ��˵����:");
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
		printf("�����˳�����!\n");
		break;
	default:printf("����1-10֮��ѡ��\n");
	}
}