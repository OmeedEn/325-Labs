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
#include "Card.h"

using namespace std;

bool isFibo(int n);

int main()
{
    int choice;
    Deck d;
    int numofgames = 0;
    do
    {
        cout << "Welcome to Fibonacci Solitaire!" << endl;
        cout << "Menu:" << endl;
        cout << "1) Create New Deck" << endl;
        cout << "2) Display Deck" << endl;
        cout << "3) Shuffle Deck" << endl;
        cout << "4) Play Fibo Solitaire" << endl;
        cout << "5) Win Fibo Solitaire" << endl;
        cout << "6) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Create New Deck" << endl;
            d.newDeck();
            break;
        }

        case 2:
        {
            cout << "Display Deck" << endl;
            d.show();
            break;
        }

        case 3:
        {
            cout << "Shuffle Deck" << endl;
            d.shuffle();
            break;
        }

        case 4:
        {
            cout << "Play Fibo Solitaire" << endl;
            ++numofgames;
            d.newDeck();
            d.shuffle();

            int sum = 0;
            int piles = 1;

            for (int i = 0; i < 52 && d.isEmpty() == false; i++)
            {
                Card deal = d.deal();
                int val = deal.getValue();
                sum += val;
                deal.show();
                cout << ", ";

                if (i == 51)
                {
                    if (isFibo(sum))
                    {
                        cout << "Fibo: " << sum << endl
                             << "Winner in " << piles << " piles!\n";
                    }
                    else
                    {
                        cout << "Last pile NOT fibo: " << sum << endl
                             << "Loser in " << piles << " piles!\n";
                    }
                }
                else if (isFibo(sum))
                {
                    cout << "Fibo: " << sum << endl;
                    sum = 0;
                    piles++;
                }
            }
            break;
        }

        case 5:
        {
            cout << "Win Fibo Solitaire" << endl;
            bool win = false;
            while (win == false)
            {
                d.newDeck();
                d.shuffle();
                numofgames++;
                int sum = 0;
                int piles = 1;

                for (int i = 0; i < 52 && d.isEmpty() == false; i++)
                {
                    Card deal = d.deal();
                    int val = deal.getValue();
                    sum += val;
                    deal.show();
                    cout << ", ";

                    if (i == 51)
                    {
                        if (isFibo(sum))
                        {
                            cout << "Fibo: " << sum << endl
                                 << "Winner in " << piles << " piles!" << endl;
                            cout << endl
                                 << "Games Played: " << numofgames << endl;
                            win = true;
                        }
                        else
                        {
                            cout << "Last pile NOT fibo: " << sum << endl
                                 << "Loser in " << piles << " piles!\n"
                                 << endl;
                        }
                    }
                    else if (isFibo(sum))
                    {
                        cout << "Fibo: " << sum << endl;
                        sum = 0;
                        piles++;
                    }
                }
            }
            break;
        }
        case 6:
        {
            cout << "Exit" << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    } while (choice != 6);

    return 0;
}

bool isFibo(int n) // if its a fibo sequence
{
    if (n == 0 || n == 1)
        return true; // true is these outputs

    int a = 0;
    int b = 1;
    while (b < n)
    {
        int temp = b;
        b = a + b; // add last two nums together
        a = temp;
    }

    return b == n; // return boolean
}
