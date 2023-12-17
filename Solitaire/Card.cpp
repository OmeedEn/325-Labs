// Omeed Enshaie
// Class (CECS 325-02)
// Project Name (Prog 1 – Fibonacci Solitaire)
// Due Date (09/26/2023)
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program
#include <iostream>
#include "Card.h"
using namespace std;

Card::Card()
{
    // Default constructor, initialize as Joker
    rank = '0';
    suit = 'J';
}

Card::Card(char r, char s)
{
    // Constructor to create a card with a specified rank and suit
    rank = r;
    suit = s;
}

int Card::getValue()
{
    // Return the point value of the card
    switch (rank)
    {
    case 'A':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'T':
    case 'J':
    case 'Q':
    case 'K':
        return 10;
    default:
        return 0;
    }
}

void Card::show()
{
    // Display the rank and suit of the card
    cout << rank << suit;
}
