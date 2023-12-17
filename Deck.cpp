// Omeed Enshaie
// Class (CECS 325-02)
// Project Name (Prog 1 – Fibonacci Solitaire)
// Due Date (09/26/2023)
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program

#include <vector>
#include <string>
#include <iostream>
#include "Deck.h"
#include <stdlib.h>
#include <ctime>
#include "Card.h"

using namespace std;

Deck::Deck()
{
    // Construct the deck with card values
    for (char suit : {'H', 'D', 'C', 'S'})
    {
        for (char rank : {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'})
        {
            Card card(rank, suit);
            myDeck.push_back(card);
        }
    }
}

void Deck::newDeck()
{
    // reset the deck
    numofcards = 0;
    myDeck.clear();
    for (char suit : {'H', 'D', 'C', 'S'})
    {
        for (char rank : {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'})
        {
            Card card(rank, suit);
            myDeck.push_back(card);
        }
    }
}

Card Deck::deal()
{
    // show the last card of the deck
    Card r = myDeck.back();
    numofcards++;
    myDeck.pop_back();
    return r;
}

void Deck::shuffle()
{
    // shuffle deck
    srand(time(0));
    for (int i = 0; i < 51; i++)
    {
        int min = 0;
        int max = 51;
        int x = rand() % (max - min + 1) + min;

        // swap
        Card temp = myDeck[i];
        myDeck[i] = myDeck[x];
        myDeck[x] = temp;
    }
}

bool Deck::isEmpty()
{
    // if deck is empty,print true, else print false
    if (numofcards == 52)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Deck::show()
{
    // show all cards in 13 columns and 4 rows
    int col = 0;
    for (int i = 0; i < 52; ++i, ++col)
    {
        if (col == 13)
        {
            cout << endl;
            col = 0;
        }
        myDeck[i].show();
        if (i != 51)
        {
            cout << ", ";
        }
    }
    cout << endl;
}