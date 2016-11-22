#include <stdio.h>
#include <malloc.h>
struct date
{
	int month;
	int day;
	int year;
};
struct student
{
	int num;
	char name[10];
	int age;
	int grade;
	char profession[10];
	float score[3];
	float ave;
	float sMark[3];
	float stuGPA;
	struct date birthday;
};
struct cl
{
	float score[100];
	int num[3];
	int mark[3];
};
void input(struct student sArray[], int *count)
{
	int i;
	for (i=*count;;i++)
	{
		printf("ѧ��[%d]=",i+1);
		scanf("%d",&sArray[i].num);
		if (sArray[i].num==0)
		{
			*count=i;
			break;
		}
		printf("����[%d]=",i+1);
		scanf("%s",sArray[i].name);
		printf("������[%d]=",i+1);
		scanf("%d",&sArray[i].birthday.year);
		printf("������[%d]=",i+1);
		scanf("%d",&sArray[i].birthday.month);
		printf("������[%d]=",i+1);
		scanf("%d",&sArray[i].birthday.day);
		printf("����[%d]=",i+1);
		scanf("%d",&sArray[i].age);
		printf("�꼶[%d]=",i+1);
		scanf("%d",&sArray[i].grade);
		printf("רҵ[%d]=",i+1);
		scanf("%s",&sArray[i].profession);
		printf("****************************\n");
	}
}
void cho(struct student sArray[],struct cl clas[], int count)
{
	int i,j;
	printf("***************************\n");
	printf("1.��ѧ����(ѧ��4)\n");
	printf("2.�ߵ���ѧ(ѧ��3)\n");
	printf("3.��ѧӢ��(ѧ��2)\n");
	printf("4.c�������(ѧ��3)\n");
	printf("5.ң��ԭ��(ѧ��2)\n");	
	printf("***************************\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%s��%d�ſ�Ϊ��",sArray[i].name,j+1);
			scanf("%d",&clas[i].num[j]);
			if(clas[i].num[j]==1)
			{
				printf("��%d�ſ�Ϊ��ѧ����\n",j+1);
				clas[i].mark[j]=4;
			}
			else if(clas[i].num[j]==2)
			{
				printf("��%d�ſ�Ϊ�ߵ���ѧ\n",j+1);
				clas[i].mark[j]=3;
			}
			else if(clas[i].num[j]==3)
			{
				printf("��%d�ſ�Ϊ��ѧӢ��\n",j+1);
				clas[i].mark[j]=2;
			}
			else if(clas[i].num[j]==4)
			{
				printf("��%d�ſ�Ϊc�������\n",j+1);
				clas[i].mark[j]=3;
			}
			else if(clas[i].num[j]==5)
			{
				printf("��%d�ſ�Ϊң��ԭ��\n",j+1);
				clas[i].mark[j]=2;
			}
			else
			{
				printf("�������!\n");
				j--;
			}
		}
	}
}
void input2(struct student sArray[],struct cl clas[], int count)
{	
	int i,j;
	for(i=0;i<count;i++)
	{
		for(j=0;j<3;j++)
		{	
			printf("%s��",sArray[i].name);
			if(clas[i].num[j]==1)
				printf("��ѧ����");
			else if(clas[i].num[j]==2)
				printf("�ߵ���ѧ");
			else if(clas[i].num[j]==3)
				printf("��ѧӢ��");
			else if(clas[i].num[j]==4)
				printf("c�������");
			else if(clas[i].num[j]==5)
				printf("ң�����");
			printf("�ɼ�Ϊ��");
			scanf("%f",&sArray[i].score[j]);
			if(clas[i].num[j]==1)
				clas[0].score[i]=sArray[i].score[j];
			else if(clas[i].num[j]==2)
				clas[1].score[i]=sArray[i].score[j];
			else if(clas[i].num[j]==3)
				clas[2].score[i]=sArray[i].score[j];
			else if(clas[i].num[j]==4)
				clas[3].score[i]=sArray[i].score[j];
			else if(clas[i].num[j]==5)
				clas[4].score[i]=sArray[i].score[j];
		}
	}
}
void print(struct student sArray[],struct cl clas[], int count)
{
	int i,j;
	for (i=0;i<count;i++)
	{
		if(sArray[i].num>0)
		{
			printf("ѧ��=%d ����=%s ����������=%d.%d.%d ����=%d �꼶=%d רҵ=%s\n",sArray[i].num,sArray[i].name,sArray[i].birthday.year,sArray[i].birthday.month,sArray[i].birthday.day,sArray[i].age,sArray[i].grade,sArray[i].profession);
			for(j=0;j<3;j++)
			{
				printf("��%d�ſ�Ϊ",j+1);
				if(clas[i].num[j]==1)
					printf("��ѧ����\n");
				else if(clas[i].num[j]==2)
					printf("�ߵ���ѧ\n");
				else if(clas[i].num[j]==3)
					printf("��ѧӢ��\n");
				else if(clas[i].num[j]==4)
					printf("c�������\n");
				else if(clas[i].num[j]==5)
					printf("ң�����\n");
				printf("�ɼ�Ϊ��%.2f\n",sArray[i].score[j]);
			}
		}
	}
}
void calcAverage(struct student sArray[], int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(sArray[i].num>0)
		{
			int j;
			float sum;
			sum=0;
			for(j=0;j<3;j++)
				sum=sum+sArray[i].score[j];
			sArray[i].ave=sum/3;
			printf("��%d��ѧ�����ſ�ƽ����Ϊ��%.2f\n",i+1,sArray[i].ave);
		}
	}
}
void del(struct student sArray[], int count)
{
	int n,i,j;
	printf("����Ҫɾ����ѧ����ѧ�ţ�");
	scanf("%d",&n);
	for(i=0;i<count;i++)
	{
		if(sArray[i].num==n)
		{
			for(j=i;j<count;j++)
			{
				sArray[j]=sArray[j+1];
			}
		}
	}
	printf("��ɾ��!\n");
}
void change(struct student sArray[], int count)
{
	int i,j,n;
	printf("����Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d",&n);
	for(i=0;i<count;i++)
	{
		if(sArray[i].num==n)
		{			
			for(j=0;j<3;j++)
			{
				printf("��%d�ſγɼ�Ϊ��",j+1);
				scanf("%f",&sArray[i].score[j]);
			}
			printf("���޸�!\n");
		} 
	}
}
void rank1(struct student sArray[], int count)
{
	int i,j;
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-1-i;j++) 
		{
			if(sArray[j].ave>sArray[j+1].ave)
			{ 
				struct student temp;
				temp=sArray[j];
				sArray[j]=sArray[j+1];
				sArray[j+1]=temp;
			}
		}
	}
	printf("������\n");
}
void rank2(struct student sArray[], int count)
{
	int i,j;
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-1-i;j++)
		{
			if(sArray[j].birthday.year>sArray[j+1].birthday.year
				||sArray[j].birthday.year==sArray[j+1].birthday.year&&sArray[j].birthday.month>sArray[j+1].birthday.month
				||sArray[j].birthday.year==sArray[j+1].birthday.year&&sArray[j].birthday.month==sArray[j+1].birthday.month&&sArray[j].birthday.day>sArray[j+1].birthday.day)
			{
				struct student temp;
				temp=sArray[j];
				sArray[j]=sArray[j+1];
				sArray[j+1]=temp;
			}
		}
	}
	printf("������\n");
}
void av(struct cl clas[],int count)
{
	int i,j,n;
	float ave[5];
	for(i=0;i<5;i++)
	{
		n=0;
		ave[i]=0;
		for(j=0;j<count;j++)
		{
			if(clas[i].score[j]>0)
			{
				ave[i]=ave[i]+clas[i].score[j];
				n=n+1;
			}
		}
		ave[i]=ave[i]/n;		
		if(ave[i]>0)
		{	
			if(i==0)
				printf("��ѧ����");
			else if(i==1)
				printf("�ߵ���ѧ");
			else if(i==2)
				printf("��ѧӢ��");
			else if(i==3)
				printf("c�������");
			else if(i==4)
				printf("ң��ԭ��");
			printf("ƽ���ɼ�Ϊ%.2f\n",ave[i]);
		}
	}	
}
void calcGPA(struct student sArray[],struct cl clas[],int count)
{
	int i,j;
	float sumMark,sumGP;
	for (i=0;i<count;i++)
	{
		sumMark=0,sumGP=0;
		for (j=0;j<3;j++)
		{
			if (sArray[i].score[j]>=95)
				sArray[i].sMark[j]=4.5;
			else if (sArray[i].score[j]>=90)
				sArray[i].sMark[j]=4;
			else if (sArray[i].score[j]>=85)
				sArray[i].sMark[j]=3.5;
			else if (sArray[i].score[j]>=80)
				sArray[i].sMark[j]=3;
			else if (sArray[i].score[j]>=75)
				sArray[i].sMark[j]=2.5;
			else if (sArray[i].score[j]>=70)
				sArray[i].sMark[j]=2;
			else if (sArray[i].score[j]>=65)
				sArray[i].sMark[j]=1.5;
			else if (sArray[i].score[j]>=60)
				sArray[i].sMark[j]=1;
			else
				sArray[i].sMark[j]=0;
			sumMark=sumMark+clas[i].mark[j];
			sumGP=sumGP+(clas[i].mark[j]*sArray[i].sMark[j]);
		}
		sArray[i].stuGPA=sumGP/sumMark;
		printf("��%d��ѧ������Ϊ%.2f\n",i+1,sArray[i].stuGPA);
	}
}
void print2(struct student sArray[],int count)
{

	int i,j;
	printf("%-6s%-8s%-12s%-5s %-5s %-7s%-7s %-7s %-7s %-7s\n","ѧ��","����","����������","����","�꼶","רҵ","����һ","������","������","ƽ����");
	for(i=0;i<count;i++)
	{
		if(sArray[i].num>0)
		{
			printf("%-6d%-8s%-d,%-d,%-d %5d%5d%8s",sArray[i].num,sArray[i].name,sArray[i].birthday.year,sArray[i].birthday.month,sArray[i].birthday.day,sArray[i].age,sArray[i].grade,sArray[i].profession);
			for(j=0;j<3;j++)
			{
				printf("%8.2f",sArray[i].score[j]);
			}
			printf("%8.2f\n",sArray[i].ave);
		}
	}
}
void main()
{
	struct student sArray[100];
	struct cl clas[5];
	int len=0;
	int choice;
	printf("************************ѧ����Ϣ�ǼǱ�************************\n");
	while(1)
	{
		printf("**********************\n");
		printf("������Ӧ������ִ��ָ��\n");
		printf("**********************\n");
		printf("����ѧ��������Ϣ(1)\n");
		printf("ѧ��ѡ��(2)\n");
		printf("����ѧ���ɼ�(3)\n");
		printf("��ӡ����(4)\n");
		printf("����ƽ���ɼ�(5)\n");
		printf("ɾ������(6)\n");
		printf("�޸ĳɼ�(7)\n");
		printf("ѧ����ƽ���ִ�С��������(8)\n");
		printf("ѧ��������Ӵ�С����(9)\n");
		printf("��ÿ�ſ�ƽ����(10)\n");
		printf("������˼���(11)\n");
		printf("�Ա����ʽ�������(12)\n");
		printf("�˳�(13)\n");
		printf("**********************\n");
		printf("ע��1.ѧ�������롰0���Խ�������\n");
		printf("    2.��ѡ�κ�������ɼ�\n");
		printf("    3.��ӡ����ǰ�����ƽ���ɼ�\n");
		printf("**********************\n");
		printf("������ѡ�");
		scanf("%d",&choice);
		if (choice==1)
			input(sArray,&len);
		else if (choice==2)
			cho(sArray,clas,len);
		else if (choice==3)
			input2(sArray,clas,len);
		else if (choice==4)
			print(sArray,clas,len);
		else if (choice==5)
			calcAverage(sArray,len);
		else if (choice==6)
			del(sArray,len);
		else if (choice==7)
			change(sArray,len);
		else if (choice==8)
			rank1(sArray,len);
		else if (choice==9)
			rank2(sArray,len);
		else if (choice==10)
			av(clas,len);
		else if (choice==11)
			calcGPA(sArray,clas,len);
		else if (choice==12)
			print2(sArray,len);			
		else if (choice==13)
			break;
		else
			printf("�������!\n");
	}
	printf("\n");
	printf("    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("    +              �g�ɥ��եȥ������ΥЩ`��������                    +\n");
	printf("    +                    �Щ`��������7.0                           +\n");
	printf("    +               ��K���åץǩ`���գ�2012-06-12                     +\n");
	printf("    +    Copyright 2012 �ZNIPPON Sawatari Inc. All rights reserved     +\n");
	printf("    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
}
 
