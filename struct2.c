#include <stdio.h>

// Structure definition for complex numbers
struct Complex
{
    float real;
    float imag;
};

// Function to add two complex numbers
struct Complex addComplex(struct Complex num1, struct Complex num2)
{
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

// Function to input a complex number
struct Complex inputComplex()
{
    struct Complex num;
    printf("Enter the real part: ");
    scanf("%f", &num.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &num.imag);
    return num;
}

// Function to display a complex number
void displayComplex(struct Complex num)
{
    if (num.imag >= 0)
        printf("Complex number: %.2f + %.2fi\n", num.real, num.imag);
    else
        printf("Complex number: %.2f - %.2fi\n", num.real, -num.imag);
}

int main()
{
    struct Complex num1, num2, sum;

    // Input two complex numbers
    printf("Enter the first complex number:\n");
    num1 = inputComplex();

    printf("Enter the second complex number:\n");
    num2 = inputComplex();

    // Add the two complex numbers
    sum = addComplex(num1, num2);

    // Display the result
    printf("\nThe sum of the two complex numbers is:\n");
    displayComplex(sum);

    return 0;
}