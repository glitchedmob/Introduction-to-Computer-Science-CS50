#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check for correct number of command line arguments
    if (argc != 2) {
        printf("Error! Incorrect number of command line arguments\n");
        return 1;
    }
    else 
    {
        // Iterate through the characters in the second command line argument
        // and output an error if any of them are not letters
        for (int i = 0, n = strlen(argv[1]); i < n; i++) 
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Error! Key must only contain letters.\n");
                return 1;
            }
        }
    }
    
    string k = argv[1];
    
    // Get plaintext from the user
    printf("plaintext: ");
    string p = get_string();
    
    
    // Begin output of the ciphertext
    printf("ciphertext: ");
    
    // Iterate through each of the characters in the plaintext
    for (int i = 0, n = strlen(p), j = 0; i < n; i ++)
    {
        // Check to see if we have reached the end of the key
        // If so then we wrap around
        if (j == strlen(k))
        {
            j = 0;
        }
        
        // Calculate the key to encrypt the current letter
        int cipher = toupper(k[j]) - 'A';
        
        if (isupper(p[i]))
        {
            // Encrypt character and print it
            printf( "%c", 'A' + (p[i] - 'A' + cipher) % 26);
            // If we encyrpted a character then incremient j to use next character from key
            j++;
        }
        else if (islower(p[i]))
        {
            // Encrypt character and print it
            printf( "%c", 'a' + (p[i] - 'a' + cipher) % 26);
            // If we encyrpted a character then incremient j to use next character from key
            j++;
        }
        else
        {
            // If i'th character is neither lowercase nor uppercase print it out unencrypted
            printf("%c", p[i]);
        }
    }
    
    printf("\n");
    return 0;
}