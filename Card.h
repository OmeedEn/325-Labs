// Omeed Enshaie
// Class (CECS 325-02)
// Project Name (Prog 1 – Fibonacci Solitaire)
// Due Date (09/26/2023)
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program
#ifndef CARD_H
#define CARD_H

class Card
{
private:
    char rank; // Assuming rank is a character
    char suit; // Assuming suit is a character

public:
    // Default constructor
    Card();
    Card(char r, char s); // Parameterized constructor
    int getValue();       // Member function to get the card's value
    void show();          // Show the card
};

#endif
