#include <stdio.h>

struct student
{
    int rollno;
    char name[50];
    int marks;
    char grade;
};

void main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll number: ");
        scanf("%d", &s[i].rollno);
        printf("Marks: ");
        scanf("%d", &s[i].marks);
        printf("Grade: ");
        scanf("%s", &s[i].grade);
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i].marks >= 75)
        {
            printf("%s\t%d\t%d\t%c\n", s[i].name, s[i].rollno, s[i].marks, s[i].grade);
        }
    }
}