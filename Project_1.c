#include <windows.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// basic structure of saving information of a book
struct library
{

    char book_name[20];

    char author[20];

    int pages;

    float price;
};
// basic structure of  saving information of a student
struct StudentInfo
{
    char ID[10];
    char Name[20];
    char Email[30];
    char Phone[20];
    int NumberOfCourse;
};
// basic structure of input as course
struct CourseInfo
{
    char StudentID[10];
    char Code[10];
    char Name[20];
};

struct StudentInfo Students[100];
struct CourseInfo Courses[500];

// some global variables
int i, j;
int TotalStudents = 0;
int TotalCourse = 0;
char StudentID[10];
// end

bool IsRunning = true;
// function for creating the menu
void Menu();
// function for adding the information  of a student
void AddNewStudent();
// function to show information of all the students
void ShowAllStudents();
int SearchStudent(char StudentID[10]);
// to edit student data
void EditStudent(int StudentFoundIndex);
// to delete student data
void DeleteStudent(int StudentIndex);
// delete all student data
void DeleteAllStudents();
int IsAlreadyExists(char GivenLine[30], char InfoType, char StudentID[300]);
// delete course of student
void DeleteCourseByIndex(int CourseIndex);
void DeleteStudentByIndex(int CourseIndex);
void UserGuideline();
void AboutUs();
void GoBackOrExit();
void ExitProject();
void DataSeed();
// end
int main()
{
    while (1)
    {
        int choice;
        system("cls");
        // Display menu
        printf("Choose an option:\n");
        printf("1. Student management system\n");
        printf("2. Library management system\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);

        // Switch-case statement to handle choice
        switch (choice)
        {
        case 1:
            system("cls");
            printf("You chose Student management system.\n");
            DataSeed(); // you can comment this line if not want dummy data

            {
                while (IsRunning)
                {
                    Menu();
                    int Option;
                    scanf("%d", &Option);
                    if (Option == -1)
                    {
                        break;
                    }
                    switch (Option)
                    {
                    case 0:
                        IsRunning = false;
                        ExitProject();
                        break;
                    case 1:
                        system("cls");
                        printf("\n\t\t * Add A New Student *\n\n");
                        AddNewStudent();
                        GoBackOrExit();
                        break;
                    case 2:
                        system("cls");
                        printf("\n\t\t * All Students *\n\n");
                        ShowAllStudents();
                        GoBackOrExit();
                        break;
                    case 3:
                    {
                        system("cls");
                        printf("\n\t\t * Search Students *\n\n");
                        printf(" Enter The Student ID: ");
                        scanf("%s", StudentID);
                        int IsFound = SearchStudent(StudentID);
                        if (IsFound < 0)
                        {
                            printf(" No Student Found\n\n");
                        }
                        printf("\n");
                        GoBackOrExit();
                        break;
                    }
                    case 4:
                        system("cls");
                        printf("\n\t\t * Edit a Student *\n\n");
                        printf(" Enter The Student ID: ");
                        scanf("%s", StudentID);
                        int StudentFoundIndex = SearchStudent(StudentID);

                        if (StudentFoundIndex >= 0)
                        {
                            EditStudent(StudentFoundIndex);
                        }
                        else
                        {
                            printf(" No Student Found\n\n");
                        }
                        GoBackOrExit();
                        break;
                    case 5:
                        system("cls");
                        printf("\n\t\t * Delete a Student *\n\n");
                        printf(" Enter The Student ID: ");
                        scanf("%s", StudentID);

                        int DeleteStudentFoundIndex = SearchStudent(StudentID);

                        if (DeleteStudentFoundIndex >= 0)
                        {
                            char Sure = 'N';
                            getchar();
                            printf("\n\n");
                            printf(" Are you sure want to delete this student? (Y/N): ");
                            scanf("%c", &Sure);

                            if (Sure == 'Y' || Sure == 'y')
                            {
                                DeleteStudent(DeleteStudentFoundIndex);
                            }
                            else
                            {
                                printf(" Your Data is Safe.\n\n");
                                GoBackOrExit();
                            }
                        }
                        else
                        {
                            printf(" No Student Found\n\n");
                            GoBackOrExit();
                        }

                        break;
                    case 6:
                    {
                        char Sure = 'N';
                        getchar();
                        system("cls");
                        printf("\n\t\t * Delete ALL Students *\n\n");

                        printf(" Are you sure want to delete all the students? (Y/N): ");
                        scanf("%c", &Sure);
                        if (Sure == 'Y' || Sure == 'y')
                        {
                            DeleteAllStudents();
                        }
                        else
                        {
                            printf(" Your Data is Safe.\n\n");
                            GoBackOrExit();
                        }
                        break;
                    }

                    case 7:
                        system("cls");
                        break;
                    case 8:
                        system("cls");
                        UserGuideline();
                        GoBackOrExit();
                        break;
                    case 9:
                        system("cls");
                        AboutUs();
                        GoBackOrExit();
                        break;
                    default:
                        ExitProject();
                        break;
                    }
                }
                break;
            case 2:
                system("cls");
                printf("You chose Option 2.\n");
                {
                    struct library lib[100];
                    // ar_nm contains authors name for comparision
                    // bk_nm contains books name for comparision
                    char ar_nm[30], bk_nm[30];

                    // Keep the track of the number of

                    // of books available in the library

                    int i, input, count;

                    i = input = count = 0;

                    // Iterate the loop
                    int po = 0;
                    while (po != 1000)
                    {

                        printf("\n\n**######"

                               "WELCOME TO E-LIBRARY "

                               "#####\n");

                        printf("\n\n1. Add book infor"

                               "mation\n2. Display all the "

                               "book information\n");

                        printf("3. List all books of "

                               "given author\n");
                        printf("4. checks if book is present or not in the database\n");

                        printf(

                            "5. List the count of book"

                            "s in the library\n");

                        printf("6. Go back to main menu");

                        // Enter the book details

                        printf("\n\nEnter one of "

                               "the above: ");

                        scanf("%d", &input);

                        // Process the input

                        if (input == 1)
                        { // Add book

                            printf("Enter book name = ");

                            scanf("%s", lib[count].book_name);

                            printf("Enter author name = ");

                            scanf("%s", lib[count].author);

                            printf("Enter pages = ");

                            scanf("%d", &lib[count].pages);

                            printf("Enter price = ");

                            scanf("%f", &lib[count].price);

                            count++;
                        }

                        else if (input == 2)
                        { // Print book information
                            if (count > 0)
                            {
                                printf("you have entered"

                                       " the following "

                                       "information\n");

                                for (i = 0; i < count; i++)
                                {
                                    printf("\nbook:%d", i + 1);

                                    printf("\nbook name = %s",

                                           lib[i].book_name);

                                    printf("\n author name = %s",

                                           lib[i].author);

                                    printf("\n  pages = %d",

                                           lib[i].pages);

                                    printf("\n  price = %f",

                                           lib[i].price);
                                }
                            }
                            else
                            {
                                printf("There are no books in the library database\n");
                            }
                        }

                        else if (input == 3)

                        { // Take the author name as input
                            printf("Enter author name : ");

                            scanf("%s", ar_nm);
                            int u = 0, kk = 0;
                            for (i = 0; i < count; i++)
                            {

                                if (strcmp(ar_nm, lib[i].author) == 0)

                                {
                                    kk++;
                                    printf("Book %d -\n", kk);
                                    printf("Name of book:%s\n Author:%s\n Number of pages:%d\n Price of the book:%f\n",

                                           lib[i].book_name,

                                           lib[i].author,

                                           lib[i].pages,

                                           lib[i].price);
                                    u = 1;
                                }
                            }
                            if (u == 0)
                            {
                                printf("The entered author has no books in this database\n");
                            }
                        }
                        else if (input == 4)

                        { // Take the book name as input
                            printf("Enter book name : ");

                            scanf("%s", bk_nm);
                            int u = 0, kok = 0;
                            for (i = 0; i < count; i++)
                            {

                                if (strcmp(bk_nm, lib[i].book_name) == 0)

                                {
                                    kok++;
                                    printf("Book %d -\n", kok);
                                    printf("Name of book:%s\n Author:%s\n Number of pages:%d\n Price of the book:%f\n",

                                           lib[i].book_name,

                                           lib[i].author,

                                           lib[i].pages,

                                           lib[i].price);
                                    u = 1;
                                }
                            }
                            if (u == 0)
                            {
                                printf("The entered book is not present in this database\n");
                            }
                        }

                        else if (input == 5)

                        { // Print total count
                            printf("\n No of books in library : %d", count);
                        }

                        else if (input == 6)
                        { // goes back to main menu by breaking out of while loop
                            break;
                        }
                        else
                        {
                            printf("Invalid choice\n");
                        }
                        int lol = 0;
                        while (lol == 0)
                        {
                            printf("\nDo you want to exit(Y/N):");
                            char lanj;
                            scanf(" %c", &lanj);

                            if (lanj == 'y' || lanj == 'Y')
                            {
                                exit(0);
                            }
                            else if (lanj == 'n' || lanj == 'N')
                            {
                                lol = 1;
                            }
                            else
                            {
                                printf("Invalid choice try again\n");
                            }
                        }
                    }
                }
            }
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
// end main function

// this is will display the display menu of  the student management system
void Menu()
{
    printf("\n\n\t**Student Management System Using C\n\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New student.\n");
    printf("\t\t[2] Show All students.\n");
    printf("\t\t[3] Search A student.\n");
    printf("\t\t[4] Edit A student.\n");
    printf("\t\t[5] Delete A student.\n");
    printf("\t\t[6] Delete All students.\n");
    printf("\t\t[7] Clear The window.\n");
    printf("\t\t[8] User Guideline.\n");
    printf("\t\t[9] About Us.\n");
    printf("\t\t[-1] Go back to main menu.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t=======================\n");
    printf("\t\tEnter The Choice: ");
} // end menu

// function for adding new student
void AddNewStudent()
{
    char StudentID[300];
    char Name[300];
    char Phone[300];
    char Email[300];
    int NumberOfCourses;
    char CourseCode[300];
    char CourseName[300];

    int IsValidID = 0;
    while (!IsValidID)
    {
        printf(" Enter The ID: ");
        scanf("%s", &StudentID);
        if (IsAlreadyExists(StudentID, 'i', StudentID) > 0)
        {
            printf(" Error: This ID is already exists.\n\n");
            IsValidID = 0;
        }
        else if (strlen(StudentID) > 10)
        {
            printf(" Error: ID can not be more than 10 characters.\n\n");
            IsValidID = 0;
        }
        else if (strlen(StudentID) <= 0)
        {
            printf(" Error: ID can not be empty.\n\n");
            IsValidID = 0;
        }
        else
        {
            IsValidID = 1;
        }
    }

    int IsValidName = 0;
    while (!IsValidName)
    {
        printf(" Enter The Name: ");
        scanf(" %[^\n]s", &Name);
        if (strlen(Name) > 20)
        {
            printf(" Error: Name can not be more than 20 characters.\n\n");
            IsValidName = 0;
        }
        if (strlen(Name) <= 0)
        {
            printf(" Error: Name can not be empty.\n\n");
            IsValidName = 0;
        }
        else
        {
            IsValidName = 1;
        }
    }

    int IsValidEmail = 0;
    while (!IsValidEmail)
    {
        printf(" Enter The Email: ");
        scanf("%s", &Email);
        if (IsAlreadyExists(Email, 'e', StudentID) > 0)
        {
            printf(" This Email is Already Exists.\n");
            IsValidEmail = 0;
        }
        else if (strlen(Email) > 30)
        {
            printf(" Error: Email can not be more than 30 characters.\n\n");
            IsValidEmail = 0;
        }
        else if (strlen(Email) <= 0)
        {
            printf(" Error: Email can not be empty.\n\n");
            IsValidEmail = 0;
        }
        else
        {
            IsValidEmail = 1;
        }
    }

    int IsValidPhone = 0;
    while (!IsValidPhone)
    {
        printf(" Enter The Phone: ");
        scanf("%s", &Phone);
        if (IsAlreadyExists(Phone, 'p', StudentID) > 0)
        {
            printf(" This Phone Number is Already Exists\n");
            IsValidPhone = 0;
        }
        else if (strlen(Phone) > 20)
        {
            printf(" Error: Phone can not be more than 20 characters.\n\n");
            IsValidPhone = 0;
        }
        else if (strlen(Phone) <= 0)
        {
            printf(" Error: Phone can not be empty.\n\n");
            IsValidPhone = 0;
        }
        else
        {
            IsValidPhone = 1;
        }
    }

    int IsValidNumberOfCourse = 0;
    while (!IsValidNumberOfCourse)
    {
        printf(" Number of courses: ");
        scanf("%d", &NumberOfCourses);
        if (NumberOfCourses <= 0 || NumberOfCourses > 4)
        {
            printf(" Error: Number of courses can not be more than 4 and lees than 1.\n\n");
            IsValidNumberOfCourse = 0;
        }
        else
        {
            IsValidNumberOfCourse = 1;
        }
    }

    strcpy(Students[TotalStudents].ID, StudentID);
    strcpy(Students[TotalStudents].Name, Name);
    strcpy(Students[TotalStudents].Phone, Phone);
    strcpy(Students[TotalStudents].Email, Email);
    Students[TotalStudents].NumberOfCourse = NumberOfCourses;
    TotalStudents++;

    for (i = 0; i < NumberOfCourses; i++)
    {

        printf(" Enter Course %d Code: ", i + 1);
        scanf("%s", &CourseCode);

        printf(" Enter Course %d Name: ", i + 1);
        scanf(" %[^\n]s", &CourseName);

        strcpy(Courses[TotalCourse].StudentID, StudentID);
        strcpy(Courses[TotalCourse].Code, CourseCode);
        strcpy(Courses[TotalCourse].Name, CourseName);
        TotalCourse++;
    }

    printf("\n Student Added Successfully.\n\n");
}

// function to show the data of all the existing students
void ShowAllStudents()
{
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|    ID    |        Name        |            Email             |       Phone        |  NO.Course  |\n");
    printf("|==========|====================|==============================|====================|=============|\n");

    for (i = 0; i < TotalStudents; i++)
    {
        printf("|");
        printf("%s", Students[i].ID);
        for (j = 0; j < (10 - strlen(Students[i].ID)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s", Students[i].Name);
        for (j = 0; j < (20 - strlen(Students[i].Name)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s", Students[i].Email);
        for (j = 0; j < (30 - strlen(Students[i].Email)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s", Students[i].Phone);
        for (j = 0; j < (20 - strlen(Students[i].Phone)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%d", Students[i].NumberOfCourse);
        for (j = 0; j < 12; j++)
        {
            printf(" ");
        }
        printf("|\n");
        printf("|----------|--------------------|------------------------------|--------------------|-------------|\n");
    }
    printf("\n");
}

int SearchStudent(char StudentID[10])
{
    system("cls");
    int StudentFoundIndex = -1;

    int i;
    for (i = 0; i < TotalStudents; i++)
    {
        if (strcmp(StudentID, Students[i].ID) == 0)
        {
            StudentFoundIndex = i;
            printf("\n One Student Found for ID: %s\n\n", StudentID);
            printf(" Student Informations\n");
            printf("-------------------------\n");

            printf(" ID:    %s\n", Students[i].ID);
            printf(" Name:  %s\n", Students[i].Name);
            printf(" Email: %s\n", Students[i].Email);
            printf(" Phone: %s\n", Students[i].Phone);
            printf("\n Total Number of Courses: %d\n", Students[i].NumberOfCourse);
        }
    }
    int CourseCount = 0;
    int j;
    for (j = 0; j < TotalCourse; j++)
    {
        if (strcmp(StudentID, Courses[j].StudentID) == 0)
        {
            CourseCount++;
            printf(" Course %d Code: %s\n", CourseCount, Courses[j].Code);
            printf(" Course %d Name: %s\n", CourseCount, Courses[j].Name);
        }
    }

    return StudentFoundIndex;
}

// to  edit student data
void EditStudent(int StudentFoundIndex)
{
    printf("\n\t\t * Update The New Student *\n\n");

    char NewName[300];
    char NewPhone[300];
    char NewEmail[300];
    int NewNumberOfCourses;
    char StudentID[300];
    strcpy(StudentID, Students[StudentFoundIndex].ID);
    int OldTotalNumberOfCourse = Students[StudentFoundIndex].NumberOfCourse;

    int IsValidName = 0;
    while (!IsValidName)
    {
        printf(" Enter The New Name(0 for skip): ");
        scanf(" %[^\n]s", &NewName);
        if (strlen(NewName) > 20)
        {
            printf(" Error: Name can not be more than 20 characters.\n\n");
            IsValidName = 0;
        }
        else if (strlen(NewName) <= 0)
        {
            printf(" Error: Name can not be empty.\n\n");
            IsValidName = 0;
        }
        else
        {
            IsValidName = 1;
        }
    }

    int IsValidEmail = 0;
    while (!IsValidEmail)
    {
        printf(" Enter The New Email(0 for skip): ");
        scanf("%s", &NewEmail);

        if (strlen(NewEmail) > 30)
        {
            printf(" Error: Email can not be more than 30 characters.\n\n");
            IsValidEmail = 0;
        }
        else if (strlen(NewEmail) <= 0)
        {
            printf(" Error: Email can not be empty.\n\n");
            IsValidEmail = 0;
        }
        else if (IsAlreadyExists(NewEmail, 'e', StudentID) > 0)
        {
            printf(" Error: This Email Already Exists.\n\n");
            IsValidEmail = 0;
        }
        else
        {
            IsValidEmail = 1;
        }
    }

    int IsValidPhone = 0;
    while (!IsValidPhone)
    {
        printf(" Enter The New Phone(0 for skip): ");
        scanf("%s", &NewPhone);

        if (strlen(NewPhone) > 20)
        {
            printf(" Error: Phone can not be more than 20 characters.\n\n");
            IsValidPhone = 0;
        }
        else if (strlen(NewPhone) <= 0)
        {
            printf(" Error: Phone can not be empty.\n\n");
            IsValidPhone = 0;
        }
        else if (IsAlreadyExists(NewPhone, 'p', StudentID) > 0)
        {
            printf(" Error: This Phone Number is Already Exists.\n\n");
            IsValidPhone = 0;
        }
        else
        {
            IsValidPhone = 1;
        }
    }

    int IsValidNumberOfCourse = 0;
    while (!IsValidNumberOfCourse)
    {
        printf(" Number of New courses(0 for skip): ");
        scanf("%d", &NewNumberOfCourses);

        if (NewNumberOfCourses > 4 || NewNumberOfCourses < 0)
        {
            printf(" Error: A Student can have maximum 4 and Minimum 0 number of courses.\n\n");
            IsValidNumberOfCourse = 0;
        }
        else
        {
            IsValidNumberOfCourse = 1;
        }
    }

    if (strcmp(NewName, "0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Name, NewName);
    }

    if (strcmp(NewEmail, "0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Email, NewEmail);
    }

    if (strcmp(NewPhone, "0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Phone, NewPhone);
    }

    if (NewNumberOfCourses != 0)
    {
        int OldTotalCourse = Students[StudentFoundIndex].NumberOfCourse;
        Students[StudentFoundIndex].NumberOfCourse = NewNumberOfCourses;

        int FirstCourseIndex;
        int dc;
        for (dc = 0; dc < TotalCourse; dc++)
        {
            if (strcmp(StudentID, Courses[dc].StudentID) == 0)
            {
                FirstCourseIndex = dc; // store the index for delete
                break;
            }
        }
        // after every delete array index will update (decrease by one)
        // we store the courses sequential
        // so if we know the first course index and total number of course we can delete all
        for (dc = 1; dc <= OldTotalCourse; dc++)
        {
            DeleteCourseByIndex(FirstCourseIndex);
        }

        char CourseCode[300];
        char CourseName[300];
        for (i = 1; i <= NewNumberOfCourses; i++)
        {
            printf(" Enter New Course %d Code: ", i);
            scanf("%s", &CourseCode);

            printf(" Enter New Course %d Name: ", i);
            scanf(" %[^\n]s", &CourseName);

            strcpy(Courses[TotalCourse].StudentID, StudentID);
            strcpy(Courses[TotalCourse].Code, CourseCode);
            strcpy(Courses[TotalCourse].Name, CourseName);
            TotalCourse++;
        }
    }

    printf(" Student Updated Successfully.\n\n");
}

// to delete student data
void DeleteStudent(int StudentIndex)
{
    int d;
    int FirstCourseIndexs;
    struct StudentInfo ThisStudents;
    ThisStudents = Students[StudentIndex];
    for (d = 0; d < TotalCourse; d++)
    {
        if (strcmp(ThisStudents.ID, Courses[d].StudentID) == 0)
        {
            FirstCourseIndexs = d;
            break;
        }
    }
    for (d = 1; d <= ThisStudents.NumberOfCourse; d++)
    {
        DeleteCourseByIndex(FirstCourseIndexs);
    }
    DeleteStudentByIndex(StudentIndex);
    printf(" Student Deleted Successfully.\n\n");
    GoBackOrExit();
}

// delete all student data
void DeleteAllStudents()
{
    TotalStudents = 0;
    TotalCourse = 0;
    printf(" All Students Deleted Successfully.\n\n");
    GoBackOrExit();
}

// delete course of a student
void DeleteCourseByIndex(int CourseIndex)
{
    int c;
    for (c = 0; c < TotalCourse - 1; c++)
    {
        if (c >= CourseIndex)
        {
            Courses[c] = Courses[c + 1];
        }
    }
    TotalCourse--;
}

void DeleteStudentByIndex(int CourseIndex)
{
    int s;
    for (s = 0; s < TotalStudents - 1; s++)
    {
        if (s >= CourseIndex)
        {
            Students[s] = Students[s + 1];
        }
    }
    TotalStudents--;
}

int IsAlreadyExists(char GivenLine[300], char InfoType, char StudentID[300])
{
    int EmailExists = 0;
    int PhoneExists = 0;
    int IDExists = 0;
    int ep;

    for (ep = 0; ep < TotalStudents; ep++)
    {
        if (strcmp(GivenLine, Students[ep].ID) == 0)
        {
            IDExists++;
        }
        if (strcmp(GivenLine, Students[ep].Email) == 0 && strcmp(StudentID, Students[ep].ID) != 0)
        {
            EmailExists++;
        }
        if (strcmp(GivenLine, Students[ep].Phone) == 0 && strcmp(StudentID, Students[ep].ID) != 0)
        {
            PhoneExists++;
        }
    }

    if (InfoType == 'i')
    {
        return IDExists;
    }
    else if (InfoType == 'e')
    {
        return EmailExists;
    }
    else if (InfoType == 'p')
    {
        return PhoneExists;
    }
    else
    {
        return 0;
    }
}

void UserGuideline()
{
    printf("\n\t\t * How it Works? *\n\n");
    printf(" -> You will only able to store the Student's ID, Name, Email, Phone, Number of Courses.\n");
    printf(" -> A student can have maximum 4 courses and minimum 1 course.\n");
    printf(" -> Student ID can be maximum 10 characters long and unique for every students.\n");
    printf(" -> Student Name can be maximum 20 characters long.\n");
    printf(" -> Student Email can be maximum 30 characters long and unique for every students.\n");
    printf(" -> Student Phone can be maximum 20 characters long and unique for every students.\n");
    printf(" -> Course code can be maximum 10 characters long.\n");
    printf(" -> Course Name can be maximum 20 characters long.\n\n");
}

void AboutUs()
{
    printf("\n\t\t * About Us? *\n\n");
    printf("THIS PROJECT IS DONE BY PROJECT GROUP 08\n");
    printf("==>This is a simple College Administration system project\n");
    printf("==>It has two parts in it\n");
    printf("==>That are Student Management System and Library Management System\n");
    printf("==>The members of this project are:\n");
    printf("2301AI08-Banavth Dheeraj\n2301CB08-Aryan Sambare\n2301CB55-Pratik Mishra\n2301CT08-Bismay Bibhor\n2301CE08-Bharath Eslavth\n2301CE25-Savrav Kumar\n2301CS08-Arnav Reddy\n2301CS36-Praneeth Reddy\n2301EE08-Chitra Iyer\n2301EC08-Ayush Kumar\n");
}

void GoBackOrExit()
{
    getchar();
    char Option;
    printf(" Go back(b)? or Exit(0)?: ");
    scanf("%c", &Option);
    if (Option == '0')
    {
        ExitProject();
    }
    else
    {
        system("cls");
    }
}

void ExitProject()
{
    system("cls");
    int i;
    char ThankYou[100] = " ========= Thank You =========\n";
    char Haveaniceday[100] = " ========= Have A Nice Day ======\n";
    for (i = 0; i < strlen(ThankYou); i++)
    {
        printf("%c", ThankYou[i]);
        Sleep(40);
    }
    for (i = 0; i < strlen(Haveaniceday); i++)
    {
        printf("%c", Haveaniceday[i]);
        Sleep(40);
    }
    exit(0);
}

void DataSeed()
{

    //-- store some dummy data
    //-- student 1
    strcpy(Students[0].ID, "S-1");
    strcpy(Students[0].Name, "Student 1");
    strcpy(Students[0].Phone, "016111111111");
    strcpy(Students[0].Email, "student-1@gmail.com");
    Students[0].NumberOfCourse = 1;

    strcpy(Courses[0].StudentID, "S-1");
    strcpy(Courses[0].Code, "CSE-1");
    strcpy(Courses[0].Name, "Course - 1");

    //-- student 2
    strcpy(Students[1].ID, "S-2");
    strcpy(Students[1].Name, "Student 2");
    strcpy(Students[1].Phone, "016111111112");
    strcpy(Students[1].Email, "student-2@gmail.com");
    Students[1].NumberOfCourse = 2;

    strcpy(Courses[1].StudentID, "S-2");
    strcpy(Courses[1].Code, "CSE-1");
    strcpy(Courses[1].Name, "Course - 1");

    strcpy(Courses[2].StudentID, "S-2");
    strcpy(Courses[2].Code, "CSE-2");
    strcpy(Courses[2].Name, "Course - 2");

    //-- student 3
    strcpy(Students[2].ID, "S-3");
    strcpy(Students[2].Name, "Student 3");
    strcpy(Students[2].Phone, "016111111113");
    strcpy(Students[2].Email, "student-3@gmail.com");
    Students[2].NumberOfCourse = 3;

    strcpy(Courses[3].StudentID, "S-3");
    strcpy(Courses[3].Code, "CSE-1");
    strcpy(Courses[3].Name, "Course - 1");

    strcpy(Courses[4].StudentID, "S-3");
    strcpy(Courses[4].Code, "CSE-2");
    strcpy(Courses[4].Name, "Course - 2");

    strcpy(Courses[5].StudentID, "S-3");
    strcpy(Courses[5].Code, "CSE-3");
    strcpy(Courses[5].Name, "Course - 3");

    TotalStudents = 3;
    TotalCourse = 6;
}