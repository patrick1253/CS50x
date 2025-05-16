#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = str get_string("What is your name?\n");
    printf("Hello, my name is %s\n", name);
}