#include <stdio.h>
#include <string.h>

// Structure definition for student details
struct Student
{
    int rollno;
    char name[50];
    float marks;
    char grade;
};

int main()
{
    int n, count = 0;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Declare an array of structures to store student details
    struct Student s[n];

    // Input student details
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollno);

        printf("Name: ");
        scanf(" %[^\n]%*c", s[i].name); // To read string with spaces

        printf("Marks: ");
        scanf("%f", &s[i].marks);

        printf("Grade: ");
        scanf(" %c", &s[i].grade);
    }

    // Print the names of students with marks >= 70 and count them
    printf("\nStudents with marks greater than or equal to 70:\n");
    for (int i = 0; i < n; i++)
    {
        if (s[i].marks >= 70)
        {
            printf("Name: %s\n", s[i].name);
            count++;
        }
    }

    // Print the count
    printf("\nNumber of students with marks greater than or equal to 70: %d\n", count);

    return 0;
}