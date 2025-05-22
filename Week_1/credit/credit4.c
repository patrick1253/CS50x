#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void numStringToIntArray(char* sourceArray, int length, int* destArray);
void checkArrayContents(int* nameArray, int length);


int main(void)
{
    char card[] = "12345678";
    int length = strlen(card);

    int cCard[16];

    numStringToIntArray(card, length, cCard);
    checkArrayContents(cCard, length);    
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

void numStringToIntArray(char* sourceArray, int length, int* destArray)
{   
    int digit;
    //int digitSum = 0;
    //int cCard[16];

    for (int i = 0; i < length; i++)
    {
        digit = sourceArray[i] - 48;
        destArray[i] = digit;
    }
    // return cCard;
}


    

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



/**/
    





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