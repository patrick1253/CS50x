#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_card(void);
int get_length(string card_num);

string card_num;
int length;


int main(void)
{
    long card_num[] = get_card();
    int length = get_length(card_num);

}

// get credit card number
string get_card(void)
{
    string card_num = '4000111122223333';
    // string card_num = get_string("Credit card number: \n");
    
    printf("card_num: %s\n", card_num);
    return card_num;
}


int get_length(card_num)
{
    int length = strlen(card_num);
    
    printf("len: %i\n", length);
    return length;
}


{
    int length = 0;
    while (card_num[length] != '\0');
    {
        length++;
    }
return length;
}

// Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add 
// those products’ digits together.
int double_digits(long card_num)
{
    int digits = [length/2];
    int length = strlen(card_num);
    for (int i = 0, i < length/2; i = i +2)
    {
        int digits[0] = card_num[length - i] * 2;
        printf("%s\n", digits);
    }
}

// Add the sum to the sum of the digits that weren’t multiplied by 2.


// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), 
// the number is valid!

// program’s last line of output must be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n,
