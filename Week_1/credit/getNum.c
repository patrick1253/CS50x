// a helper function to be added to credit.c to get a credit card fromm a user, validate that it is a 
//plausible number, and which credit card company is the issuer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNum(char* number, int length);



void numStringToIntArray(char* sourceArray, int length, int* destArray);
// void checkArrayContents(int* nameArray, int length);
// int luhnsAlgorithm(int* nameArray, int length);


int main(void)
{    
    char card[16];// = "4003600000000014"; // source string, as single-element array of chars

    do
    {
        printf("Enter credit card number: ");
        scanf("%s", card);    
        printf("card: %d\n", card[0]);
    }    
    while (card[0]-48 != 3 ||  card[0]-48 != 4 || card[0]-48 != 5);

    //char number[16];
    //scanf("%s", card);

    int length = strlen(card);
    int cCard[16];  // destination array, containing elements of source string as integers

    numStringToIntArray(card, length, cCard); // converts numerical string to array of single-digit integers
    
    /*
    checkArrayContents(cCard, length);   // confirms string was properly converted to int array
    //luhnsAlgorithm(cCard, length);  

    if (luhnsAlgorithm(cCard, length))  // checks validity of credit card number using algorithm
    {
        printf("Credit Card number is VALID\n");
    } 
    else 
    {
        printf("Credit Card number is INVALID. \n");
    } */
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

/*
int main(void)
{
    char number[16];
    int length = strlen(number);

    while (number[0] != 3 ||  number[0] != 4 || number[0] != 5)
    {
        printf("Enter credit card number: ");
        scanf("%s", number);
    }
    
    printf("CC num: %s,\n", number);
    // getNum(number, length);
}


int getNum(char* number, int length)
{





}
*/