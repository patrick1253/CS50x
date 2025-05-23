/* 
A cleaned up version of the credit.c program, written for CS-50x.  This is meant to be an intro class,
so I suspect I over-thought this project.  I had a tough time passing arguments to functions (especially arrays,
and particularly string arrays) so it is likely there is an easier and cleaner way to do this.  That said, I 
learned a lot about C, if not about programming per se.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void numStringToIntArray(char* sourceArray, int length, int* destArray);
// void checkArrayContents(int* nameArray, int length);
int checkIssuer(int* nameArray, int length, char* issuer);
int luhnsAlgorithm(int* nameArray, int length, int* validity);


int main(void)
{
    char card[16];  // source string, as single-element array of chars
    printf("Enter credit card number: ");
    scanf("%s", card);
        
    int length = strlen(card);
    int cCard[16];  // destination array, containing elements of CC number (source string) as integers
    int validNum[] = {0}; // 1: CC number complies with Luhn's Algorithm, 0: default (invalid CC number)
    char issuer[20]; // destination array to store name of issuing CC company

    numStringToIntArray(card, length, cCard); 
    checkArrayContents(cCard, length);      
    checkIssuer(cCard, length, issuer);
    luhnsAlgorithm(cCard, length, validNum);
    
    printf("Issuer: %s", issuer);
    
    if (*validNum == 1 && (strcmp(issuer, "INVALID\n") != 0))
    {
        printf("Credit Card number is VALID\n");
    } 
        else 
        {
        printf("Credit Card number is INVALID. \n");
        }
}


void numStringToIntArray(char* sourceArray, int length, int* destArray)
    // converts numerical string to array of single-digit integers
{   
    int digit;

    for (int i = 0; i < length; i++)
    {
        digit = sourceArray[i] - 48;
        destArray[i] = digit;
    }
}


void checkArrayContents(int* nameArray, int length)
    // Helper function for debugging:  Prints contents of array of integers
{   
    printf("cCard: [");  

    for (int j = 0; j < length - 1; j++)
    {
        printf("%i, ", nameArray[j]);
    }
    printf("%i", nameArray[length - 1]);
    printf("]\n");
}


int checkIssuer(int* nameArray, int length, char* issuer)
    // Checks whether first digits match Issuer formats
{
    if (length < 13)
    {
        printf("Credit card number seems too short to be valid\n");
    }
    int first = nameArray[0];
    int second = nameArray[1];
    int formatCode = 0;
    
    if (first == 4) // all VISA cards begin with 4
    {
        formatCode = 4;
    } 

    if (first == 3) // all AMEX cards begin with 34 or 37
    {
        if (second == 4 || second == 7)
        {
            formatCode = 3;
        }
    } 

    if (first == 5) // all MASTERCARDs begin with 51, 52, 53, 54, or 55
    {
        if (second > 0 && second < 6)
        {
            formatCode = 5;
        }
    }

    switch (formatCode)
    {
        case 3:
            strcpy(issuer, "AMEX\n");
            break;
        case 4:
            strcpy(issuer, "VISA\n");
            break;
        case 5:
            strcpy(issuer, "MASTERCARD\n");
            break;
        default:
            strcpy(issuer, "INVALID\n");
            break;
    }
}


int luhnsAlgorithm(int* nameArray, int length, int* validity)
    // checks validity of credit card number using 3-step algorithm:

    // Step 1:  Multiply every other digit by 2, starting with the second to last digit, 
    // and sum THEIR DIGITS (i.e.: 12 is 1+2, not +12) digits
{
    int checkDoubleSum = 0;
    for (int k = 2; k <= length; k = k + 2)
    {
        int checkDoubleDigit = nameArray[length - k];
        if (checkDoubleDigit * 2 >= 10)
        {
            checkDoubleSum ++;
        }
        checkDoubleSum = checkDoubleSum + ((checkDoubleDigit *2) % 10);
    }
        
    // Step 2: Get sum of digits that were not multiplied by 2 in the previous step

    int checkSingleSum = 0;
    for (int k = 1; k <= length; k = k + 2)
    {
        int checkSingleDigit = nameArray[length - k];
        checkSingleSum = checkSingleSum + (checkSingleDigit);
    }
            
    // Step 3: Add the checkDoubleSum to the checkSingleSum.  If the total sum mod 10 == 0, return True

    int checkSum = checkSingleSum + checkDoubleSum;
    
    *validity = (checkSum % 10 == 0);
}
