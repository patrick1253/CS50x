// CS50x assignment: count the Scrabble points for two words and determine the winner.  v2 passes 
// the letterValues array to the functions directly, vice passing a pointer.  This improvement was 
// suggested by Grok ai.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scoreLetter(char input, int letterValues[][2]);
int scoreWord(char *word, int length, int letterValues[][2]);


int letterValues[26][2] = {{'a',1}, {'b',3}, {'c',3}, {'d',2}, {'e',1}, \
                            {'f',4}, {'g',2}, {'h',4}, {'i',1}, {'j',8}, \
                            {'k',5}, {'l',1}, {'m',3}, {'n',1}, {'o',1}, \
                            {'p',3}, {'q',10}, {'r',1}, {'s',1}, {'t',1}, \
                            {'u',1}, {'v',4}, {'w',4},{'x',8}, {'y',4}, {'z',10}};

//int (*pLetterValues)[26][26] = &letterValues[26][26];
//int* pLetterValues[26][26] = &letterValues;
// int **pLetterValues;

//char letter = {'z'};
//char* pLetter = &letter; 

int main(void)
{
    /*for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            pLetterValues[i][j] = &letterValues[i][j];
        }    
    }
    */

    int scores[2];

    for (int p = 0; p < 2; p++)
        // accept user input
    {
        char word[20];  // source string, as single-element array of chars

        printf("Player %i, enter your word: ", p + 1);
        scanf("%s", word);
        int length = strlen(word);

        //printf("word: %s\n", word);
        for (int i = 0; i < length; i++)
            word[i] = tolower(word[i]);
        //printf("word: %s\n", word);

        //printf("Player %i: %s\n", p + 1, word);

        scores[p] = scoreWord(word, length, letterValues);
    }

    //printf("Player 1 score: %i\n", scores[0]);
    //printf("Player 2 score: %i\n", scores[1]);
      
    if (scores[0] == scores[1])
    {
        printf("It's a tie!\n");
    }

    else if (scores[0] > scores[1])
    {
        printf("Player 1 wins!\n");
    }
    
    else if (scores[0] < scores[1])
    {
        printf("Player 2 wins!\n");
    }
    return 0;
}


int scoreWord(char *word, int length, int letterValues[][2])
    // Add the letter scores for all letters in the word and return the word score to main().
{
    int totalScore = 0;

    for (int k = 0; k < length; k++)
    {
        //char inputLetter = word[k];
        //char* pInput = &inputLetter;
        totalScore += scoreLetter(word[k], letterValues);
    }
        printf("Total Word Score: %i\n", totalScore);
        return totalScore;
}


int scoreLetter(char input, int letterValues[][2])
    // receive one letter, search for that letter in letterValues, return score from letterValues
{
    if (!isalpha(input))
    {
        return 0;
    }

    //char inputLetter = *input;
    //printf("string: %c, ascii: %d\n", inputLetter, inputLetter);
    //printf("letter: %c,  ", inputLetter);
    input = tolower(input);
    //int score = value[(input - 'a')][1];
    //printf("letter score: %d\n", score);
    return letterValues[input - 'a'][1];

}