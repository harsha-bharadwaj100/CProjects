#include <stdio.h>
#include <string.h>
struct DOB
{
    int day, month, year;
};

struct Employee
{
    char name[50];
    char designation[50];
    int salary;
    char department[50];
    struct DOB dob;
};

int main()
{
    int highest = 0;
    struct Employee emp[3];

    printf("Enter details of 3 Employees: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Employee(%d):\n", i + 1);
        printf("Enter name: ");
        scanf("%s", emp[i].name);
        printf("Enter designation: ");
        scanf("%s", emp[i].designation);
        printf("Enter salary: ");
        scanf("%d", &emp[i].salary);
        printf("Enter department: ");
        scanf("%s", emp[i].department);
        printf("Enter date of birth: \n");
        printf("Enter DOB(dd/mm/yyyy): ");
        scanf("%d/%d/%d", &emp[i].dob.day, &emp[i].dob.month, &emp[i].dob.year);
        printf("\n");
    }

    printf("Highest salary: \n");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(emp[i].designation, "Manager") == 0 && emp[i].salary > highest)
        {
            highest = emp[i].salary;
        }
    }

    printf("Manager(s) with the highest salary: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(emp[i].designation, "Manager") == 0 && emp[i].salary == highest)
        {
            printf("%s\t%d\n", emp[i].name, emp[i].salary);
        }
    }
}