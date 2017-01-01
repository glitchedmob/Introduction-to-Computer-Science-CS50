#include <stdio.h>
#include <cs50.h>

int getHeight(void);

int main(void) {
    
    int height = getHeight();
    
    // Generate lines
    for (int i = 1; i <= height; i++) {
        
        // Generate the characters on each line
        for (int j = height + 1; j > 0; j--) {
            if (j < (i + 2)) {
                printf("#");   
            }
            else {
                printf(" ");
            }
        }
        
        // Add a newline character at the end of each line
        printf("\n");
    }
    
}

int getHeight(void) {
    int height;
    
    // loop until a int between 1 and 22 is entered
    do {
        printf("height: ");
        height = GetInt(); 
    } while (height <= 0 || height > 23);
    
    return height;
}
