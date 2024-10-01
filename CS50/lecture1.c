#include <stdio.h>
#include <cs50.h>

void triangle(int i);

int main(void)
{
    // initializing
    int n;

    // get number of width and high
    do
    {
        n = get_int("Get number between 1 - 8: ");
    } while(n>8 || n<1);

    // make triangle
    for(int i=0; i < n; i++) // row
    {
        // FIRST TRIANGLE
        for(int space = i; space < (n-1); space++) // making space
            {
                printf(" ");
            }
        triangle(i);

        // SPACE BETWEEN TRIANGLES
        printf("  ");

        // SECOND TRIANGLE
        triangle(i);

        printf("\n"); //next row
    }
}

void triangle(int i)
{
    for(int k = i; k>=0; k--) // column
        {          
            printf("#"); // making #
        }
}