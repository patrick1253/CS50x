#include <cs50.h>
#include <string.h>
#include <stdio.h>

char get_card(void);
int get_length(void);


char card[] = "4444111122223333";
int length;
//char input_card;

//char *card = input_card[16];

int main() 
{
    char get_card();
    int length = get_length();

    printf("%i\n", length);
}


//char get_card()
//{
//   char input_card[16] = "4444111122223333";
   //char input_card[16] = get_long("card number: \n");
   //return input_card;
//}


int get_length(void)
{
    // Find length of string using strlen()
	int length = strlen(card);
    
    //printf("%lu\n", strlen(card));
    //printf("%i\n", length);
  
    return length;
}


// Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add 
// those products’ digits together.
//int double_digits(card)
// {
//     //int digits = card[length/2];
//     int doubled = 0;

//     for (int i = length - 2; i > 0; i = i - 2)
//     {
//         int doubled = doubled + (card[i] * 2); 
        
//         printf("%i\n", doubled);
//     }
// }

// Add the sum to the sum of the digits that weren’t multiplied by 2.


// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), 
// the number is valid!

// program’s last line of output must be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n,