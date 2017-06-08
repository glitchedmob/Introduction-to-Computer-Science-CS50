#include <stdio.h>
#include <cs50.h>

int get_height(void);
void generatePyramid(int height);

int main(void)
{
    printf("Enter a height: ");
    int height = get_height();
    
    generatePyramid(height);
    
}

int get_height(void) 
{
    // constants
    int max = 23;
    int min = 4;
    int height = get_int();
    
    
    while (height < min || height > max) 
    {
        printf("Height must be between %i and %i: ", min, max);
        height = get_int();
    }
    
    return height;
}

void generatePyramid(int height) 
{
    // Generate each row
    for(int i = 0; i < height; i++)
    {
        // Generate each character for left side of pyramid
        for (int j = height; j > 0; j--)
        {
            
            if (i > (j - 2)) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        
        // Generate space in between each side of the pyramid
        printf("  ");
        
        // Generate each character for right side of pyramid
        for (int j = 0; j < height; j++)
        {
            if (i > (j - 1)) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        
        printf("\n");
    }
}