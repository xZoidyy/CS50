#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int grade(string text);

int main(void)
{
    string text = get_string("Text: ");

    int index = grade(text);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("After Grade 16\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;

}

int grade(string text)
{
    int textLenght = strlen(text);
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int L = 0;
    int S = 0;

    for (int i = 0; i < textLenght; i++)
    {

        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentences++;
            words++;
        }
        if (text[i] == 32)
        {
            words++;
        }
        if (text[i-1] == 46 || text[i-1] == 63 || text[i-1] == 33)
        {
            words--;
        }

    }

    L = (letters / (float) words) * 100;
    S = (sentences / (float) words) * 100;

    return round(0.0588*L - 0.296*S - 15.8);

}