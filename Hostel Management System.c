/*
	User:GUEST
	Password:GUEST
	
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct Student{
	char name[30], id[20], Father_name[30], Mother_name[30], city[20], state[20], college[10], Payment[5], phone[11], Father_phone[11], Mother_phone[11];
	int roomno, sharing;
};

struct Room{
	int roomno, sharing;
	char student1[20], student2[20], student3[20], student4[20];
};

struct visitor_detail{
	char visitor[20], relation[20], in_time[6], out_time[6];
};

void line_design(int);
void login_check(char [], char []);
void enter_password(char []);
void studentMenu();
void wardenMenu();
void line_design();
void Header_design();
void Header_design1();
void studentStatus();
void messDetails();
void roomDetails();
void visitorDetails();
void addVisitorDetails();
void viewVisitorDetails();
void feeStatus();
void logout();
void roomStatusView();
void messDetailsView();
void noticeboard();
void registerComplain();
void viewStudent();
void addStudent();
void updateStudent();
void searchStudent();
void viewRoom();
void updateRoom();
void searchRoom();
void gotoStudentMenu();
void gotoWardenMenu();

int main()
{
	char id[20], password[15];
	
	system("color F5");
	
	printf("\n\n");
	printf("\t\t");
	line_design(75);
	
	printf("\n\n\n");
	printf("\t\t\t\t\t\b\b %c HOSTEL MANAGEMENT SYSTEM %c \n\n\n", 17, 16);
	printf("\t\t\t\t\t\t\b %c LOGIN %c ", 17, 16);
	
	printf("\n\n\n\t\t\t\t\b\b %c  Enter User ID : ", 254);
	scanf("%s", &id);
	printf("\n\n\t\t\t\t\b\b %c  Enter Password : ", 254);
	enter_password(password);
	
	login_check(id, password);
	
	return 0;
}

void login_check(char id[20], char password[15]){
	FILE *fpLogin;
	char *fid, *fpassword;
	char user[35] = "";
	int check = 0;
	int choice;
	
	fpLogin = fopen("login.dat", "r");
	
	if (fpLogin == NULL)
	{
		printf("File Read Error...");
		exit(0);
	}
	
	while (fgets(user, 35, fpLogin) != NULL)
	{
		fid = strtok(user, ",");
		fpassword = strtok(NULL , ";");
		
		if (strcmp(id, fid) == 0)
		{
			if (strcmp(password, fpassword) == 0)
				check = 1;
			else 
				check = 2;
				
			break;
		}
	}
	
	if (check == 1)
	{
		int choice;
		
		printf("\n\n\n\t\t\t\t\t\t\b\b\b\bLogin Successfull...");
		printf("\n\n\n\t\t");
		line_design(75);
		printf("\n\n\n\t\t\t\t1. Student\n\t\t\t\t2. Warden\n\n\t\t\t\t\b\bEnter which user you want to access: ");
		scanf("%d", &choice);
		
		if (choice == 1)
		{
			system("cls");
			studentMenu();
		}
		
		else if(choice == 2)
		{
			system("cls");
			wardenMenu();
		}
		else
		{
			while (choice != 1 && choice != 2)
			{
				printf("\n\t\t\t\t\b\bPlease enter correct choice: ");
				scanf("%d", &choice);
				if (choice == 1)
				{
					system("cls");
					studentMenu();	
				}	
				if (choice == 2)
				{
					system("cls");
					wardenMenu();	
				}
			}
		}
	}
	else if (check == 0)
	{
		printf("\n\n\n\t\t\t\t\t\t\b\bLogin Failed...");
		printf("\n\n\t\t\t\t\t  User ID doesn't exists");
		Sleep(2000);
	}
	
	else 
	{
		printf("\n\n\t\t\t\t\tIncorrect Password...");
		Sleep(2000);
	}
}

void enter_password(char password[15])
{
	int i = 0;
	char chr;
	chr = getch();
	while (chr != 13)
	{
		if (chr == 8)
		{
			if (i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		
		else if (chr == 9 || chr == 32)
		{
			continue;
		}
		
		else
		{
			password[i]=chr;
			i++;
			printf("*");
		}
		chr = getch();
	}
	password[i] = '\0';
}

void studentMenu(void)
{
	int Choice;
	
	system("color F1");
	
	printf("\n");
	
	line_design(85);
	
	printf("\n\n\t\t\t\t\t");
	Header_design(19);
	printf("\n\t\t\t\t\tSTUDENT'S MAIN MENU");
	printf("\n\t\t\t\t\t");
	Header_design1(19);
	printf("\n\n\t\t %c  1. Room Status\n\n", 254);
	printf("\t\t %c  2. Mess Status\n\n", 254);
	printf("\t\t %c  3. Register Complain\n\n", 254);
	printf("\t\t %c  4. Notice Board\n\n", 254);
	printf("\t\t %c  5. Logout\n\n", 254);
	
	line_design(85);
	
	printf("\n\n\t\tEnter your choice: ");
	scanf("%d", &Choice);
	
	switch(Choice){
		case 1: viewRoom();
				gotoStudentMenu();
				break;
		case 2: messDetails();
				gotoStudentMenu();
				break;
		case 3: registerComplain();
				break;
		case 4: noticeboard();
				break;
		case 5: logout();
				break;	
		default: printf("\n\n\t\tTry Again...");
				 Sleep(1000);
				 system("cls");
				 studentMenu();
				 break;
	}
}

void wardenMenu()
{
	int Choice;
	
	system("color F1");
	
	printf("\n");
	
	line_design(85);
	
	printf("\n\n\t\t\t\t\t");
	Header_design(18);
	printf("\n\t\t\t\t\tWARDEN'S MAIN MENU");
	printf("\n\t\t\t\t\t");
	Header_design1(18);
	printf("\n\n\t\t %c  1. Student Status\n\n", 254);
	printf("\t\t %c  2. Mess Details\n\n", 254);
	printf("\t\t %c  3. Room Details\n\n", 254);
	printf("\t\t %c  4. Visitor Details\n\n", 254);
	printf("\t\t %c  5. Fee Status\n\n", 254);
	printf("\t\t %c  6. Logout\n\n", 254);
	
	line_design(85);
	
	printf("\n\n\t\tEnter your choice: ");
	scanf("%d", &Choice);
	
		switch(Choice){
		case 1: studentStatus();
				break;
		case 2: messDetails();
				gotoWardenMenu();
				break;
		case 3: roomDetails();
				break;
		case 4: visitorDetails();
				break;
		case 5: feeStatus();
				break;
		case 6: logout();
				break;	
		default: printf("\n\n\t\tTry Again... ");
				 Sleep(1000);
				 system("cls");
				 wardenMenu();
				 break;
	}	
}

void studentStatus(){
	int Choice;
	
	system("cls");
	system("color F1");
	
	printf("\n\t");
	line_design(85);
	
	printf("\n\n\t\t\t\t\tSTUDENT STATUS \n\n\n");
	printf("\t\t\t %c 1. View Student Details\n\n", 254);
	printf("\t\t\t %c 2. Add Student Details\n\n", 254);
	printf("\t\t\t %c 3. Update Student Details\n\n", 254);
	printf("\t\t\t %c 4. Search Student Details\n\n", 254);
	
	printf("\n\t");
	line_design(85);
	
	printf("\n\n\t\t\tEnter choice no.: ");
	scanf("%d", &Choice);

	switch(Choice){
		case 1: viewStudent();
				gotoWardenMenu();
				break;
		case 2: addStudent();
				break;
		case 3: updateStudent();
				break;
		case 4: searchStudent();
				break;
		default: printf("\n\n\t\t\t\t\tTry Again...");
				 Sleep(1000);
				 studentStatus();
				 break;
	
	}
}

void viewStudent(){
	system("cls");
	system("color F1");
	
	printf("\n");
	line_design(85);
	printf("\n\n\t\t\t\t\t\b\bSTUDENT DETAILS");
	
	struct Student s;
	FILE *fpStudent;
	fpStudent = fopen ("Student.dat", "r");
	
	if (fpStudent == NULL)
	{
		printf("File read error...");
		exit(1);
	}
	
	while (fscanf(fpStudent, "%s %s %s %s %s %s %s %s %s %s %d %d %s\n", &s.name, &s.id, &s.Father_name, &s.Mother_name, &s.city, &s.state, &s.phone, &s.Father_phone, &s.Mother_phone, &s.college, &s.roomno, &s.sharing, &s.Payment)!=EOF)
	{
		printf("\n\n\t\tName               : %s\n", s.name);
		printf("\t\tID                 : %s\n", s.id);
		printf("\t\tFather's Name      : %s\n", s.Father_name);
		printf("\t\tMother's Name      : %s\n", s.Mother_name);
		printf("\t\tCity               : %s\n", s.city);
		printf("\t\tState              : %s\n", s.state);
		printf("\t\tStudent's Phone No.: %s\n", s.phone);
		printf("\t\tFather's Phone No. : %s\n", s.Father_phone);
		printf("\t\tMother's Phone No. : %s\n", s.Mother_phone);
		printf("\t\tCollege            : %s\n", s.college);	
		printf("\t\tRoom No            : %d\n", s.roomno);
		printf("\t\tNo. of sharing     : %d\n", s.sharing);
		printf("\t\tFee payment status : %s\n", s.Payment);
		printf("\n\n\t\t=====================================\n\n");
	}
	fclose(fpStudent);
	
	printf("\n");
	line_design(85);
}

void addStudent(){
	system("cls");
	system("color F1");
	
	printf("\n");
	line_design(85);
	
	printf("\n\n\t\t\t\t\t\b\bADD STUDENT DETAILS");
	
	struct Student add;
	FILE *fpStudent;
	fpStudent = fopen ("Student.dat", "a");
	
	if (fpStudent == NULL)
	{
		printf("File read error...");
		exit(1);
	}
	
	printf("\n\n\t\tEnter Name: ");
	scanf("%s", add.name);
	printf("\t\tEnter ID: ");
	scanf("%s", add.id);
	printf("\t\tEnter Father's Name: ");
	scanf("%s", add.Father_name);
	printf("\t\tEnter Mother's Name: ");
	scanf("%s", add.Mother_name);
	printf("\t\tEnter City: ");
	scanf("%s", add.city);
	printf("\t\tEnter State: ");
	scanf("%s", add.state);
	printf("\t\tEnter Student's Phone: ");
	scanf("%s", add.phone);
	printf("\t\tEnter Father's Phone: ");
	scanf("%s", add.Father_phone);
	printf("\t\tEnter Mother's Phone: ");
	scanf("%s", add.Mother_phone);
	printf("\t\tEnter name of College: ");
	scanf("%s", add.college);	
	printf("\t\tEnter Room No: ");
	scanf("%d", &add.roomno);
	printf("\t\tEnter No. of sharing: ");
	scanf("%d", &add.sharing);
	printf("\t\tEnter Fee payment status: ");
	scanf("%s", add.Payment);
	
	fprintf(fpStudent, "%s %s %s %s %s %s %s %s %s %s %d %d %s\n", add.name, add.id, add.Father_name, add.Mother_name, add.city, add.state, add.phone, add.Father_phone, add.Mother_phone, add.college, add.roomno, add.sharing, add.Payment);
	
	printf("\n\n\t\tStudent details added successfully into student data file...");

	fclose(fpStudent);
	
	printf("\n");
	line_design(85);
	
	gotoWardenMenu();
}

void updateStudent(){
	system("cls");
	system("color F1");
	
	printf("\n");
	line_design(85);
	
	printf("\n\n\t\t\t\t\t\b\b\bUPDATE STUDENT DETAILS");
	
	struct Student Old, New;
	int check=0, choice; 
	FILE *fpStudent, *fpStudentNew;
	fpStudent = fopen("Student.dat", "r");
	fpStudentNew = fopen("StudentNew.dat", "w");
	
	if (fpStudent == NULL)
	{
		printf("File Read Error...");
		exit(1);
	}
	
	printf("\n\n\t\tEnter Student's ID which you want to change: ");
	scanf("%s", &New.id);
	
	while (fscanf(fpStudent, "%s %s %s %s %s %s %s %s %s %s %d %d %s\n", &Old.name, &Old.id, &Old.Father_name, &Old.Mother_name, &Old.city, &Old.state, &Old.phone, &Old.Father_phone, &Old.Mother_phone, &Old.college, &Old.roomno, &Old.sharing, &Old.Payment)!=EOF)
	{
		if (strcmp(New.id, Old.id) == 0)
		{
			check = 1;
			printf("\n\t\t1. Room No\n\t\t2. Fee payment Status\n\t\t3. Student's phone no.\n");
			printf("\n\n\t\tEnter choice no. of the details you want to change: ");
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("\n\t\tEnter New Room No.: ");
				scanf("%d", &New.roomno);
				printf("\t\tEnter no. of sharing: ");
				scanf("%d", &New.sharing);
				
				fprintf(fpStudentNew, "%s %s %s %s %s %s %s %s %s %s %d %d %s\n", Old.name, Old.id, Old.Father_name, Old.Mother_name, Old.city, Old.state, Old.phone, Old.Father_phone, Old.Mother_phone, Old.college, New.roomno, New.sharing, Old.Payment);
				printf("\n\t\tData updated succesfully into Student Data File");			
			}
			else if(choice == 2)
			{
				printf("\t\tEnter Fee Payment Status: ");
				scanf("%s", New.Payment);
				
				fprintf(fpStudentNew, "%s %s %s %s %s %s %s %s %s %s %d %d %s\n", Old.name, Old.id, Old.Father_name, Old.Mother_name, Old.city, Old.state, Old.phone, Old.Father_phone, Old.Mother_phone, Old.college, Old.roomno, Old.sharing, New.Payment);
				printf("\n\t\tData updated succesfully into Student Data File");
			}
			else if(choice == 3)
			{
				printf("\t\tEnter new phone no. of Student: ");
				scanf("%s", &New.phone);
				
				fprintf(fpStudentNew, "%s %s %s %s %s %s %s %s %s %s %d %d %s\n", Old.name, Old.id, Old.Father_name, Old.Mother_name, Old.city, Old.state, New.phone, Old.Father_phone, Old.Mother_phone, Old.college, Old.roomno, Old.sharing, Old.Payment);
				printf("\n\t\tData updated succesfully into Student Data File");
			}
			else
			{
				printf("\t\tYou have entered wrong choice: ");
			}
			
		}
		else 
		{
			fprintf(fpStudentNew, "%s %s %s %s %s %s %s %s %s %s %d %d %s\n", Old.name, Old.id, Old.Father_name, Old.Mother_name, Old.city, Old.state, Old.phone, Old.Father_phone, Old.Mother_phone, Old.college, Old.roomno, Old.sharing, Old.Payment);	
		}
	}
	
	fclose(fpStudent);
	fclose(fpStudentNew);
	remove("Student.dat");
	rename("StudentNew.dat", "Student.dat");
	
	if (check == 0)
	{
		printf("\n\t\tStudent ID not found...");
	}
	
	printf("\n\n");
	line_design(85);
	
	gotoWardenMenu();
}

void searchStudent(){
	system("cls");
	system("color F1");
	
	printf("\n");
	line_design(85);
	
	printf("\n\n\t\t\t\t\t\b\b\bSEARCH STUDENT DETAILS");
	
	struct Student search;
	char id[20];
	int check = 0;
	FILE *fpSearch;
	fpSearch = fopen("Student.dat", "r");
	
	if (fpSearch == NULL)
	{
		printf("File read error...");
		exit(1);
	}
	
	printf("\n\n\t\tEnter Student ID which you want to search: ");
	scanf("%s", id);
	
	while (fscanf(fpSearch, "%s %s %s %s %s %s %s %s %s %s %d %d %s\n", &search.name, &search.id, &search.Father_name, &search.Mother_name, &search.city, &search.state, &search.phone, &search.Father_phone, &search.Mother_phone, &search.college, &search.roomno, &search.sharing, &search.Payment)!=EOF)
	{
		if (strcmp(id, search.id) == 0)
		{
			check = 1;
			
			printf("\n\n\t\tName              : %s\n", search.name);
			printf("\t\tID                : %s\n", search.id);
			printf("\t\tFather's Name     : %s\n", search.Father_name);
			printf("\t\tMother's Name     : %s\n", search.Mother_name);
			printf("\t\tCity              : %s\n", search.city);
			printf("\t\tState             : %s\n", search.state);
			printf("\t\tStudent's Phone   : %s\n", search.phone);
			printf("\t\tFather's Phone    : %s\n", search.Father_phone);
			printf("\t\tMother's Phone    : %s\n", search.Mother_phone);
			printf("\t\tCollege           : %s\n", search.college);	
			printf("\t\tRoom No           : %d\n", search.roomno);
			printf("\t\tNo. of sharing    : %d\n", search.sharing);
			printf("\t\tFee payment status: %s\n", search.Payment);
		}	
	}
	
	if (check == 0)
	{
		printf("\n\t\tStudent ID not found...\n");
	}
	
	fclose(fpSearch);
	
	printf("\n");
	line_design(85);
	
	gotoWardenMenu();
}

void messDetails(){
	system("cls");
	system("color F1");
		
	printf("\n\n");
	line_design(120);
	printf("\n\n\t\t\t\t\t\t\tMESS DETAILS\n\n");

	FILE *fp;
	char ch;
	fp = fopen("MessTiming.dat","r");
	while(ch != EOF){
		ch = fgetc(fp);
		printf("%c",ch);
	}
	printf("\n\n");
	line_design(120);
	printf("\n\n");
}

void roomDetails(){
	int Choice;
	
	system("cls");
	system("color F1");
	
	printf("\n\t");
	line_design(85);
	
	printf("\n\n\t\t\t\t\tROOM DETAILS \n\n\n");
	printf("\t\t\t %c 1. View Room Details\n\n", 254);
	printf("\t\t\t %c 2. Update Room Details\n\n", 254);
	printf("\t\t\t %c 3. Search Room Details\n\n", 254);
	
	printf("\n\t");
	line_design(85);
	
	printf("\n\n\t\t\tEnter choice no.: ");
	scanf("%d", &Choice);
	
	switch(Choice){
		case 1: viewRoom();
				gotoWardenMenu();
				break;
		case 2: updateRoom();
				break;
		case 3: searchRoom();
				break;
		default: printf("\n\n\t\t\t\t\tTry Again...");
				 Sleep(1000);
				 roomDetails();
				 break;
	}
}

void viewRoom(){
	system("cls");
	system("color F1");
	
	printf("\n\n");
	line_design(100);
	printf("\n\n\t\t\t\t\t\t\b\bROOM DETAILS");
	
	struct Room r;
	FILE *fpRoom;
	fpRoom = fopen("RoomStatus.dat", "r");
	
	if (fpRoom == NULL)
	{
		printf("File Read Error...");
		exit(1);
	}
	
	while(fscanf(fpRoom, "%d %d %s %s %s %s", &r.roomno, &r.sharing, &r.student1, &r.student2, &r.student3, &r.student4)!=EOF)
	{
		if (r.sharing==4)
		{
			if (strcmp(r.student1,"null") != 0)
			{
				printf("\n\n\t\tRoom No : %d", r.roomno);
				printf("\n\t\tNo. of sharing : %d", r.sharing);
				printf("\n\t\tStudent 1: %s", r.student1);
				printf("\n\t\tStudent 2: %s", r.student2);
				printf("\n\t\tStudent 3: %s", r.student3);
				printf("\n\t\tStudent 4: %s", r.student4);
				printf("\n\n\t\t========================================");
			}
		}
		else if(r.sharing==3)
		{
			if (strcmp(r.student1, "null") != 0)
			{
				printf("\n\n\t\tRoom No : %d", r.roomno);
				printf("\n\t\tNo. of sharing : %d", r.sharing);
				printf("\n\t\tStudent 1: %s", r.student1);
				printf("\n\t\tStudent 2: %s", r.student2);
				printf("\n\t\tStudent 3: %s", r.student3);
				printf("\n\n\t\t========================================");	
			}
		}
	}
	fclose(fpRoom);
	
	printf("\n\n");
	line_design(100);
}

void updateRoom(){
	system("cls");
	system("color F1");
	
	printf("\n");
	line_design(100);
	
	printf("\n\n\t\t\t\t\t\t\b\bUPDATE ROOM DETAILS");
	
	struct Room r1, r2;
	FILE *fpRoom, *fpRoomNew;
	int check=0;
	fpRoom = fopen("RoomStatus.dat", "r");
	fpRoomNew = fopen("RoomStatusNew.dat", "w");
	if (fpRoom == NULL)
	{
		printf("File Read Error...");
		exit(1);	
	}	
	printf("\n\n\t\tEnter room no. whose details you want to change : ");
	scanf("%d", &r2.roomno);
	
	while(fscanf(fpRoom, "%d %d %s %s %s %s", &r1.roomno, &r1.sharing, &r1.student1, &r1.student2, &r1.student3, &r1.student4)!=EOF)
	{
		if (r2.roomno == r1.roomno)
		{
			check=1;
			if (r1.sharing==4)
			{
				printf("\n\t\tEnter student 1 : ");
				scanf("%s", &r2.student1);
				printf("\n\t\tEnter student 2 : ");
				scanf("%s", &r2.student2);
				printf("\n\t\tEnter student 3 : ");
				scanf("%s", &r2.student3);
				printf("\n\t\tEnter student 4 : ");
				scanf("%s", &r2.student4);
			}
			else
			{
				printf("\n\t\tEnter student 1 : ");
				scanf("%s", &r2.student1);
				printf("\n\t\tEnter student 2 : ");
				scanf("%s", &r2.student2);
				printf("\n\t\tEnter student 3 : ");
				scanf("%s", &r2.student3);
				strcpy(r2.student4, "null");
			}
			
			fprintf(fpRoomNew, "%d %d %s %s %s %s\n", r1.roomno, r1.sharing, r2.student1, r2.student2, r2.student3, r2.student4);
		}
		else
		{
			fprintf(fpRoomNew, "%d %d %s %s %s %s\n", r1.roomno, r1.sharing, r1.student1, r1.student2, r1.student3, r1.student4);
		}
	}
	fclose(fpRoom);
	fclose(fpRoomNew);
	remove("RoomStatus.dat");
	rename("RoomStatusNew.dat","Roomstatus.dat");
	
	if (check == 0)
	{
		printf("\t\tRoom No. not found...");
	}
	
	printf("\n");
	line_design(100);
		
	gotoWardenMenu();
}

void searchRoom(){
	system("cls");
	system("color F1");
	
	printf("\n");
	line_design(100);
	
	printf("\n\n\t\t\t\t\t\t\b\bSEARCH ROOM DETAILS");
	
	struct Room Search;
	int roomno, check=0;
	FILE *fpRoomSearch;
	fpRoomSearch = fopen("RoomStatus.dat", "r");
	
	if (fpRoomSearch == NULL)
	{
		printf("File Read Error...");
		exit(1);
	}
	
	printf("\n\n\t\tEnter Room no which you want to search: ");
	scanf("%d", &roomno);
	
	while(fscanf(fpRoomSearch, "%d %d %s %s %s %s", &Search.roomno, &Search.sharing, &Search.student1, &Search.student2, &Search.student3, &Search.student4)!=EOF)
	{
		if (Search.roomno == roomno)
		{
			check = 1;
			if (Search.sharing==4)
			{
				if (strcmp(Search.student1,"null") != 0)
				{
					printf("\n\n\t\tRoom No : %d", Search.roomno);
					printf("\n\t\tNo. of sharing : %d", Search.sharing);
					printf("\n\t\tStudent 1: %s", Search.student1);
					printf("\n\t\tStudent 2: %s", Search.student2);
					printf("\n\t\tStudent 3: %s", Search.student3);
					printf("\n\t\tStudent 4: %s", Search.student4);
				}
				else
				{
					printf("\n\n\t\tRoom is Unoccupied...\n");
				}
			}
			else if(Search.sharing==3)
			{
				if (strcmp(Search.student1, "null") != 0)
				{
					printf("\n\n\t\tRoom No : %d", Search.roomno);
					printf("\n\t\tNo. of sharing : %d", Search.sharing);
					printf("\n\t\tStudent 1: %s", Search.student1);
					printf("\n\t\tStudent 2: %s", Search.student2);
					printf("\n\t\tStudent 3: %s\n", Search.student3);	
				}
				else
				{
					printf("\n\t\tRoom is Unoccupied...\n");
				}
			}
			break;
		}
	}

	if (check == 0)
	{
		printf("\n\n\t\tRoom No not found...\n");
	}	
	
	fclose(fpRoomSearch);
	
	printf("\n");
	line_design(100);
	
	gotoWardenMenu();
}

void visitorDetails(){
	int Choice;
	
	system("cls");
	system("color F1");
	
	printf("\n\t");
	line_design(85);
	
	printf("\n\n\t\t\t\t\tVISITOR DETAILS \n\n\n");
	printf("\t\t\t %c 1. View Visitor Details\n\n", 254);
	printf("\t\t\t %c 2. Add Visitor Details\n\n", 254);
	
	printf("\n\t");
	line_design(85);
	
	printf("\n\n\t\t\tEnter choice no.: ");
	scanf("%d", &Choice);

	switch(Choice)
	{
		case 1: viewVisitorDetails();
				break;
		case 2: addVisitorDetails();
				break;
		default: printf("\n\n\t\t\t\t\tTry Again...");
				 Sleep(1000);
				 visitorDetails();
				 break;
	}	
}

void addVisitorDetails(){
	system("cls");
	system("color F1");
	
	printf("\n");
	line_design(100);
	
	printf("\n\n\t\t\t\t\t\t\b\bADD VISITOR DETAILS");
	
	FILE *fpAddVisitor;
	struct visitor_detail a;
	fpAddVisitor = fopen("VisitorDetails.dat", "a");
	
	if (fpAddVisitor == NULL)
	{
		printf("File Error Occurred...");
		exit(1);
	}
	
	fflush(stdin);
	printf("\n\n\t\tEnter Visitor Name : ");
	gets(a.visitor);
	printf("\t\tEnter Incoming time of the Visitor in hh:mm format : ");
	scanf("%s", a.in_time);
	printf("\t\tEnter Outgoing time of the Visitor in hh:mm format : ");
	scanf("%s", a.out_time);
	printf("\t\tEnter Relation with the Student : ");
	scanf("%s", a.relation);
	fprintf(fpAddVisitor, "\n%s %s %s %s", a.visitor, a.in_time, a.out_time, a.relation);
	
	printf("\n\n\t\tData saved succesfully into the Visitor Data File...\n");
	
	fclose(fpAddVisitor);
	
	printf("\n");
	line_design(100);
	
	gotoWardenMenu();
}

void viewVisitorDetails(){
	system("cls");
	system("color F1");
	
	printf("\n");
	line_design(100);
	printf("\n\n\t\t\t\t\t\t\b\bVISITOR DETAILS");
	FILE *fpVisitor;
	struct visitor_detail v;
	fpVisitor = fopen("VisitorDetails.dat", "r");
	
	if (fpVisitor == NULL)
	{
		printf("File Error Occurred...");
		exit(1);
	}
	
	while(fscanf(fpVisitor, "%s %s %s %s", &v.visitor, &v.in_time, &v.out_time, &v.relation) != EOF)
	{
		printf("\n\n\n\t\tVisitor Name : %s", v.visitor);
		printf("\n\n\t\tIncoming Time : %s", v.in_time);
		printf("\n\n\t\tOutgoing Time : %s", v.out_time);
		printf("\n\n\t\tRelation with the Student : %s", v.relation);
		printf("\n\n\t\t=========================================");
	}
	
	printf("\n\n");
	line_design(100);
	
	gotoWardenMenu();
}

void feeStatus(){
	system("cls");
	system("color F1");
	
	printf("\n\n");
	line_design(85);
	
	char due[500] = "\n\n\n\t\tStudents whose fees are due for this month:\n\n";
	int paid_3=0, paid_4=0, due_3=0, due_4=0;
	struct Student fee;
	FILE *fpStudent;
	fpStudent = fopen ("Student.dat", "r");
	
	if (fpStudent == NULL)
	{
		printf("File read error...");
		exit(1);
	}
	
	while (fscanf(fpStudent, "%s %s %s %s %s %s %ld %ld %ld %s %d %d %s\n", &fee.name, &fee.id, &fee.Father_name, &fee.Mother_name, &fee.city, &fee.state, &fee.phone, &fee.Father_phone, &fee.Mother_phone, &fee.college, &fee.roomno, &fee.sharing, &fee.Payment)!=EOF)
	{
		if (strcmp(fee.Payment, "Paid") == 0)
		{
			if (fee.sharing == 4)
				++paid_4;
			else
				++paid_3;
		}
		else if(strcmp(fee.Payment, "Due") == 0)
		{
			char Due[20];
			if (fee.sharing == 4)
			{
				++due_4;
				strcat(due, "\t\t");
				strcat(due, fee.name);
				strcat(due, "\n");
			}	
			else
			{
				++due_3;
				strcat(due, "\t\t");
				strcat(due, fee.name);
				strcat(due, "\n");	
			}
		}
	}
	
	printf("\n\n\t\t\t\t\t\b\bFEE PAYMENT STATUS  ");
	printf("\n\n\t\tTotal fees paid for this month = %ld", (paid_4*11500 + paid_3*12500));
	printf("\n\t\tTotal fees due for this month = %ld", (due_4*11500 + due_3*12500));
	printf("%s", due);
	
	fclose(fpStudent);
	
	printf("\n\n");
	line_design(85);
	
	gotoWardenMenu();
}

void noticeboard(){
	system("cls");
	printf("\n\n");
	line_design(80);
	printf("\n\n");
	
	FILE *fp;
	char ch;
	fp = fopen("NoticeBoard.dat","r");
	while(ch != EOF){
		ch = fgetc(fp);
		printf("%c",ch);
	}
	printf("\n\n");
	line_design(80);
	
	gotoStudentMenu();
}

void registerComplain(){
	char complain[500];
	FILE *fpComplain;
	
	fpComplain = fopen ("RegisterComplain.dat", "a");
	if (fpComplain == NULL)
	{
		printf("File Error occurred...");
		exit(1);
	}
	
	system("cls");
	
	printf("\n\n");
	line_design(80);
	
	printf("\n\n\t\t\t\t\t\bCOMPLAIN BOX");
	
	printf("\n\n\t\tEnter you complain : ");
	fflush(stdin);
	gets(complain);
	fprintf(fpComplain, "%s\n", complain);
	printf("\n\n\t\t\tComplain saved succesfully....");
	
	fclose(fpComplain);
	
	printf("\n\n");
	line_design(80);
	
	gotoStudentMenu();
}

void gotoStudentMenu(){
	int select;
	
	printf("\n\n\t\t\tEnter 1 to return to Main Menu");
	printf("\n\t\t\tEnter 0 to logout");
	printf("\n\n\t\t\tEnter your choice here: ");
	
	while (select != 0 || select != 1)
	{
		scanf("%d", &select);
		if (select == 1)
		{
			system("cls");
			studentMenu();
			break;	
		}
		else if (select == 0)
		{
			logout();
			break;			
		}
		else
			printf("\n\n\t\t\tPlease enter correct choice: ");
	}
}

void gotoWardenMenu(){
	int select;
	
	printf("\n\n\t\t\tEnter 1 to return to Main Menu");
	printf("\n\t\t\tEnter 0 to logout");
	printf("\n\n\t\t\tEnter your choice here: ");
	
	while (select != 0 || select != 1)
	{
		scanf("%d", &select);
		if (select == 1)
		{
			system("cls");
			wardenMenu();
			break;
		}

		else if (select == 0)
		{
			logout();
			break;
		}
		else
			printf("\n\n\t\t\tPlease enter correct choice: ");
	}	
}

void logout(){
	system("cls");
	system("color F1");
	printf("\n\n");
	line_design(110);
	printf("\n\n\t\t\t\t\t\tTHANK YOU");
	printf("\n\n\t\t\t\t\t\t\b\b\bHave a Nice Day");
	printf("\n\n");
	line_design(110);
}

void line_design(int j){
	int i;
	for(i=1; i<=j; i++){
	if (i>=10){
		printf("%c",219);
	}
	else{
		printf("%c", 32);
	}
	}	
}
void Header_design(int j){
	int i;
	for(i=1; i<=j; i++){
		printf("%c",223);  
	}
}
void Header_design1(int j){
	int i;
	for(i=1; i<=j; i++){
		printf("%c",220);  
	}
}