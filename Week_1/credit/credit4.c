#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void numStringToIntArray(char* sourceArray, int length, int* destArray);
void checkArrayContents(int* nameArray, int length);
int luhnsAlgorithm(int* nameArray, int length);


int main(void)
{
    char card[] = "4003600000000014"; // source string, as single-element array of chars
    int length = strlen(card);
    int cCard[16];  // destination array, containing elements of source string as integers

    numStringToIntArray(card, length, cCard); // converts numerical string to array of single-digit integers
    checkArrayContents(cCard, length);   // confirms string was properly converted to int array
    //luhnsAlgorithm(cCard, length);  

    if (luhnsAlgorithm(cCard, length))  // checks validity of credit card number using algorithm
    {
        printf("Credit Card number is VALID\n");
    } 
    else 
    {
        printf("Credit Card number is INVALID. \n");
    }
}


void numStringToIntArray(char* sourceArray, int length, int* destArray)
{   
    int digit;

    for (int i = 0; i < length; i++)
    {
        digit = sourceArray[i] - 48;
        destArray[i] = digit;
    }
}


void checkArrayContents(int* nameArray, int length)
    // Checks contents of array of integers
{   
    printf("cCard: [");
    for (int j = 0; j < length - 1; j++)
    {
        printf("%i, ", nameArray[j]);
    }
    printf("%i", nameArray[length - 1]);
    printf("]\n");
}


int luhnsAlgorithm(int* nameArray, int length)
{
    // Step 1:  Multiply every other digit by 2, starting with the second to last digit, 
    // and sum THEIR DIGITS (i.e.: 12 is 1+2, not +12) digits

    int checkDoubleSum = 0;
    for (int k = 2; k <= length; k = k + 2)
    {
        int checkDoubleDigit = nameArray[length - k];
        if (checkDoubleDigit * 2 >= 10)
        {
            checkDoubleSum ++;
        }
        checkDoubleSum = checkDoubleSum + ((checkDoubleDigit *2) % 10);

        printf("cCard[double]: %i, \n", nameArray[length - k]);
    }
    
    printf("checkDoubleSum: %i\n", checkDoubleSum);
    
    // Step 2: Get sum of digits that were not multiplied by 2 in the previous step

    int checkSingleSum = 0;
    for (int k = 1; k <= length; k = k + 2)
    {
        int checkSingleDigit = nameArray[length - k];
        checkSingleSum = checkSingleSum + (checkSingleDigit);

        printf("cCard[single]: %i, \n", nameArray[length - k]);
    }
    
    printf("checkSingleSum: %i\n", checkSingleSum);
        
    // Step 3: Add the checkDoubleSum to the checkSingleSum.  If the total sum mod 10 == 0, return True

    int checkSum = checkSingleSum + checkDoubleSum;
    printf("checkSum: %i\n", checkSum);

    return checkSum % 10 == 0;

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