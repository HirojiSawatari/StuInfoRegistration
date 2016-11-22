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
		printf("学号[%d]=",i+1);
		scanf("%d",&sArray[i].num);
		if (sArray[i].num==0)
		{
			*count=i;
			break;
		}
		printf("姓名[%d]=",i+1);
		scanf("%s",sArray[i].name);
		printf("出生年[%d]=",i+1);
		scanf("%d",&sArray[i].birthday.year);
		printf("出生月[%d]=",i+1);
		scanf("%d",&sArray[i].birthday.month);
		printf("出生日[%d]=",i+1);
		scanf("%d",&sArray[i].birthday.day);
		printf("年龄[%d]=",i+1);
		scanf("%d",&sArray[i].age);
		printf("年级[%d]=",i+1);
		scanf("%d",&sArray[i].grade);
		printf("专业[%d]=",i+1);
		scanf("%s",&sArray[i].profession);
		printf("****************************\n");
	}
}
void cho(struct student sArray[],struct cl clas[], int count)
{
	int i,j;
	printf("***************************\n");
	printf("1.大学语文(学分4)\n");
	printf("2.高等数学(学分3)\n");
	printf("3.大学英语(学分2)\n");
	printf("4.c程序设计(学分3)\n");
	printf("5.遥感原理(学分2)\n");	
	printf("***************************\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%s第%d门课为：",sArray[i].name,j+1);
			scanf("%d",&clas[i].num[j]);
			if(clas[i].num[j]==1)
			{
				printf("第%d门课为大学语文\n",j+1);
				clas[i].mark[j]=4;
			}
			else if(clas[i].num[j]==2)
			{
				printf("第%d门课为高等数学\n",j+1);
				clas[i].mark[j]=3;
			}
			else if(clas[i].num[j]==3)
			{
				printf("第%d门课为大学英语\n",j+1);
				clas[i].mark[j]=2;
			}
			else if(clas[i].num[j]==4)
			{
				printf("第%d门课为c程序设计\n",j+1);
				clas[i].mark[j]=3;
			}
			else if(clas[i].num[j]==5)
			{
				printf("第%d门课为遥感原理\n",j+1);
				clas[i].mark[j]=2;
			}
			else
			{
				printf("输入错误!\n");
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
			printf("%s的",sArray[i].name);
			if(clas[i].num[j]==1)
				printf("大学语文");
			else if(clas[i].num[j]==2)
				printf("高等数学");
			else if(clas[i].num[j]==3)
				printf("大学英语");
			else if(clas[i].num[j]==4)
				printf("c程序设计");
			else if(clas[i].num[j]==5)
				printf("遥感设计");
			printf("成绩为：");
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
			printf("学号=%d 姓名=%s 出生年月日=%d.%d.%d 年龄=%d 年级=%d 专业=%s\n",sArray[i].num,sArray[i].name,sArray[i].birthday.year,sArray[i].birthday.month,sArray[i].birthday.day,sArray[i].age,sArray[i].grade,sArray[i].profession);
			for(j=0;j<3;j++)
			{
				printf("第%d门课为",j+1);
				if(clas[i].num[j]==1)
					printf("大学语文\n");
				else if(clas[i].num[j]==2)
					printf("高等数学\n");
				else if(clas[i].num[j]==3)
					printf("大学英语\n");
				else if(clas[i].num[j]==4)
					printf("c程序设计\n");
				else if(clas[i].num[j]==5)
					printf("遥感设计\n");
				printf("成绩为：%.2f\n",sArray[i].score[j]);
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
			printf("第%d名学生三门课平均数为：%.2f\n",i+1,sArray[i].ave);
		}
	}
}
void del(struct student sArray[], int count)
{
	int n,i,j;
	printf("输入要删除的学生的学号：");
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
	printf("已删除!\n");
}
void change(struct student sArray[], int count)
{
	int i,j,n;
	printf("输入要修改的学生的学号：");
	scanf("%d",&n);
	for(i=0;i<count;i++)
	{
		if(sArray[i].num==n)
		{			
			for(j=0;j<3;j++)
			{
				printf("第%d门课成绩为：",j+1);
				scanf("%f",&sArray[i].score[j]);
			}
			printf("已修改!\n");
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
	printf("已排序。\n");
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
	printf("已排序。\n");
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
				printf("大学语文");
			else if(i==1)
				printf("高等数学");
			else if(i==2)
				printf("大学英语");
			else if(i==3)
				printf("c程序设计");
			else if(i==4)
				printf("遥感原理");
			printf("平均成绩为%.2f\n",ave[i]);
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
		printf("第%d个学生绩点为%.2f\n",i+1,sArray[i].stuGPA);
	}
}
void print2(struct student sArray[],int count)
{

	int i,j;
	printf("%-6s%-8s%-12s%-5s %-5s %-7s%-7s %-7s %-7s %-7s\n","学号","姓名","出生年月日","年龄","年级","专业","分数一","分数二","分数三","平均分");
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
	printf("************************学生信息登记表************************\n");
	while(1)
	{
		printf("**********************\n");
		printf("输入相应数字以执行指令\n");
		printf("**********************\n");
		printf("输入学生基本信息(1)\n");
		printf("学生选课(2)\n");
		printf("输入学生成绩(3)\n");
		printf("打印数据(4)\n");
		printf("计算平均成绩(5)\n");
		printf("删除数据(6)\n");
		printf("修改成绩(7)\n");
		printf("学生按平均分从小到大排序(8)\n");
		printf("学生按年龄从大到小排序(9)\n");
		printf("求每门课平均分(10)\n");
		printf("计算个人绩点(11)\n");
		printf("以表格形式输出数据(12)\n");
		printf("退出(13)\n");
		printf("**********************\n");
		printf("注：1.学号内输入“0”以结束输入\n");
		printf("    2.请选课后再输入成绩\n");
		printf("    3.打印数据前请计算平均成绩\n");
		printf("**********************\n");
		printf("请输入选项：");
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
			printf("输入错误!\n");
	}
	printf("\n");
	printf("    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("    +              沢渡ソフトウェアのバージョン情報                    +\n");
	printf("    +                    バージョン情報：7.0                           +\n");
	printf("    +               最終アップデート日：2012-06-12                     +\n");
	printf("    +    Copyright 2012 ㈱NIPPON Sawatari Inc. All rights reserved     +\n");
	printf("    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
}
 
