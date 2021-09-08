#include<stdio.h>
#include<string.h>
#include<ctype.h>
//#include<conio.h>
#include<ctype.h>
/*#include<windows.h>*/
#include<stdlib.h>
#include"struct.h"
#include"fun.h"

int main()
{	int pass;
	int meternumber;
	char ch;



	system("cls");

	printf("\n\n\n\n\n\n\n\n\n______________________________________________________________");
	printf("\n\t\t*******ELECTRICITY BILLING SYSTEM******");                                   
	printf("\n\t\t_________________________________________________________________");
	Sleep(2000);
	getch();
    system("cls");
	while (1)
	{
		system("cls");
		printf("\n Enter\n 1 : Addition of new data.\n 2 : list of Data.");
		printf("\n 3 : Modification of Data.\n 4 : Payments.");
		printf("\n 5 : Search.");
		printf("\n 6 : Deletion.\n 7 :  Exit\n");
		ch=getche();
		ch=toupper(ch);
		switch(ch)
		{
			case '4':
				payment();break;
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				modification();break;
			case '5':
				search();break;
			case '6':
				delete();break;
			case '7':
				system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				printf("\n\n\n\n\n:\n\tFOR USING OUR SERVICE");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();


				
		}
	}
}
