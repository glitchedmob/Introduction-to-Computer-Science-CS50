#include <stdio.h>
#include <cs50.h>

int main(void) {
    
    // Get the user's input
    printf("Minutes: ");
    int minutes = GetInt();
    
    // Calculate the number of water bottles used during shower
    int bottles = (minutes * 192) / 16;
    
    //ouput results to the user
    printf("Bottles: %i\n", bottles);
}