#include <stdio.h>
#include <cs50.h> //get functions do not work because of ARM
//#include <math.h>

int main(void)
{   
    //printf("Hi\n");
    string answer = get_string("What is your name? ");
    //string answer = "Krystof";
    printf("Hello, %s\n", answer); //jako {}.format(asnwer)...... %i for integer (%c, %li, %f)
    return 0;
}