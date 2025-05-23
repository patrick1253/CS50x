#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void numStringToIntArray(char* sourceArray, int length, int* destArray);
void checkArrayContents(int* nameArray, int length);
int checkIssuer(int* nameArray, int length, /* int* validIssuer,*/ char* issuer);
int luhnsAlgorithm(int* nameArray, int length, int* validity);


int main(void)
{
    char card[16];  // source string, as single-element array of chars
    printf("Enter credit card number: ");
    scanf("%s", card);
        
    int length = strlen(card);
    int cCard[16];  // destination array, containing elements of CC number (source string) as integers
    //int validIss[] = {0}; // Issuer Format 3: AMEX, 4: VISA, 5: MC, 0: default (invalid issuer format)
    int validNum[] = {0}; // 1: CC number complies with Luhn's Algorithm, 0: default (invalid CC number)

    char issuer[20]; // destination array to store name of issuing CC company

    numStringToIntArray(card, length, cCard); 
    
    // optional helper program for debugging -- prints entire array to confirm string was properly converted:    
    // checkArrayContents(cCard, length);   

 
    checkIssuer(cCard, length, /*validIss,*/ issuer);
    luhnsAlgorithm(cCard, length, validNum);
    
    // printf("*validNum: %d\n", *validNum);            
    // printf("IssuedBy: %d\n", issuedBy[0]);
    printf("Issuer: %s", issuer);
    // printf("strcmp issuer vs INVALID: %i\n", strcmp(issuer, "INVALID\n"));
    
    if (*validNum == 1 && (strcmp(issuer, "INVALID\n") != 0)) //issuer != "INVALID\n") // validIss != 0
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


int checkIssuer(int* nameArray, int length, /*int* validIssuer,*/ char* issuer)
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
            //*validIssuer = 3;
            //printf("AMEX\n");
            strcpy(issuer, "AMEX\n");
            break;
        case 4:
            //*validIssuer = 4;
            //printf("VISA\n");
            strcpy(issuer, "VISA\n");
            break;
        case 5:
            //*validIssuer = 5;
            // printf("MASTERCARD\n");
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

        // printf("cCard[double]: %i, \n", nameArray[length - k]); // optional debugging statement
    }
    
    // printf("checkDoubleSum: %i\n", checkDoubleSum);  // optional debugging statement
    
    // Step 2: Get sum of digits that were not multiplied by 2 in the previous step

    int checkSingleSum = 0;
    for (int k = 1; k <= length; k = k + 2)
    {
        int checkSingleDigit = nameArray[length - k];
        checkSingleSum = checkSingleSum + (checkSingleDigit);

        // printf("cCard[single]: %i, \n", nameArray[length - k]); // optional debugging statement
    }
    
    // printf("checkSingleSum: %i\n", checkSingleSum);  // optional debugging statement
        
    // Step 3: Add the checkDoubleSum to the checkSingleSum.  If the total sum mod 10 == 0, return True

    int checkSum = checkSingleSum + checkDoubleSum;
    // printf("checkSum: %i\n", checkSum);

    //return checkSum % 10 == 0;
    *validity = (checkSum % 10 == 0);
}
