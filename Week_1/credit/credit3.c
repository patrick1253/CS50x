#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *card = "4444111122223333";
    printf("%c\n", card[0]);

    int length = strlen(card);
    printf("%i\n", length);

    int doubled = 0;

    for (int i = length; i >= 0; i = i -2)
    {
        char digit = (card[i]);
        //printf("%c\n", card[i]);
        printf("digit as char: %c\n", digit);

        //digit = strtol(digit, '\0', 10) * 2;

        printf("digit as int: %i\n", digit);

        //int doubled = doubled + (digit * 2);
        //printf("%i\n", doubled);

    }

}