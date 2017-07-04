#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // Retrieve name from user
    string name = get_string();
    
    
    char initials[] = {'!', '!', '!'};
    int initialCounter = 0;
    
    // loop through name
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        
        // Check for first initial if no spaces in beginning of string
        if (initials[0] == '!' && name[i] != ' ') {
            initials[0] = name[i];
            initialCounter++;
        }
        
        // loop through spaces in string
        while(name[i] == ' ' || !isalpha(initials[0])) {
            // "skips" the space
            i++;
            
            // Check if next character is not a space, and if so saves it as an initial
            if(isalpha(name[i])) {
                initials[initialCounter] = name[i];
                initialCounter++;
            }
        }
    }
    // reset counter to resuse in next loop
    initialCounter = 0;
    
    // only outputs characters that are not a !
    while(initialCounter < 3 && initials[initialCounter] != '!') {
        printf("%c", toupper(initials[initialCounter]));
        initialCounter++;
    }
    
    printf("\n");
    
    return 0;
}