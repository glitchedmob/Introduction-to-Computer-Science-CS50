#include <stdio.h>
#include <cs50.h>

long long getCardNumber(void);
int findLongLength(long long num);
int findFirstDigits(long long num, int numOfDigits);
string findCardType(long long card);
bool validateCard(long long card);


int main(void) 
{
    long long cardNumber = getCardNumber();
    string cardType = findCardType(cardNumber);
    string empty = "";
    
    if(cardType != empty && validateCard(cardNumber)) {
        printf("%s\n", cardType);
    } else {
        printf("INVALID\n");
    }

    
    return 0;
}

long long getCardNumber(void)
{
    printf("Enter credit card number: ");
    long long card = get_long_long();
    
    while(card <= 0) {
        printf("Retry: ");
        card = get_long_long();
    }
    
    return card;
}

// Returns the number of digits in a given long long
int findLongLength(long long num)
{
    int length = 0;
    long long x = 1;
    
    while(x <= num) {
        length++;
        
        x = x * 10;
    }
    
    return length;
}

// returns the first digits to the left of a given long long. 
int findFirstDigits(long long num, int numOfDigits)
{
    int divisor = 10;
    
    while (numOfDigits > 1) {
        divisor *= 10;
        numOfDigits--;
    }

    
    while (num >= divisor) {
        num /= 10;
    }
    
    return num;
}

// Uses the length and first digits of a card number to classify it's type
string findCardType(long long card)
{
    string cardType = "";
    int cardNumLength = findLongLength(card);

    switch (cardNumLength) 
    {
        case 15:
            switch(findFirstDigits(card, 2)) 
            {
                case 34:
                case 37:
                    cardType = "AMEX";
                    break;
            }
            break;
        case 13:
        case 16:
            switch(findFirstDigits(card, 1))
            {
                case 4:
                    cardType = "VISA";
                    break;
            }
            
            switch(findFirstDigits(card, 2))
            {
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    cardType = "MASTERCARD";
                    break;
            }
            break;
        default:
            break;
    }
    
    return cardType;
}

// Implementation of Luhn’s algorithm. Takes a card number and returns true if valid, and flase if invaled.
    long long evenCard = card / 10;
    long long oddCard = card;
    int total = 0;
    for(int i = 0; i < (findLongLength(card) / 2) + 1; i++)
    {
        int evenDigit = evenCard % 10;
        int oddDigit = oddCard % 10;
        evenCard /= 100;
        oddCard /= 100;
        evenDigit *= 2;
        
        total += oddDigit;
        
        if(evenDigit / 10 > 0) {
            total += 1 + (evenDigit % 10);
        } else {
            total += evenDigit;
        }
    }
    
    if (total % 10 == 0) {
        return true;
    } else {
        return false;
    }
}
