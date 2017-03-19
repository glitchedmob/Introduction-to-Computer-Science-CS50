/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

const int MAXIMUM = 65536;

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n) {
    // Return false if n is non-positive
    if (value < 0) {
        return false;   
    }
    
    // Set end and start of array
    int end = n - 1;
    int start = 0;
    
    // Continue searching until the length of section to check is less than 0
    while(n > 0) {
        // Calculate the middle of the array
        int middle = (end + start) / 2 + start;
        
        // Check the middle for the value we are looking for
        if (values[middle] == value) {
            return true;
        }
        // Else if middle is greater than our value search the left half of array
        else if (values[middle] > value) {
            end = middle;
        }
        // Else if middle is less than our value search the right half of the array
        else if (values[middle] < value) {
            start = middle;
        }
        
        // Calculate the length of the section of the array to check
        n = end - start + 1;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Create an empty array of zeros that is 65536 elements long
    int tempArray[65536] = {0};
    
    // Loops through array to sort
    for (int i = 0; i < n; i++) {
        // Incriments the value in the empty array by one where the 
        // value of the array to sort is the same as the empty array's index 
        tempArray[values[i]] += 1;
    }
    
    // Initialize a counter variable
    int counter = 0;
    
    // Loop through temp array
    for (int k = 0; k < MAXIMUM; k++) {
        // Loop through the value at temparray[k]
        while (tempArray[k] > 0) {
            // Set the value in the original array at the position of the counter to be k
            values[counter] = k;
            
            counter++;
            tempArray[k]--;
        }
    }
    

    return;
}
