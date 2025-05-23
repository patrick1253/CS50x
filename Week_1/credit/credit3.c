#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char card[] = "4444111122223333";
    long card[16];
          
    //long numsToDouble[16];
    int i;

    for (i = 15; i >= 0; i = i - 1)
    {   
        long card = strtol(card[i], NULL, 10);
        printf("%c", card[i]);  
    }

        
        //numsToDouble[i] = card[i];
        //printf("%i", numsToDouble[i]);
}






    /*
    //printf(" %c\n", card[0]);

    int length = strlen(card);
    printf("Length: %i\n", length);

    int digitsToDouble[16];

    for (int i = length; i >= 0; i = i-2)
    {
        char digit = (card[i]);
        printf("%c\n", card[i]);
        
        digitsToDouble[i] = digit;
        printf("%li", digitsToDouble[i]);

        //printf("%d", digitsToDouble);

        //digit = strtol(digit, '\0', 10) * 2;

        //printf("digit as int: %i\n", (int)digit);

        //int doubled = doubled + (digit * 2);
        //printf("%i\n", doubled);

    }*/