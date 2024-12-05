#include <stdio.h>

int main()
{
    int Year;
    printf("enter an year");
    scanf("%d", &Year);
    if (Year % 100 == 0)
    {
        if (Year % 400 == 0)
            printf("the year is leap year");
        else
            printf("The year is not a leap year");
    }
    else
    {
        if (Year % 4 == 0)
            printf("the year is leap year");
        else
            printf("the year is not leap year");
    }
}