// Omeed Enshaie
// Class (CECS 325-02)
// Project Name (Prog 1 – Fibonacci Solitaire)
// Due Date (09/26/2023)
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program

#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

using namespace std;
class Deck
{

private:
    int numofcards = 0;
    int col = 0;
    // vector<string> cards{"2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH",
    //                      "JH", "QH", "KH", "AH", "2C", "3C", "4C", "5C", "6C",
    //                      "7C", "8C", "9C", "TC", "JC", "QC", "KC", "AC", "2S",
    //                      "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS",
    //                      "QS", "KS", "AS", "2D", "3D", "4D", "5D", "6D", "7D",
    //                      "8D", "9D", "TD", "JD", "QD", "KD", "AD"};

    // vector<string> deckReset{"2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH",
    //                          "JH", "QH", "KH", "AH", "2C", "3C", "4C", "5C", "6C",
    //                          "7C", "8C", "9C", "TC", "JC", "QC", "KC", "AC", "2S",
    //                          "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS",
    //                          "QS", "KS", "AS", "2D", "3D", "4D", "5D", "6D", "7D",
    //                          "8D", "9D", "TD", "JD", "QD", "KD", "AD"};
    vector<Card> myDeck;

    // Use std:: prefix for vector and string
public:
    Deck();
    void newDeck();
    Card deal();
    void shuffle();
    bool isEmpty();
    void show();
};

#endif