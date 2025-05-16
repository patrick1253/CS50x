#include <stdio.h>
//#include <cs50.h>

int pyramid_size(void);
void build_pyramid(int);

int main(void)
{
    int size = pyramid_size();
    build_pyramid(size);
}

void build_pyramid(int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size-row; col++)
        {
            printf("  ");
        }
        for (int col_hash = 0; col_hash <= row; col_hash++)
        {
            printf("# ");
        }
        printf("\n");
    }
}

int pyramid_size(void)
{
    //int size;
    //do
    //{    
    //int pyramid_size = get_int("Height of the pyramid?\n");
    //}
    int size = 6;
    return size;
}
