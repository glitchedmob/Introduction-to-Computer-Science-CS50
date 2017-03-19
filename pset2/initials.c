#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void) {
    
    // Get a name from the user
    string name = get_string();
    
    if (name != NULL) 
    {
        // If the first character is not a space then it is the first intial
        if(name[0] != ' ') 
        {
           printf("%c", toupper(name[0])); 
        }
        
        // Flag to determine if next character is an initial
        bool grab_initial = false;
        
        // Iterate through all of the characters in the input
        int name_length = strlen(name);
        for(int i = 0; i < name_length; i++) 
        {
            if (name[i] == ' ') 
            {
                // Update flag to grab next character
                grab_initial = true;
            } 
            else if (grab_initial) 
            {
                // Print out initial and update flag
                printf("%c", toupper(name[i]));
                grab_initial = false;
            }
        }
        printf("\n");
    }
}