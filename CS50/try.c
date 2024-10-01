#include <stdio.h>
#include <string.h>

int main(void)
{
    int count = 9;
    char text[20];

    sprintf(text, "%d", count);

    char *medium = ".jpeg";

    char *string1 = "00";
    char *string2 = strcat(text, medium);
    char *string = strcat(string1, string2);

    printf("%s", string);
}