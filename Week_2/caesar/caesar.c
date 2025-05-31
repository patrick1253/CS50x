// CS50x assignment

// line 65 (terminating cyperText string with '\0') added at suggestion of Grok ai

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAXSIZE = 1000;

void getPlainText(char *plainText, int MAXSIZE);
void encryptText(char *plainText, char key, char *cypherText);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Missing cypher key:  Please include one CLI argument.\n");
        return 1;
    }

    if (!isdigit(argv[1][0]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char *endptr;
    int key = strtol(argv[1], &endptr, 10);

    char plainText[MAXSIZE];
    char cypherText[MAXSIZE];

    getPlainText(plainText, MAXSIZE);
    encryptText(plainText, key, cypherText);

    printf("Cyphertext: %s\n", cypherText);
    return 0;
}
 

void getPlainText(char *plainText, int MAXSIZE)
{
    printf("Enter plaintext:  ");
    //scanf("%s\n", plainText);
    fgets(plainText, MAXSIZE, stdin);
    if (strlen(plainText) > 0 && plainText[-1] == '\n')
    {
        plainText[-1] = '\0';
    }
}


void encryptText(char *plainText, char key, char *cypherText)
{
    int length = strlen(plainText);
    //printf("len: %i\n", length);

    for (int i = 0; i < length; i++)
    {    

        if (isalpha(plainText[i]))
        {
            if (islower(plainText[i]))
            {
                cypherText[i] = 97 + (plainText[i] - 97 + key) % 26;
            }
            else if (isupper(plainText[i]))
            {
                cypherText[i] = 65 + (plainText[i] - 65 + key) % 26;
            }
        }
        else
        {
            cypherText[i] = plainText[i];
        }
    }
    cypherText[length] = '\0';
}