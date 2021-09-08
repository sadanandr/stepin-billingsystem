#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "fun.h"
#include "struct.h"
void delete()
{
	FILE *f,*t;
	int i=1;
	char meternumber[20];
	if((t=fopen("c:/temp.ojs","w+"))==NULL)
	exit(0);
	if((f=fopen("c:/file.ojs","rb"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Meter Number to be deleted from the Data");
	fflush(stdin);
	scanf("%[^\n]",meternumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.meternumber,meternumber)==0)
		{       i=0;
			continue;

		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       system("cls");
		printf("Meter Number \"%s\" not found",meternumber);
		remove("c:/file.ojs");
		rename("c:/temp.ojs","c:/file.ojs");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	remove("c:/file.ojs");
	rename("c:/temp.ojs","c:/file.ojs");
	system("cls");
	printf("The Meter Number %s Successfully Deleted!!!!",meternumber);
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
	FILE *f;
	char meternumber[20];
	int flag=1;
	f=fopen("c:/file.ojs","rb+");
	if(f==0)
		exit(0);
	fflush(stdin);
	system("cls");
	printf("Enter Meter Number to search user in our data");
	scanf("%s", meternumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.meternumber,meternumber)==0)
		{	system("cls");
			printf(" Record Found ");
			printf("\n\nMeter Number: %s\nName: %s\nAmount: Rs.%0.2f\n",s.meternumber,s.name,s.billamount);
			flag=0;
			break;
		}
		else if(flag==1)
		{	system("cls");
			printf("Requested Meter Number Not found in our data");
		}
	}
	getch();
	fclose(f);
}

void add()
{
	FILE *f;
	char test;
	f=fopen("c:/file.ojs","ab+");
	if(f==0)
	{   f=fopen("c:/file.ojs","wb+");
		system("cls");
		printf("please wait while we configure your pc");
		printf("/npress any key to continue");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Meter Number:");
		scanf("%s",&s.meternumber);
		printf("\n Enter name of the user:");
		fflush(stdin);
		scanf("%[^\n]",&s.name);
		printf("\n Enter amount:");
		scanf("%f",&s.billamount);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		printf("1 Data successfully added");
		printf("\n Press esc key to exit, any other key to add other record:");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("c:/file.ojs","rb"))==NULL)
		exit(0);
	system("cls");
	printf("Meter Number\t\tUser Name\t\t\tAmount\n");
	for(i=0;i<79;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%-10s\t\t%-20s\t\tRs. %.2f /-",s.meternumber,s.name,s.billamount);
	}
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}

void payment()
{
	FILE *f;
	char meternumber[20];
	long int size=sizeof(s);
	float amount;
	int i;
	if((f=fopen("c:/file.ojs","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Meter Number of the subscriber for payment");
	scanf("%[^\n]",meternumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.meternumber,meternumber)==0)
		{
			system("cls");
			printf("\n Meter Num.: %s",s.meternumber);
			printf("\n Name: %s",s.name);
			printf("\n Current amount: %f",s.billamount);
			printf("\n");
			for(i=0;i<79;i++)
				printf("-");
			printf("\n\nEnter amount of payment :");
			fflush(stdin);
			scanf(" %f",&amount);
			s.billamount=s.billamount-amount;
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	system("cls");
	printf("THANK YOU %s FOR USING OUR SERVICE",s.name);
	getch();
	fclose(f);
}

void modification()
{
	FILE *f;
	char meternumber[20];
	long int size=sizeof(s);
	if((f=fopen("c:/file.ojs","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Meter Number of the user to modify:");
	scanf("%[^\n]",meternumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.meternumber,meternumber)==0)
		{
			system("cls");
			printf("\n Enter Meter Number:");
			scanf("%s",&s.meternumber);
			printf("\n Enter name: ");
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			printf("\n Enter amount: ");
			scanf("%f",&s.billamount);
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	fclose(f);
}
