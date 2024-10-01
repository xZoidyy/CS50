#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) // argc counting from 1
    {
        printf("Use: ./a.out key (positive integer)");
        return 1;
    }

    string key = argv[1];
    int keyInt = atoi(key); // Convert string key to int 

    if (keyInt <= 0) // Argument should be only positive integer
    {
        printf("Use: ./a.out key (positive integer)");
        return 1;        
    }

    string plain = get_string("Get plaintext: ");
    int lenght = strlen(plain);

    for (int i = 0; i < lenght; i++)
    {
        // I need to stay in letter number (ASCII) range
        if ((plain[i] >= 'A') && (plain[i] <= 'Z')) //Capital letters
        {
            if (plain[i] + keyInt <= 90)
            {
                plain[i] += keyInt;
            }
            else
            {
                plain[i] = 65 + (plain[i] + keyInt - 91);
            }
        }
        if ((plain[i] >= 'a') && (plain[i] <= 'z')) //Small letters
        {
            if (plain[i] + keyInt <= 122)
            {
                plain[i] += keyInt;
            }
            else
            {
                plain[i] = 97 + (plain[i] + keyInt - 123);
            }
            
        }
    }
    
    printf("Ciphertext:    %s\n", plain);
    return 0;
}