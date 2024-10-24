#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// convert string to double
int main()
{
    char str[] = ".1*+4";
    char *startptr = str;
    char *endptr;

    double num = strtod(startptr, &endptr);
    printf("num = %lf\n", num);
    // print index of startptr and endptr
    printf("startptr = %d\n", startptr - str);
    printf("endptr = %d\n", endptr - str);
    return 0;
}