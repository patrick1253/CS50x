#include <stdio.h>

void pyramid_build(int size);
int pyramid_size(void);
void print_row(int size);

int main(void) 
{
    int size = pyramid_size();
    pyramid_build(size);
}
        
void pyramid_build(int size)
{
    //pyramid_size(void);
    for (int row = 0; row < size; row++)
    { 
        print_row(row);
        //row--;
    }
    //printf("\n");
    
}

void print_row(int row)
{
    //int i;
    for (int i = row; i > 0; i--)
    {
        printf("*");
    }
    for (int j = 0; j < row; j++)
    {
        printf("#");
    }
    printf("\n");

}



int pyramid_size(void)
{
    //int size;
    //do
    //{    
    //int pyramid_size = get_int("height of the pyramid?\n");
    //}
    int size = 6;
    return size;
}