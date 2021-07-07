#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>

/*Managing developers of an office having a number of branches. Adding, Deleting, Modifying the developers details and Displaying all the details of
employees in all the branches or at a specific branch given. When hikes are declared the employee details are modified and based on working hrs reward
points are also given*/

typedef struct employee
{
    char name[30], dept[5];
    int ID, sal, avgTimeInHoursPerDay;
    struct employee *link;
} employee;
employee *start = NULL, *q;

typedef struct BinaryTree
{
    char place[20];
    employee *officeEmployees;
    struct BinaryTree *left_branch, *right_branch;
} BT;
BT *headQuarter = NULL;

int length()
{
    int i;
    for(i = 0; q ; i++)
        q = q->link;
    return i;
}

// Checks whether the employee with ID is present or not
int isTheir(int ID)
{
    q = start;
    while(q)
    {
        if(q->ID == ID)
            return 1;
        q = q->link;
    }
    return 0;
}

// Displays the Employees List
void Display()
{
    q = start;
    if(!start)
        printf("No Records\n");
    else
    {
        while(q)
        {
            printf("Name: %-30s ID: %-7d Department: %-6s Salary: %7d Average Time Taken to Complete Work: %d\n", q->name, q->ID, q->dept, q->sal, q->avgTimeInHoursPerDay);
            q = q->link;
        }
    }
}

//For Inserting Function
void insertEmployee(char name[], int ID, char dept[], int sal, int avgTimeInHoursPerDay)
{
    employee *temp = (employee*)malloc(sizeof(employee));
    if(avgTimeInHoursPerDay > 8)
    {
        sal += (avgTimeInHoursPerDay - 8) * 1000;
        printf("Reward Points Added\n");
    }
    strcpy(temp->name, name);
    temp->ID = ID;
    strcpy(temp->dept, dept);
    temp->sal = sal;
    temp->avgTimeInHoursPerDay = avgTimeInHoursPerDay;
    temp->link = NULL;
    if(!start)
        start = temp;
    else
    {
        q = start;
        while(q->link)
            q = q->link;
        q->link = temp;
    }
    printf("Insertion Successful\n");
}

//For Delete Function
void deleteEmployee(int ID)
{
    int i = 1;
    employee *temp = (employee*)malloc(sizeof(employee));
    if(!start)
        printf("No Records\n");
    else if(start->ID == ID)
    {
        temp = start;
        start = start->link;
        printf("1Details of Employee with ID %d is Deleted successfully\n", temp->ID);
        free(temp);
    }
    else
    {
        q = start;
        while(q->link->ID != ID)
            q = q->link;
        temp = q->link;
        q->link = q->link->link;
        printf("Details of Employee with ID %d is Deleted successfully\n", temp->ID);
        free(temp);
    }
}

// Deletes All Records
void deleteAll()
{
    if(!start)
        printf("No Records To Delete\n");
    else
    {
        while(start)
        {
            q = start;
            start = start->link;
            free(q);
        }
        printf("All Records Deleted Successfully\n");
    }
}


// For Modify Function
void hike(int ID, int hikedSal)
{
    q = start;
    while(q->ID != ID)
        q = q->link;
    q->sal += hikedSal;
}

void modifyEmployee(int ID)
{
    int hikedSal;
    printf("Amount of Hike: ");
    scanf("%d",&hikedSal);
    hike(ID, hikedSal);
    printf("Employee Details Successfully Modified\n");
}

// Hike Function
void hikeForAll(int hikedSal)
{
    q = start;
    while(q)
    {
        q->sal += hikedSal;
        q = q->link;
    }
}

// For Sort Function
void swap(employee *a, employee *b)
{
    int temp;
    char tempChar[30];
    temp = a->ID;
    a->ID = b->ID;
    b->ID = temp;

    temp = a->sal;
    a->sal = b->sal;
    b->sal = temp;

    temp = a->avgTimeInHoursPerDay;
    a->avgTimeInHoursPerDay = b->avgTimeInHoursPerDay;
    b->avgTimeInHoursPerDay = temp;

    strcpy(tempChar, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tempChar);

    strcpy(tempChar, a->dept);
    strcpy(a->dept, b->dept);
    strcpy(b->dept, tempChar);
}

void sortByID(char ch)
{
    q = start;
    employee *r;
    int i = 0;
    if(ch == 'A')
    {
        while(q->link)
        {
            r = start;
            while(r->link)
            {
                if (r->ID > r->link->ID )
                    swap(r, r->link);
                r = r->link;
            }
            q = q->link;
        }
        printf("The List After Sorting in Ascending Order is:\n");
        Display();
    }

    else
    {
        while(q->link)
        {
            r = start;
            while(r->link)
            {
                if (r->ID < r->link->ID )
                    swap(r, r->link);
                r = r->link;
            }
            q = q->link;
        }
        printf("The List After Sorting in Descending Order is:\n");
        Display();
    }
}

void sortBySalary(char ch)
{
    q = start;
    employee *r;
    int temp1;
    if(ch == 'A')
    {
        while(q->link)
        {
            r = start;
            while(r->link)
            {
                if (r->sal > r->link->sal)
                    swap(r, r->link);
                r = r->link;
            }
            q = q->link;
        }
        printf("The List After Sorting in Ascending Order is:\n");
        Display();
    }
    else
    {
        while(q->link)
        {
            r = start;
            while(r->link)
            {
                if (r->sal < r->link->sal )
                    swap(r, r->link);
                r = r->link;
            }
            q = q->link;
        }
        printf("The List After Sorting in Descending Order is:\n");
        Display();
    }
}

// For Search Function
void search(int ID)
{
    q = start;
    while(q)
    {
        if(q->ID == ID)
        {
            printf("Name: %-30s ID: %-7d Department: %-6s Salary: %7d Average Time Taken to Complete Work: %d\n", q->name, q->ID, q->dept, q->sal, q->avgTimeInHoursPerDay);
            break;
        }
        q = q->link;
    }
    if(!q)
        printf("No Employee with ID %d\n", ID);
}

// Prints Menu
void menu()
{
    int sortChoice, sortOrderChoice, choice, ID, sal, hikedSal, avgTimeInHoursPerDay;
    char ch, cmd, hikeChoice, name[30],dept[5];
    do
    {
        printf("\t\t\t\t\tMenu\n-----------------------------------------------------------------------------------------------------\n1) Add Employee Record\t    |2) Delete an Employee Record\t|3) Modify the Details of an Employee\n4) Declare Hike\t\t    |5) Display the Employee Records\t|6) Sort Employees\n7) Search For an Employee   |8) Delete All Employee Record\t|9) Exit\n-----------------------------------------------------------------------------------------------------\nSelect An Option: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter Employee Details in (Name ID Department Salary AverageTimePerDayInHours) format:\n");
                    scanf("%s%d%s%d%d", name, &ID, dept, &sal, &avgTimeInHoursPerDay);
                    if(isTheir(ID)) //Checking whether employee with ID is present or not
                        printf("Employee with ID %d is Already present\n", ID);
                    else
                        insertEmployee(name, ID, dept, sal, avgTimeInHoursPerDay);
                    break;
            case 2: Display();
                    printf("Enter the ID of the employee you want to delete: ");
                    scanf("%d",&ID);
                    if(!isTheir(ID)) //Checking whether employee with ID is present or not
                        printf("Their is no Employee with ID %d\n",ID);
                    else
                    {
                        deleteEmployee(ID);
                        Display();
                    }
                    break;
            case 3: Display();
                    printf("Enter the ID of the employee you want to modify: ");
                    scanf("%d",&ID);
                    if(!isTheir(ID)) //Checking whether employee with ID is present or not
                        printf("Their is no Employee with ID %d\n",ID);
                    else
                    {
                        modifyEmployee(ID);
                        Display();
                    }
                    break;
            case 4: printf("Amount of Hike: ");
                    scanf("%d",&hikedSal);
                    hikeForAll(hikedSal);
                    break;
            case 5: Display();
                    break;
            case 6: printf("1) Sort By ID\n2) Sort By Salary\nSelect An Option: ");
                    scanf("%d",&sortChoice);
                    printf("1) Ascending\n2) Descending\nSelect The Order: ");
                    scanf("%d",&sortOrderChoice);
                    if(sortChoice == 1)
                    {
                        if(sortOrderChoice == 1)
                            sortByID('A');
                        else
                            sortByID('D');
                    }
                    else
                    {
                        if(sortOrderChoice == 1)
                            sortBySalary('A');
                        else
                            sortBySalary('D');
                    }
                    break;
            case 7: printf("Enter the ID of the employee you want to search: ");
                    scanf("%d",&ID);
                    search(ID);
                    break;
            case 8: deleteAll();
                    break;
            case 9: printf("Thank You\n");
                    return;
            default: printf("Invalid Option. Please Select a Valid Option\n");
        }
        printf("Do You Want to do something else[Y/N]: ");
        scanf(" %c",&cmd);
    }while(cmd == 'Y' || cmd == 'y');
}

BT* insertIntoTree(char place[], employee *emp)
{
    BT *temp = (BT*)malloc(sizeof(BT));
    strcpy(temp->place, place);
    temp->officeEmployees = emp;
    temp->left_branch = temp->right_branch = NULL;
    return temp;
}

void checkEmployee(char place[])
{
    if(strcmp(headQuarter->place, place) == 0)
        start = headQuarter->officeEmployees;
    else if(strcmp(headQuarter->left_branch->place, place) == 0)
        start = headQuarter->left_branch->officeEmployees;
    else if(strcmp(headQuarter->right_branch->place, place) == 0)
        start = headQuarter->right_branch->officeEmployees;
    else
    {
        printf("We don't have a Branch at %s\n", place);
        return;
    }
    menu();
}

void main()
{
    char SLChoice[7], username[20], password[20], scannedUsername[20], scannedPassword[20], c;
    printf("SignUp Or Login: ");
    scanf("%s", SLChoice);
    int found = 0, i = 0;
    FILE *adminFile;
    char place[20], checkChoice;
    if(strcmp(strlwr(SLChoice), "signup") == 0)
    {
        printf("Username: ");
        scanf("%s", username);
        adminFile = fopen("EmployeeProjectAdminCredentials.txt", "r");
        while(fscanf(adminFile, "%s %s\n", scannedUsername, scannedPassword) != EOF)
        {
            if(strcmp(scannedUsername, username) == 0)
            {
                found = 1;
                printf("Admin with this Username already exists\nProgram Exiting...\n");
                Sleep(1000);
                exit(0);
            }
        }

        if(found == 0)
        {
            printf("Set Password: ");
            while(i < 20)
            {
                password[i] = getch();
                c = password[i];
                if(c == 13) break;
                else printf("*");
                i++;
            }
            password[i] = '\0';
            printf("\n");
        }

        fclose(adminFile);
        adminFile = fopen("EmployeeProjectAdminCredentials.txt" , "a");
        fprintf(adminFile, "%s %s\n", username, password);
        fclose(adminFile);
        printf("Account Created Successfully\n");
    }

    else
    {
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        while(i < 20)
        {
            password[i] = getch();
            c = password[i];
            if(c == 13) break;
            else printf("*");
            i++;
        }
        password[i] = '\0';
        printf("\n");
        adminFile = fopen("EmployeeProjectAdminCredentials.txt", "r");
        while(fscanf(adminFile, "%s %s\n", scannedUsername, scannedPassword) != EOF)
        {
            if((strcmp(scannedUsername, username)) == 0 && strcmp(scannedPassword, password) == 0)
            {
                found = 1;
                printf("Logged In Successfully\n");
                break;
            }
        }
        fclose(adminFile);
        if(found == 0)
        {
            printf("No Admin with the Given Credentials\nProgram Exiting...\n");
            Sleep(1000);
            exit(0);
        }
    }

    // Menu Gets printed only if the credentials given are correct
    printf("Enter the HeadQuarters Location: ");
    scanf("%s", place);
    printf("Enter The Employee Details in Your Branch:\n");
    menu();
    headQuarter = insertIntoTree(place, start);
    start = NULL;

    printf("Enter the Left Branch's Location: ");
    scanf("%s", place);
    printf("Enter The Employee Details in Your Branch:\n");
    menu();
    headQuarter->left_branch = insertIntoTree(place, start);
    start = NULL;

    printf("Enter the Right Branch's Location: ");
    scanf("%s", place);
    printf("Enter The Employee Details in Your Branch:\n");
    menu();
    headQuarter->right_branch = insertIntoTree(place, start);
    start = NULL;

    printf("Want to Check For Employees In a Branch [Y/N]: ");
    scanf(" %c", &checkChoice);
    while(tolower(checkChoice) == 'y')
    {
        printf("Enter The Branch Name: ");
        scanf("%s", place);
        checkEmployee(place);
        printf("Want to Check Again [Y/N]: ");
        scanf(" %c", &checkChoice);
    }
    printf("Thank You for Using our Services\n");
}
