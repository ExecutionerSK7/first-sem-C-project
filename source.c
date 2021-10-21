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
void editrecord();
void viewrecord();
void deleterecord();

FILE* fp, * ft;

void main()
{	
	system("cls");
	//mkdir("file");
	loadscreen(100);
	login();
	system("cls");

	int ch;

	//main program loop
	while (1)
	{
		printf("\n\n\n\n\t        ##MAIN MENU##\n");
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

		case 3:
			editrecord();
			break;

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
			loadscreen(100);
			Sleep(50);
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

	printf("\n\t\t    |  ___/|  _  /| |\\/| |\\___ \\ ");
	Sleep(time);

	printf("\n\t\t    | |    | | \\ \\| |  | |____) |");
	Sleep(time);

	printf("\n\t\t    |_|    |_|  \\_\\_|  |_|_____/ ");
	Sleep(time);
	printf(" (c) 2021");
	

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
			fseek(stdin, 0, SEEK_END);

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

void editrecord()
{
	system("cls");
	char id[10], select = 'Y', filename[14];
	int choice, count = 0;

	printf("\n\n\t\t====================================\n");
	printf("\t\t\t- MODIFY RECORDS -");
	printf("\n\t\t====================================\n\n");

	do
	{
		printf("\n\tEnter id:");
		fseek(stdin, 0, SEEK_END);
		gets(id);
		fp = fopen("filename", "rb+");

		while (fread(&record, sizeof(record), 1, fp) == 1)
		{

			if (strcmp(record.id, id) == 0)
			{

				printf("\n %c ID = %s                       ", 179, record.id);
				printf("\n %c Convict's name: %s            ", 179, record.name);
				printf("\n %c Convict's date of birth: %d/%d/%d  ", 179, record.dob.year, record.dob.month, record.dob.day);
				printf("\n %c Convict's gender: %s          ", 179, record.gender);
				printf("\n %c Convict's weight: %s          ", 179, record.weight);
				printf("\n %c Convict's height: %s          ", 179, record.height);
				printf("\n %c Convict's haircolor: %s       ", 179, record.hair);
				printf("\n %c Convict's eyecolor: %s        ", 179, record.eye);
				printf("\n %c Convict's crime: %s           ", 179, record.crime);
				printf("\n %c Address of police station: %s ", 179, record.address);

				printf("\n\n\t\tWhich details would you like to edit?");

				printf("\n %c 1.Name.", 179);
				printf("\n %c 2.Birth year ", 179);
				printf("\n %c 3.Birth month ", 179);
				printf("\n %c 4.Birth day ", 179);
				printf("\n %c 5.Gender", 179);
				printf("\n %c 6.Weight", 179);
				printf("\n %c 7.Height", 179);
				printf("\n %c 8.Haircolor", 179);
				printf("\n %c 9.Eyecolor", 179);
				printf("\n %c 10.Crime", 179);
				printf("\n %c 11.Address of police station", 179);
				printf("\n %c 12.Edit whole record", 179);
				printf("\n %c 13.Go back", 179);

				do
				{

					printf("\n\tENTER YOUR CHOICE:");
					fseek(stdin,0,SEEK_END);
					scanf("%d", &choice);
					fseek(stdin,0,SEEK_END);

					switch (choice)
					{
					case 1:
						printf("Enter new name: ");
						gets(record.name);
						break;
					case 2:
						printf("Enter new year: ");
						scanf("%d", &record.dob.year);
						break;
					case 3:
						printf("Enter new month: ");
						scanf("%d", &record.dob.month);
						break;
					case 4:
						printf("Enter new birthday: ");
						scanf("%d", &record.dob.day);
						break;
					case 5:
						printf("Enter new Gender: ");
						gets(record.gender);
						break;
					case 6:
						printf("Enter new weight: ");
						gets(record.weight);
						break;
					case 7:
						printf("Enter new height: ");
						gets(record.height);
						break;
					case 8:
						printf("Enter new haircolor: ");
						gets(record.hair);
						break;
					case 9:
						printf("Enter new eyecolor: ");
						gets(record.eye);
						break;
					case 10:
						printf("Enter new crime: ");
						gets(record.crime);
						break;
					case 11:
						printf("Enter new address: ");
						gets(record.address);
						break;
					case 12:
						printf("ENTER THE NEW DATA:");

						printf("Enter new name: ");
						gets(record.name);

						printf("Enter new Gender: ");
						gets(record.gender);

						printf("Enter new weight: ");
						gets(record.weight);

						printf("Enter new height: ");
						gets(record.height);

						printf("Enter new haircolor: ");
						gets(record.hair);

						printf("Enter new eyecolor: ");
						gets(record.eye);

						printf("Enter new crime: ");
						gets(record.crime);

						printf("Enter new address: ");
						gets(record.address);
						
						break;

					case 13:
						printf("\nPRESS ANY KEY TO GO BACK...\n");
						getch();
						return;
						break;

					default:
						printf("\nInvalid input. Try again.\n");
						break;

					}

				}
				while (choice < 1 || choice>13);

				fseek(fp, -sizeof(record), SEEK_CUR);

				fwrite(&record, sizeof(record), 1, fp);

				//fseek(fp, -sizeof(record), SEEK_CUR);

				//fread(&record, sizeof(record), 1, fp);

				select = 'Y';

				break;

			}
		}

		if (select == 'Y')

		{

			system("cls");

			printf("\n\t\tEDITING COMPLETED...\n");
			printf("--------------------\n");
			printf("THE NEW RECORD IS:\n");
			printf("--------------------\n");
			printf("\n %c ID = %s                       ", 179, record.id);
			printf("\n %c Convict's name: %s            ", 179, record.name);
			printf("\n %c Convict's date of birth: %d/%d/%d  ", 179, record.dob.year, record.dob.month, record.dob.day);
			printf("\n %c Convict's gender: %s          ", 179, record.gender);
			printf("\n %c Convict's weight: %s          ", 179, record.weight);
			printf("\n %c Convict's height: %s          ", 179, record.height);
			printf("\n %c Convict's haircolor: %s       ", 179, record.hair);
			printf("\n %c Convict's eyecolor: %s        ", 179, record.eye);
			printf("\n %c Convict's crime: %s           ", 179, record.crime);
			printf("\n %c Address of police station: %s ", 179, record.address);

			fclose(fp);

			printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
			scanf("%c", &select);
			//select++;

		}
		else
		{

			printf("\nTHE RECORD DOES NOT EXIST::\n");
			printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
			scanf("%c", &select);

		}
	}while (select == 'Y' || select == 'y');

	fclose(fp);
	printf("\tPRESS ENTER TO EXIT EDITING MENU.");
	getch();
}

void deleterecord()
{
	system("cls");
	struct Record U;
	char filename[15], another = 'Y', id[16];
	char pword[10];
	char c = ' ';
	int choice, check;
	int j = 0;
	int i = 0;
	//char pass[8];

	printf("\n\n\t\t====================================\n");
	printf("\t\t\t- DELETE RECORDS -");
	printf("\n\t\t====================================\n\n");

	printf("\nENTER PASSWORD\n");
	/*int i;
	scanf("%s", pass);*/

	while (i < 10)
	{
		pword[i] = getch();
		c = pword[i];
		if (c == 13) break;
		else printf("*");
		i++;
	}
	pword[i] = '\0';

	if (strcmpi(pword, "pass") == 0)
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
			printf("\n %c ID = %s                       ", 179, record.id);
			//printf("\n %c Convict's name: %s            %c", 179, record.name);
			printf("\n %c Convict's name: %s            ", 179, record.name);
			printf("\n %c Convict's gender: %s          ", 179, record.gender);
			printf("\n %c Convict's date of birth: %d/%d/%d:  ", 179, record.dob.year, record.dob.month, record.dob.day);
			printf("\n %c Convict's weight: %s          ", 179, record.weight);
			printf("\n %c Convict's height: %s          ", 179, record.height);
			printf("\n %c Convict's haircolor: %s       ", 179, record.hair);
			printf("\n %c Convict's eyecolor: %s        ", 179, record.eye);
			printf("\n %c Convict's crime: %s           ", 179, record.crime);
			printf("\n %c Address of police station: %s ", 179, record.address);
			getch();
		}
		fclose(fp);
		getch();
}
