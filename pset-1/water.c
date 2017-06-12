#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Constants
    float ozPerMin = 192;
    float ozInBottle = 16;
    
    printf("Minutes: ");
    int minutes = get_int();
    
    float totalOz = minutes * ozPerMin;
    float bottles = totalOz / ozInBottle;
    
    printf("Bottles: %.1f\n", bottles);
}