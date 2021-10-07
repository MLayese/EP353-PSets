#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //counting cmd-line arg

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, s = strlen(argv[1]); i < s; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else
            {
                printf("");
            }
        }
    }

    int num = atoi(argv[1]);

    //getting Plaintext


    string plaintext;

    plaintext = get_string("Insert Plaintext: ");

    string cyphertext = plaintext;

    int len = strlen(plaintext);

    //iterating over the plaintext en ciphering it

    for (int i = 0; i < len; i++)
    {
        //Only works on alphabetical stuff, everything else is ignored
        if (isalpha(cyphertext[i]))
        {
            //iterating over each character
            for (int p = 0; p < num; p++)
            {
                cyphertext[i]++;

                //if its going past z, then start at a and add the remaining num

                if (cyphertext[i] > 'z')
                {
                    cyphertext[i] = cyphertext[i] - 'z' + 96;
                }
                else if (cyphertext[i] > 'Z' && cyphertext[i] < 'a')
                {
                    cyphertext[i] = cyphertext[i] - 'Z' + 64;
                }
                else
                {
                    printf("");
                }
            }
        }

        else
        {
            printf("");
        }
    }

    printf("ciphertext:  %s\n", cyphertext);
}
