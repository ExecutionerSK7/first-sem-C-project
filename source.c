#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

struct Record{
	char name[30];
	char id[10];
	char weight[7];
	char height[7];
	char gender[8];
	struct DOB{
		int year;
		int month;
		int day;
	} dob;
	char hair[10];
	char eye[10];
	char crime[30];
	char address[30];

} record;

void loadscreen(int time);
void login();
//void addrecord();
//void searchrecord();
//void editrecord();
void viewrecord();
//void deleterecord();

FILE* fp;

void main()
{	
	system("cls");
	mkdir("file");
	loadscreen(100);
	printf("\n\nEnter any key to continue........");
	_getch();
	system("cls");

	int ch;

	//main program loop
	while (1)
	{
		printf("\n\n\n\n\t  ##MAIN MENU##\n");
		//printf("%c\n", 179);
		printf("   %c            ===========              %c\n", 179, 179);
		printf("   %c                                     %c\n", 179, 179);
		printf("   %c  [1] View available records         %c\n", 179, 179);
		printf("   %c  [2] Add a new record               %c\n", 179, 179);
		printf("   %c  [3] Edit existing Record           %c\n", 179, 179);
		printf("   %c  [4] Delete existing Record         %c\n", 179, 179);
		printf("   %c  [5] Search for a Record            %c\n", 179, 179);
		printf("   %c  [6] Exit                           %c\n", 179, 179);
		printf("    -------------------------------------\n");
		printf("\n\n\t\t\tChoose an option.....:\t");
		scanf("%d", &ch);

		switch (ch)
		{

		case 1:
			viewrecord();
			break;

//		case 2:
//			addrecord();
//			break;
/*
		case 3:
			editrecord();
			break;

		case 4:
			deleterecord();
			break;

		case 5:
			searchrecord();
			break;
*/
		case 6:
			system("cls");
			printf("\n\n\t\tThank you for using PRMS. Your program will now exit.\n\n ");
			_getch();
			exit(0);

		default:
			printf("\nYOU ENTERED WRONG CHOICE.");
			printf("\nPRESS ANY KEY TO TRY AGAIN");
			_getch();
			break;

		}
		system("cls");

	}

	login();
}

void loadscreen(int time)
{
	printf("\n\t\t     _____  _____  __  __  _____ ");
	Sleep(time);

	printf("\n\t\t    |  __ \\|  __ \\|  \\/  |/ ____|");
	Sleep(time);

	printf("\n\t\t    | |__) | |__) | \\  / | (___  ");
	Sleep(time);

	printf("\n\t\t    |  ___/|  _  /| |\\/| |\___ \ ");
	Sleep(time);

	printf("\n\t\t    | |    | | \\ \\| |  | |____) |");
	Sleep(time);

	printf("\n\t\t    |_|    |_|  \\_\\_|  |_|_____/ ");
	Sleep(time);
	

}
void login()
{
	int atmpt = 0, i = 0;
	char user[10], c = ' ';
	char pword[10], code[10];
	//char userid[10] = "user";
	//char pass[10] = "pass";
	do
	{
		printf("\n\nWelcome to Police Record Management System. Please enter your login info:\n\n");
		printf("\n  <<<<<<<<<<<<<<<<<<<<<<< PRMS LOGIN >>>>>>>>>>>>>>>>>>>>>>>>>  \n");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &user);
		printf(" \n                       ENTER PASSWORD:-");
		while (i < 10)
		{
			pword[i] = _getch();
			c = pword[i];
			if (c == 13) break;
			else printf("*");
			i++;
		}
		pword[i] = '\0';
		//char code=pword;
		i = 0;
		//scanf("%s",&pword); 
		if (strcmp(user, "user") == 0 && strcmp(pword, "pass") == 0)
		{
			printf("  \n\n\n    LOGIN SUCCESSFUL!! ");
			printf("\n\n\n\t\t\tEnter any key to continue...");
			_getch();//holds the screen
			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			atmpt++;

			_getch();//holds the screen
			system("cls");

		}
	}while (atmpt <= 2);

	if (atmpt > 2)
	{
		printf("\nYou have exceeded the attempt limit! Contact your technical provider!! ");
		_getch();

	}
	system("cls");
}
/*
void addrecord()
{
	system("cls");
	char Y = 'y';
	fflush(stdin);
	char id[10];
	char filename[10];
	int exists = 0;

	printf("\n\n\t\t====================================\n");
	printf("\t\t\t  - ADD RECORDS -");
	printf("\n\t\t====================================\n");
	printf("\n\n\tENTER FIRST NAME OF CONVICT(To Check whether record exists or not): ");
	fflush(stdin);
	gets(filename);

	fp = fopen("file", "ab+");

	if (fp == NULL) {
		fp = fopen("file", "wb+");
		printf("Error while opening record file. Contact your technical team\n");
		printf("Enter any key to exit.....");
		_getch();
		return;
	}

	while (Y == 'Y' || Y == 'y')
	{
		exists = 0;
		fflush(stdin);
		printf("\nEnter convict's id: ");
		scanf("%s", id);
		fflush(stdin);

		rewind(fp);
		while (fread(&record, sizeof(record), 1, fp) == 1)
		{
			if (strcmp(record.id, id) == 0)
			{
				printf("Record already exists.\n");
				exists = 1;
			}
		}

		if (exists == 0) {
			strcpy(record.id, id);
			fflush(stdin);

			printf("Enter name of convict: flushhed");
			fflush(stdin);
			gets(record.name);
			fflush(stdin);

			printf("Enter weight: ");
			fflush(stdin);
			gets(record.weight);
			fflush(stdin);

			printf("Enter height: ");
			fflush(stdin);
			gets(record.height);
			fflush(stdin);

			printf("Enter Date of birth: \n");
			printf("Enter year: ");
			scanf("%d", &record.dob.year);
			printf("Enter month: ");
			scanf("%d", &record.dob.month);
			printf("Enter day: ");
			scanf("%d", &record.dob.day);
			fflush(stdin);
			
			printf("Enter hair color: ");
			fflush(stdin);
			gets(record.hair);
			fflush(stdin);

			printf("Enter eye color: ");
			gets(record.eye);
			fflush(stdin);

			printf("Enter crime committed: ");
			fflush(stdin);
			gets(record.crime);
			fflush(stdin);

			printf("Enter address: ");
			fflush(stdin);
			gets(record.address);
			fflush(stdin);

			fwrite(&record, sizeof(record), 1, fp);
			printf("Your record is added!");
		}

		printf("Add another record? (Y/N)");
		Y = _getch();
	}
	
	fclose(fp);
	printf("\nEnter any key to exit.....");
	_getch();
}
*/

void viewrecord()
{
		system("cls");
		FILE* fp;
		//struct record a;
		char filename[30];

		printf("\n\n\t\t====================================\n");
		printf("\t\t\t - LIST RECORDS -");
		printf("\n\t\t====================================\n");

		fp = fopen("file", "rb");
		rewind(fp);
		while ((fread(&record, sizeof(record), 1, fp)) == 1)
		{
			printf("\n\n\t\t::PRESS ENTER TO VIEW MORE RECORDS!::\n");
			printf("\nCONVICT'S NAME IS: %s", record.name);
			printf("\nCONVICT'S SEX IS: %s", record.gender);
			//printf("\nCONVICT'S AGE IS: %s", .age);
			printf("\nCONVICT'S WEIGHT IS: %s", record.weight);
			printf("\nCONVICT'S HEIGHT IS: %s", record.height);
			printf("\nCONVICT'S HAIRCOLOR IS: %s", record.hair);
			printf("\nCONVICT'S EYECOLOR IS: %s", record.eye);
			printf("\nCONVICT'S CRIME IS: %s", record.crime);
			//printf("\nFACE DETAILS: %s", a.details);
			//printf("\nCOURT IS: %s", a.court);
			//printf("\nACT: %s", a.act);
			//printf("\nCONVICT'S CONVICTION IS: %s", a.punishment);
			printf("\nADDRESS OF POLICE STATION: %s", record.address);
			//printf("\nFIR NUMBER: %s", a.fir);
			//printf("\nCONVICT'S EMERGENCY CONTACT IS: %s", a.emergencyc);
			//printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s", a.emergencyr);
			//printf("\nARRESTED DATE: %s", a.datearr);
			_getch();

		}
		fclose(fp);
		_getch();
}