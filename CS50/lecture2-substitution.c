#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    int lenght = strlen(key);

    if (argc != 2 || lenght != 26) // argc counting from 1
    {
        printf("Use: ./a.out key. Key must contain 26 characters.");
        return 1;
    }

    int keyInt = atoi(key); // Convert string key to int 

    if (keyInt != 0) // Argument should be only string (keyInt = 0). "26x0" cannot figure out. 
    {
        printf("Use: ./a.out key. Key must contain 26 characters.");
        return 1;        
    }

    // Make alphabet array (capital letters)
    char Balphabet[lenght-1];
    char Salphabet[lenght-1];

    for (int i = 0; i < lenght; i++)
    {
        Balphabet[i] = (char) (65 + i); // capital letters
        Salphabet[i] = (char) (97 + i); // small letters
    }

    // Get plain text
    string plain = get_string("Get plaintext: ");
    int lenghtPlain = strlen(plain);

    for (int j = 0; j < lenghtPlain; j++)
    {

        for (int k = 0; k < lenght; k++)
        {
            if (plain[j] >= 65 && plain[j] <= 90) // Capital letters
            {
                if (plain[j] == Balphabet[k])
                {
                    plain[j] = toupper(key[k]); // Change capital letters
                    break;
                }
            }
            if (plain[j] >= 97 && plain[j] <= 122) // Small letters
            {
                if (plain[j] == Salphabet[k])
                {
                    plain[j] = tolower(key[k]); // Change small letters
                    break;
                }
            }
        }
        
    }

    printf("Ciphertext:    %s\n", plain);

    return 0;
}

