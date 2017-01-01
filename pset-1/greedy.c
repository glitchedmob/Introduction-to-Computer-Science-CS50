#include <stdio.h>
#include <cs50.h>

float getChange(void);

int main(void) {
    
    float change = getChange();
    int total_pennies = change * 100;
    int total_bills = 0;
    int total_coins = 0;
    
     // Calculate the number of $100 bills, add that to total_bills, and recalculate the remainder of pennies
    total_bills = total_bills + (total_pennies / 100000);
    total_pennies = total_pennies % 100000;
    
    // Calculate the number of $50 bills, add that to total_bills, and recalculate the remainder of pennies
    total_bills = total_bills + (total_pennies / 50000);
    total_pennies = total_pennies % 50000;
    
    // Calculate the number of $20 bills, add that to total_bills, and recalculate the remainder of pennies
    total_bills = total_bills + (total_pennies / 20000);
    total_pennies = total_pennies % 20000;
    
    // Calculate the number of $10 bills, add that to total_bills, and recalculate the remainder of pennies
    total_bills = total_bills + (total_pennies / 1000);
    total_pennies = total_pennies % 1000;
    
    // Calculate the number of $5 bills, add that to total_bills, and recalculate the remainder of pennies
    total_bills = total_bills + (total_pennies / 500);
    total_pennies = total_pennies % 500;
    
    // Calculate the number of $1 bills, add that to total_bills, and recalculate the remainder of pennies
    total_bills = total_bills + (total_pennies / 100);
    total_pennies = total_pennies % 100;
    
    // Calculate the number of quarters, add that to total_coins, and recalculate the remainder of pennies
    total_coins = total_coins + (total_pennies / 25);
    total_pennies = total_pennies % 25;
    
    // Calculate the number of dimes, add that to total_coins, and recalculate the remainder of pennies
    total_coins = total_coins + (total_pennies / 10);
    total_pennies = total_pennies % 10;
    
    // Calculate the number of nickels, add that to total_coins, and recalculate the remainder of pennies
    total_coins = total_coins + (total_pennies / 5);
    total_pennies = total_pennies % 5;
    
    // Add the remaining number of pennies to total_coins
    total_coins = total_coins + total_pennies;
    
    printf("%i bills and %i coins\n", total_bills, total_coins);
    
}

float getChange(void) {
    float change;
    
    // Get a nonnegative floating point value from the user
    do {
        printf("Change: $");
        change = GetFloat(); 
    } while (change <= 0);
    
    return change;
}