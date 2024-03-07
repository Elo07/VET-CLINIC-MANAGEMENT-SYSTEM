/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Ehimwenma Larry Okuonghae
Student ID#: 145203238
Email      : elokuonghae@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

#include "core.h"

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    int value;
    char character = ' ';
    do {
        scanf("%d%c", &value, &character);
        
        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (character != '\n');
    
    return value;
}

int inputIntPositive(void)
{
    int value;
    char character = ' ';
    do {
        scanf("%d%c", &value, &character);
        
        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    }while (value <= 0);
    
    return value;
}

int inputIntRange(int lowerBound, int upperBound)
{
    int value;
    char character = ' ';
    
    scanf("%d%c", &value, &character);
    do {
        
        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
            scanf("%d%c", &value, &character);
        }
        else if (!(value >= lowerBound && value <= upperBound))
        {
            printf("ERROR! Value must be between 1 and 28 inclusive: ");
            scanf("%d%c", &value, &character);
        }
        
    }while (!(value >= lowerBound && value <= upperBound));
    
    return value;
}

char inputCharOption(const char validChars[])
{
    char input;
    int i, count = 0;
    
    do {
        scanf(" %c", &input);
        for (i = 0; validChars[i] != '\0'; i++)
        {
            if (input == validChars[i])
            {
                count++;
            }
        }
        if (count == 0)
        {
            printf("ERROR: Character must be one of [%s]: ",validChars);
        }
    } while (count == 0);
    clearInputBuffer();
    return input;
}

void inputCString (char *str, int minChars, int maxChars)
{
    int flag = 1;
    char ch = 'a';

    while (flag)
    {
        int length = 0;
        while (ch != '\n' && length <= maxChars)
        {
            ch = getchar();
            str[length] = ch;
            length++;
        };
        if (ch == '\n' && length <= (maxChars + 1))
        {
            length--;
            str[length] = '\0';
        }
        else
        {
            str[maxChars] = '\0';
            clearInputBuffer();
        }

        if (minChars == maxChars && length != minChars)
        {
            printf("ERROR: String length must be exactly %d chars: ", minChars);
            ch = 'a';
        }
        else if (length < minChars || length > maxChars)
        {
            if (length > maxChars)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxChars);
                ch = 'a';
            }
            else if (length < minChars)
            {
                printf("ERROR: String length must be between %d and %d chars: ", minChars, maxChars);
                ch = 'a';
            }
        }
        else
        {
            flag = 0;
        }
    }
}

void inputCStringNumbers(char* str, int minChars, int maxChars) 
{
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int len = 0;
        while (ch != '\n' && len <= maxChars) 
        {
            ch = getchar();
            str[len] = ch;
            len++;
        };
        if (ch == '\n' && len <= (maxChars + 1)) 
        {
            len--;
            str[len] = '\0';
        }
        else 
        {
            str[maxChars] = '\0';
            clearInputBuffer();
        }

        if (minChars == maxChars && len != minChars) 
        {
            printf("Invalid 10-digit number! Number: ");
            ch = 'a';
        }
        else 
        {
            flag = 0;
        }
    }
}

void displayFormattedPhone (const char *phoneNumber)
{
    int len = 0;

    while (phoneNumber != NULL && phoneNumber[len] && (phoneNumber[len] >= '0' && phoneNumber[len] <= '9'))
    {
            len++;
    }
    if (len == 10)
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c",phoneNumber[0], phoneNumber[1], phoneNumber[2],phoneNumber[3], phoneNumber[4], phoneNumber[5],phoneNumber[6], phoneNumber[7], phoneNumber[8], phoneNumber[9]);
    }
    else
    {
        printf("(___)___-____");
    }
}
