#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

struct Record{
	char name[30];
	char id[10];
	char weight[10];
	char height[10];
	char gender[10];
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
void addrecord();
//void searchrecord();
//void editrecord();
void viewrecord();
void deleterecord();

FILE* fp, * ft;

void main()
{	
	system("cls");
	mkdir("file");
	loadscreen(100);
	login();
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

		case 2:
			addrecord();
			break;

//		case 3:
//			editrecord();
//			break;

		case 4:
			deleterecord();
			break;

/*		case 5:
			searchrecord();
			break;
*/
		case 6:
			system("cls");
			printf("\n\n\t\tThank you for using PRMS. Your program will now exit.\n\n ");
			getch();
			exit(0);

		default:
			printf("\nYOU ENTERED WRONG CHOICE.");
			printf("\nPRESS ANY KEY TO TRY AGAIN");
			getch();
			break;

		}
		system("cls");

	}

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

	do
	{
		printf("\n\nWelcome to Police Record Management System. Please enter your login info:\n\n");
		printf("\n  <<<<<<<<<<<<<<<<<<<<<<< PRMS LOGIN >>>>>>>>>>>>>>>>>>>>>>>>>  \n");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &user);
		printf(" \n                       ENTER PASSWORD:-");
		while (i < 10)
		{
			pword[i] = getch();
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
			getch();//holds the screen
			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			atmpt++;

			getch();//holds the screen
			system("cls");

		}
	}while (atmpt <= 2);

	if (atmpt > 2)
	{
		printf("\nYou have exceeded the attempt limit! Contact your technical provider!! ");
		getch();

	}
	system("cls");
}

void addrecord()

{
	system("cls");
	char Y = 'Y', id[10];
	char filename[30];
	int exists;

	printf("\n\n\t\t====================================\n");
	printf("\t\t\t  - ADD RECORDS -");
	printf("\n\t\t====================================\n");


	fp = fopen("filename", "ab+");

	if (fp == NULL)
	{
		fp = fopen("filename", "wb+");
		if (fp == NULL)
		{
			printf("\nSYSTEM ERROR...");
			printf("\nPRESS ANY KEY TO EXIT");
			getch();
			return;
		}
	}

	while (Y == 'Y' || Y == 'y')

	{
		exists = 0;
		fseek(stdin, 0, SEEK_END);

		printf("\tENTER CONVICT CODE(To check whether it matches or not): ");
		scanf("%s", id);

		rewind(fp);

		while (fread(&record, sizeof(record), 1, fp) == 1)
		{
			if (strcmp(record.id, id) == 0)
			{

				printf("\n\tTHE RECORD ALREADY EXISTS.\n");
				exists = 1;

			}

		}

		if (exists == 0)
		{

			strcpy(record.id, id);

			printf("\n\tENTER NAME OF CONVICT: ");
			fseek(stdin, 0, SEEK_END);
			gets(record.name);

			printf("\tENTER SEX: ");
			gets(record.gender);
			fseek(stdin, 0, SEEK_END);
	
			printf("Enter date of birth...\n");
			printf("Enter year: ");
			scanf("%d", &record.dob.year);
			printf("Enter month: ");
			scanf("%d", &record.dob.month);
			printf("Enter day: ");
			scanf("%d", &record.dob.day);

			printf("\tENTER WEIGHT: ");
			gets(record.weight);
			fseek(stdin, 0, SEEK_END);

			printf("\tENTER HEIGHT(FT): ");
			gets(record.height);
			fseek(stdin, 0, SEEK_END);

			printf("\tENTER HAIRCOLOR: ");
			gets(record.hair);
			fseek(stdin, 0, SEEK_END);

			printf("\tENTER EYECOLOR: ");
			gets(record.eye);
			fseek(stdin,0,SEEK_END);

			printf("\tENTER CRIME: ");
			gets(record.crime);
			fseek(stdin, 0, SEEK_END);

			printf("\tCOMPLETE ADDRESS OF POLICE STATION: ");
			gets(record.address);
			fseek(stdin, 0, SEEK_END);

			fwrite(&record, sizeof(record), 1, fp);
			printf("\nYOUR RECORD IS ADDED...\n");

		}

		printf("\n\tADD ANOTHER RECORD...(Y/N) \t");
		fseek(stdin, 0, SEEK_END);
		Y = getch();

	}

	fclose(fp);
	printf("\n\n\tPRESS ANY KEY TO EXIT...");
	getch();

}

void deleterecord()
{
	system("cls");
	struct Record U;
	char filename[15], another = 'Y', id[16];;
	int choice, check;
	int j = 0;
	char pass[8];

	printf("\n\n\t\t====================================\n");
	printf("\t\t\t- DELETE RECORDS -");
	printf("\n\t\t====================================\n\n");

	printf("\nENTER PASSWORD\n");
	int i;
	scanf("%s", pass);

	if (strcmpi(pass, "pass") == 0)
	{

		printf("\n\t\t*ACCESS GRANTED*\n\n");
		while (another == 'Y' || another == 'y')

		{
			fp = fopen("filename", "rb");
			if (fp == NULL)
			{
				printf("\nTHE FILE DOES NOT EXIST");
				printf("\nPRESS ANY KEY TO GO BACK.");
				getch();
				return;
			}
			ft = fopen("temp", "wb");

			if (ft == NULL)
			{
				printf("\nSYSTEM ERROR");
				printf("\nPRESS ANY KEY TO GO BACK");
				getch();
				return;
			}
			printf("\n\tENTER THE ID OF RECORD TO BE DELETED:");
			fseek(stdin,0,SEEK_END);
			gets(id);

			while (fread(&U, sizeof(U), 1, fp) == 1)

			{

				if (strcmp(U.id, id) != 0)

					fwrite(&U, sizeof(U), 1, ft);

			}
			fclose(ft);
			fclose(fp);
			remove("filename");
			rename("temp", "filename");
			printf("\nDELETED SUCCESFULLY...");
			getch();

			printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
			fseek(stdin,0,SEEK_END);
			scanf("%c", &another);

		}


		printf("\n\n\tPRESS ANY KEY TO EXIT...");

		getch();
	}
	else
	{
		printf("\nSorry!Invalid password\n");
		printf("Return to main menu....");
		getch();
	}
}

void viewrecord()
{
		system("cls");
		printf("\n\n\t\t====================================\n");
		printf("\t\t\t - LIST OF RECORDS -");
		printf("\n\t\t====================================\n");

		fp = fopen("filename", "rb");
		rewind(fp);
		while ((fread(&record, sizeof(record), 1, fp)) == 1)
		{
			printf("\n\n\t\t::PRESS ENTER TO VIEW MORE RECORDS!::\n");
			printf("\n\n\t\t===========\n");
			printf("\n %c ID = %s                       %c", 179, record.id);
			printf("\n %c Convict's name: %s            %c", 179, record.name);
			printf("\n %c Convict's name: %s            %c", 179, record.name);
			printf("\n %c Convict's gender: %s          %c", 179, record.gender);
			printf("\n %c Convict's weight: %s          %c", 179, record.weight);
			printf("\n %c Convict's height: %s          %c", 179, record.height);
			printf("\n %c Convict's haircolor: %s       %c", 179, record.hair);
			printf("\n %c Convict's eyecolor: %s        %c", 179, record.eye);
			printf("\n %c Convict's crime: %s           %c", 179, record.crime);
			printf("\n %c Address of police station: %s %c", 179, record.address);
			getch();
		}
		fclose(fp);
		getch();
}