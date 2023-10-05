/* 
 * 
 * File:   Calculator.c
 * Author: Jarrod Garcia-Guzman (jgarc250@ucsc.edu)
 *
 * Created on January 19, 2021
 */

// Standard libraries
#include <stdio.h>
#include <math.h>

//User libraries:
#include "BOARD.h"




// **** Declare function prototypes ****
double Add(double operand1, double operand2);
double Subtract(double operand1, double operand2);
double Multiply(double operand1, double operand2);
double Divide(double operand1, double operand2);
double AbsoluteValue(double operand);
double Round(double operand);
double FahrenheitToCelsius(double operand);
double CelsiusToFahrenheit(double operand);
double Tangent(double operand);
double Average(double operand1, double operand2);
//add more prototypes here

void CalculatorRun(void)
{
    printf("\n\nWelcome to Jarrod's calculator program! Compiled at %s %s\n", __DATE__, __TIME__);

    // Your code here
    while (1) {
        // establishing variables used for CalculatorRun()
        char g = 0;
        int t = 1;

        // while loop to gather operator input from user. If statement checks for proper operations only
        while (t == 1) {
            printf("\nEnter a mathematical operation to perform (*,/,+,-,m,a,c,f,t,r): ");
            scanf(" %c", &g);
            if (g == '+' || g == '-' || g == '*' || g == '/' || g == 'm' || g == 'a' || g == 'f' || g == 'c' || g == 't' || g == 'r')
                t = t - 1;
            else
                printf("Invalid operation. Please Try again\n");
        }

        // creating variables used for math operations and gathering the variables from user input
        double operand1 = 0;
        double operand2 = 0;
        double result = 0;
        
        printf("Enter the first operand: ");
        scanf(" %lf", &operand1);

        // certain operators require two variables
        if (g == '+' || g == '-' || g == '*' || g == '/' || g == 'm') {
            printf("Enter the second operand: ");
            scanf(" %lf", &operand2);
        }

        /* sorts out how to implement variables based on operator character
           functions are called out according to the right operator and then print the result */
        if (g == '+') {
            result = Add(operand1, operand2);
            printf("Result of (%lf + %lf): %lf \n", operand1, operand2, result);
        } else if (g == '-') {
            result = Subtract(operand1, operand2);
            printf("Result of (%lf - %lf): %lf \n", operand1, operand2, result);
        } else if (g == '*') {
            result = Multiply(operand1, operand2);
            printf("Result of (%lf * %lf): %lf \n", operand1, operand2, result);
        } else if (g == '/') {
            if (operand2 == 0) {
                printf("Divide by Zero Error\n");
            } else {
                result = Divide(operand1, operand2);
                printf("Result of (%lf / %lf): %lf \n", operand1, operand2, result);
            }
        } else if (g == 'm') {
            result = Average(operand1, operand2);
            printf("Result of ((%lf + %lf)/2): %lf \n", operand1, operand2, result);
        } else if (g == 'a') {
            result = AbsoluteValue(operand1);
            printf("Result of | %lf |: %lf \n", operand1, result);
        } else if (g == 'c') {
            result = FahrenheitToCelsius(operand1);
            printf("Result of %lf F: %lf C \n", operand1, result);
        } else if (g == 'f') {
            result = CelsiusToFahrenheit(operand1);
            printf("Result of %lf C: %lf F \n", operand1, result);
        } else if (g == 't') {
            result = Tangent(operand1);
            printf("Result of tan(%lf): %lf \n", operand1, result);
        } else if (g == 'r') {
            result = Round(operand1);
            printf("Result of round(%lf): %lf \n", operand1, result);
        }
    }
}

/********************************************************************************
 * Define the Add function here.
 ********************************************************************************/
double Add(double operand1, double operand2)
{
    double sum;
    sum = operand1 + operand2;

    return sum;
}

/********************************************************************************
 * Define the Subtract function here.
 ********************************************************************************/
double Subtract(double operand1, double operand2)
{
    double sum;
    sum = operand1 - operand2;

    return sum;
}

/********************************************************************************
 * Define the Multiply function here.
 ********************************************************************************/
double Multiply(double operand1, double operand2)
{
    double sum;
    sum = operand1 * operand2;

    return sum;
}

/********************************************************************************
 * Define the Divide function here.
 ********************************************************************************/
double Divide(double operand1, double operand2)
{
    double sum;
    sum = operand1 / operand2;

    return sum;
}

/********************************************************************************
 * Define the Absolute Value function here.
 ********************************************************************************/
double AbsoluteValue(double operand)
{
    if (operand < 0)
        operand = -operand;


    return operand;
}

/*********************************************************************************
 * Define the Fahrenheit to Celsius function here.
 ********************************************************************************/
double FahrenheitToCelsius(double operand)
{
    double celsius;
    celsius = (5.0 / 9.0)*(operand - 32.0);
    return celsius;
}

/*********************************************************************************
 * Define the Celsius to Fahrenheit function here.
 ********************************************************************************/
double CelsiusToFahrenheit(double operand)
{
    double Fahrenheit;
    Fahrenheit = ((9.0 / 5.0)*(operand)) + 32;
    return Fahrenheit;
}

/********************************************************************************
 * Define the Average function here.
 *******************************************************************************/
double Average(double operand1, double operand2)
{
    double output;
    output = operand1 + operand2;
    output = output / 2;
    return output;
}

/*********************************************************************************
 * Define the Tangent function that takes input in degrees.
 ********************************************************************************/
double Tangent(double operand)
{
    double deg;
    deg = tan(operand * M_PI / 180);

    return deg;
}

/*********************************************************************************
 * Define the Round function here.
 * In order to receive the extra credit your calculator MUST ALSO CORRECTLY utilize
 * this function.
 ********************************************************************************/
double Round(double operand)
{
    int whole;
    if (operand >= 0) {
        operand = operand + .5;
    } else {
        operand = operand - .5;
    }
    whole = (int) operand;
    whole = (double) whole;
    return whole;
}


