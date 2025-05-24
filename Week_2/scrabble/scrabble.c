// CS50x assignment

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scoreLetter(char* input, int* value[26][2]);

int letterValues[26][2] = {{'a',1}, {'b',3}, {'c',3}, {'d',2}, {'e',1}, \
                            {'f',4}, {'g',2}, {'h',4}, {'i',1}, {'j',8}, \
                            {'k',5}, {'l',1}, {'m',3}, {'n',1}, {'o',1}, \
                            {'p',3}, {'q',10}, {'r',1}, {'s',1}, {'t',1}, \
                            {'u',1}, {'v',4}, {'w',4},{'x',8}, {'y',4}, {'z',10}};

//int (*pLetterValues)[26][26] = &letterValues[26][26];
//int* pLetterValues[26][26] = &letterValues;
int* pLetterValues[26][2];

//char letter = {'z'};
//char* pLetter = &letter; 

int main(void)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            pLetterValues[i][j] = &letterValues[i][j];
        }    
    }
    
    //printf("letter: %c, letter value: %d\n", letterValues[20][0], letterValues[20][1]);
    

    // accept user input
    char word1[20];  // source string, as single-element array of chars
    printf("Enter first word: ");
    scanf("%s", word1);
    int length = strlen(word1);
    //int cCard[16];  // destination array, containing elements of CC number (source string) as integers

    int totalScore = 0;

    for (int k = 0; k < length; k++)
    {
        char inputLetter = word1[k];
        char* pInput = &inputLetter;
        totalScore = totalScore + scoreLetter(pInput, pLetterValues);
    }
        printf("Total Word Score: %i\n", totalScore);

}

int scoreLetter(char* input, int* value[26][2])
    // receive one letter, search for that letter in letterValues[0], pull score from letterValues[1]
{
    char inputLetter = *input;
    //printf("string: %c, ascii: %d\n", inputLetter, inputLetter);
    printf("letter: %c,  ", inputLetter);

    int score = *value[(inputLetter - 97)][1];
    printf("letter score: %d\n", score);
    return score;

}