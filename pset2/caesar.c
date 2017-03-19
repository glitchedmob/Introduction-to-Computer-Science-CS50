#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define ALPHABET_LENGTH 26

int main(int argc, string argv[]) 
{
    // Check that only 1 extra command line argument was entered
    if(argc != 2) {
        printf("Error! You must enter 1 command line argument\n");
        return 1;
    }
    
    // Get user input
    printf("plaintext: ");
    string plain_text = get_string();
    
    // Store key from command line arguments 
    // This statement also accounts for keys over the number 26
    int key = atoi(argv[1]) % ALPHABET_LENGTH;
    
    // Begin output
    printf("ciphertext: ");
    
    // Calculate the values needed to check wether the encyrptor will
    // need to "wrap around" from Z to A or z to a
    int upper_check = ALPHABET_LENGTH + 'A' - 1;
    int lower_check = ALPHABET_LENGTH + 'a' - 1;
    
    // Iterate through each character in plain_text
    int pt_length = strlen(plain_text);
    for (int i = 0; i < pt_length; i++) 
    {
        // Add the key to the current character for use later
        int pt_with_key = plain_text[i] + key;
        
        // Follow this branch if the current chracter is a capital
        if ((plain_text[i] >= 'A' && plain_text[i] <= 'Z')) 
        {
            if(pt_with_key > upper_check) {
                // Print out the ecrypted character after wrapping from Z to A
                printf("%c", (plain_text[i] - ALPHABET_LENGTH) + key);
            } else {
                // Print out encrypted character
                printf("%c", pt_with_key);   
            }
        }
        // Follow this branch if the current character is lower case
        else if (plain_text[i] >= 'a' && plain_text[i] <= 'z') 
        {
            if(pt_with_key > lower_check) {
                // Print out the ecrypted character after wrapping from z to a
                printf("%c", (plain_text[i] - ALPHABET_LENGTH) + key);
            } else {
                // Print out the encrypted character
                printf("%c", pt_with_key);   
            }
        }
        else 
        {
            // If the current character is not a letter just print it
            printf("%c", plain_text[i]);    
        }
    }
    
    // Print newline before exiting
    printf("\n");
    return 0;
}