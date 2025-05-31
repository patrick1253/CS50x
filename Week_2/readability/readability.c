// CS50x assignment: calculate the approximate grade level needed to comprehend a specified text.

// Suggested improvement by Grok ai:  eliminate separate countSentences function and use '.', '?', and
// '!' instead.  Also suggested adding "in_word" boolean to account for end of word and end of string.

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// test text:
char text1[] = {"One fish. Two fish. Red fish. Blue fish."}; // (Below Grade 1)
char text2[] = {"Would you like them here or there? I would not like them here or there. I would not like them anywhere."}; //(Grade 2)
char text3[] = {"Congratulations! Today is your day. You're off to Great Places! You're off and away!"};  //(Grade 3)
char text4[] = {"Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard."}; //(Grade 5)
char text5[] = {"In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since."};  // (Grade 7)
char text6[] = {"Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, \"and what is the use of a book,\" thought Alice \"without pictures or conversation?\""}; //(Grade 8)
char text7[] = {"When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh."}; //(Grade 8)
char text8[] = {"There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy."}; // (Grade 9)
char text9[] = {"It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him."}; //(Grade 10)
char text10[] = {"A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains."}; // (Grade 16+)

//char period = {'.'};

char *pText = text10;

int numChars = 0;
int numWords = 0;
int numSentences = 0;

int colemanLiauIndex(int letters, int words, int sentences);
void countChars(char *string);
void countSentences(char punct);

int main(void)
{
    int length = strlen(pText);
    //printf("%i\n", length);
    countChars(pText);
    //countSentences(pText);

    printf("numChars: %i\n", numChars);
    printf("numWords: %i\n", numWords);
    printf("numSentences: %i\n", numSentences);

    printf("Grade %d\n", colemanLiauIndex(numChars, numWords, numSentences));

    return 0;
}

int colemanLiauIndex(int letters, int words, int sentences)
    // Coleman-Liau index = (0.058 * L) - (0.296 * S) - 15.8
{
    // avoid division by zero error
    if (words == 0)
    {
        return 0;
    }

    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;
    float CL = (0.058 * L) - (0.296 * S) - 15.8;
    // CL = round(CL);
    return (int)round(CL);
}


/*
void countSentences(char punct)
{   
    char eol[] = {'.', '?', '!'};
    // char str_eol[] = {".", "?", "!"};

    // printf("\npunct: %c\n", punct);

    for (int k = 0; k < 3; k++)
    {
        char end = eol[k];

        //printf("end: %c\n", end);
        //printf("%s\n", strcmp(&punct, &eol[k]) == 0);

        //if (strcmp(str_eol[k], &punct) == 0)
        //{
            //printf("strcmp working!\n");
        //}
        if (end == punct)
        {
            // printf("True\n");
            numSentences++;
        }
    }
}
*/


void countChars(char *string)
{
    int length = strlen(string);
    bool in_word = false;

    // printf("%i\n", length);
    // printf("char: %c\n", string[1]);

    for (int j = 0; j < length; j++)
    {
        if (isalpha(string[j])) 
        {
            printf("%c", string[j]);    
            numChars++;
            in_word = true;
        }
        else if (isspace(string[j]))
        {
            if (in_word)
            {
                printf("%c", string[j]);
                numWords++;
                in_word = false;
            }
        }
        else if (string[j] == '.' || string[j] == '?' || string[j] == '!')
        {
            if (in_word)
            {
                numWords++;
                in_word = false;
                //countSentences(string[j]);
            }
            numSentences++;
        }
    }
    puts("\n");
    //printf("some kind of problem in countChars\n");
    //return 0;
    if (in_word)
    {
        numWords++;
    }
    
}


// # words == (# spaces + 1)

//1. Set var for # chars, # words, # sentences.  Increment #chars until reach '\0', then increment #words.
//2. Repeat until reach end of sentence (??) then increment #sentences.
//3. Compute C-L index and return result.