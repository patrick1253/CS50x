#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void numStringToIntArray(char* sourceArray, int length, int* destArray);
void checkArrayContents(int* nameArray, int length);
int checkIssuer(int* nameArray, int length, int* issuer);
int luhnsAlgorithm(int* nameArray, int length, int* validity);


int main(void)
{
    char card[16];  // source string, as single-element array of chars
    printf("Enter credit card number: ");
    scanf("%s", card);
        
    int length = strlen(card);
    int cCard[16];  // destination array, containing elements of source string as integers
    int issuedBy[] = {0};
    int valid[] = {0};

    numStringToIntArray(card, length, cCard); 
    
    // optional helper program for debugging -- prints entire array to confirm string was properly converted:    
    // checkArrayContents(cCard, length);   

 
    checkIssuer(cCard, length, issuedBy);
    
    if (*valid == 0)
    {
        if (*issuedBy != 0)
        {
            printf("%d\n", *issuedBy);
            printf("Credit Card number is VALID\n");
        }
    } 
        else 
    {
        printf("Credit Card number is inVALID. \n");

    /*
    printf("Issuer: ");
    switch (checkIssuer(cCard, length, issuedBy))
    {
        case 3:
            *issuedBy = 3;
            printf("AMEX\n");
            break;
        case 4:
            *issuedBy = 4;
            printf("VISA\n");
            break;
        case 5:
            *issuedBy = 5;
            printf("MASTERCARD\n");
            break;
        //case 9:
        //    *issuedBy = 9;
        //    printf("Invalid Issuer\n");
        default:
            printf("INVALID\n");
            break;
    }
    

   

    if (luhnsAlgorithm(cCard, length))  // checks validity of credit card number using algorithm
    {
        printf("%d\n", *issuedBy);
        if (*issuedBy != 0) // checks validity of first digits versus credit card Issuer format
        {
        printf("Credit Card number is VALID\n");
        }
    } 
        else 
    {
        printf("Credit Card number is inVALID. \n");
    }
    */
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


int checkIssuer(int* nameArray, int length, int* issuer)
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
            *issuer = 3;
            printf("AMEX\n");
            break;
        case 4:
            *issuer = 4;
            printf("VISA\n");
            break;
        case 5:
            *issuer = 5;
            printf("MASTERCARD\n");
            break;
        //case 9:
        //    *issuedBy = 9;
        //    printf("Invalid Issuer\n");
        default:
            printf("INVALID\n");
            break;
    }













    /*
    else
    {
        return 9;
    }
    */
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
    printf("checkSum: %i\n", checkSum);

    //return checkSum % 10 == 0;
    *validity = (checkSum % 10 == 0);

}




/*
        // Iterate through string, adding each char as an int to the cCard array
    for (int i = 0; i < length; i++)
    {
        int digit;

        digit = card[i] - 48;
        cCard[i] = digit;
        // digitSum = digitSum + digit;
        // printf("char: %i\ndigitSum: %i\n", digit, digitSum);
    }
*/

/*  // Never got this to work correctly
    char* cursor = card;
    while (cursor != card + strlen(card))
    {
        long int x = strtol(cursor, &cursor, 10);
        printf("x: %ld\n", x);
        //printf("long int x: %li\n", x);
    }

}

*/

/*  // no longer needed -- replicates functionality of checkArrayContents function

    printf("cCard: [");
    for (int j = 0; j < length - 1; j++)
    {
        printf("%i, ", cCard[j]);
    }
    printf("%i", cCard[length - 1]);
    printf("]\n");
*/

/*
    char* cursor = card;
    while (cursor != card + strlen(card))
    {
        long int x = strtol(cursor, &cursor, 10);
        printf("x: %ld\n", x);
        //printf("long int x: %li\n", x);
    }
}
*/


/*
    char* cursor = card;
    while (cursor != card + strlen(card))
    {
        long int x = strtol(cursor, &cursor, 10);
        printf("x: %ld\n", x);
        //printf("long int x: %li\n", x);
    }
}
*/
    
    /*
    int digit;
    strcpy(digit, &card[1]);
    printf("digit: %d\n", digit);


    
    char cardString[] = "1234";
    printf("cardString[0]: %c\n", cardString[0]);

    long digit = strtol(&cardString[0], '\0', 10);
    printf("%ld\n", digit); 


    int length = strlen(cardString);
    printf("%i\n", length);

    long cCard[length];
    for (int i = 0; i < length; i++)
    {
        cCard[i] = cardString[i];
        printf("cCard: %ld ", cCard[i]);
        
    }
    printf("\n");

    printf("cCard: %ln\n", cCard);

    for (int i = 0; i < length; i++)
    {    
        cCard[i] = strtol(&cardString[i], NULL, 10);
        printf("%li\n", cCard[i]);

        //cCard[i] = cardString[i]; 
        //printf("%li\n", cCard[i]);
    }
    //printf("%ln\n", cCard);
   
}

    /*
    char* card = "1234";
    long creditCard[16];
    
    for (int i = 0; i < 4; i++)
    {
        //printf("%c", card[i]);
        long cCard = strtol(card, NULL, 10);
        printf("%li ", cCard);

        creditCard[i] = card[i];
        creditCard[i]= strtol(card[i], NULL, 10);

        printf("%li\n", creditCard[i]);

    }
        
    

    {
        //creditCard[i] = card[i];
        //creditCard[i] = cCard[i];
        
       
    }
    //printf("%li\n", creditCard);
  
}
    */