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
    
    if(validateCard(cardNumber) && cardType != empty) {
        printf("%s\n", cardType);
    } else {
        printf("INVALID\n");
    }
    
    printf("%i\n", findFirstDigits(cardNumber, 3));
    
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

// Returns the number of digits in a give long long
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

int findFirstDigits(long long num, int numOfDigits)
{
    int divisor = 10;
    
    while (numOfDigits > 1) {
        divisor *= 10;
        numOfDigits--;
    }
    
    while (num >= divisor) {
        num /= divisor;
    }
    
    return num;
}

string findCardType(long long card)
{
    string cardType = "";
    
    if(card) {
        cardType = "AMEX";
    }
    
    return cardType;
}

bool validateCard(long long card)
{
    int cardNumLength = findLongLength(card);
    
    switch (cardNumLength) 
    {
        case 15:
            break;
        case 13:
            break;
        case 16:
            break;
        default:
            return false;
            break;
    }

    return true;
}
