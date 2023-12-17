// Omeed Enshaie
// CECS 325-02
// Prog 6 ThreeN
// Due Date(11/16/2023)
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

void checkNum(int maxValue, int n, int &even, int &odd, int &maxNum, int &steps);
int overf, overd = 0;

int main(int argc, char *argv[])
{

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            int n;
            stringstream ss(argv[i]);
            ss >> n;

            int even = 0, odd = 0, steps = 0;
            int maxNum = n;
            int maxValue = INT_MAX;

            cout << "Solving 3n + 1 - starting number: " << n << endl;
            try
            {
                checkNum(maxValue, n, even, odd, maxNum, steps);
            }
            catch (int err)
            {
                cout << "->(###overflow###)";
                cout << "\n"
                     << "Overflow detected for n:" << overd << endl;
                cout << "3n + 1:" << overf << endl;
                cout << "something broke dude" << endl;
                cout << "integer overflow" << endl;
            }

            int start = n;
            cout << "\n";
            cout << "start: " << start << endl;
            cout << "steps: " << steps << endl;
            cout << "max: " << maxNum << endl;
            cout << "odds: " << odd << endl;
            cout << "evens: " << even << endl;
            cout << "\n";
        }
    }
    else
    {
        cout << "Enter a positive integer: ";
        int startNumber;
        cin >> startNumber;

        int n = startNumber;
        int even = 0, odd = 0, steps = 0;
        int maxNum = n;
        int maxValue = INT_MAX;

        try
        {
            cout << "Solving 3n + 1 - starting number: " << n << endl;
            checkNum(maxValue, n, even, odd, maxNum, steps);

            cout << "\n";
            cout << "start: " << startNumber << endl;
            cout << "steps: " << steps << endl;
            cout << "max: " << maxNum << endl;
            cout << "odds: " << odd << endl;
            cout << "evens: " << even << endl;
            cout << "\n";
        }
        catch (int err)
        {
            cout << "->(###overflow###)";
            cout << "\n"
                 << "Overflow detected for n:" << overd << endl;
            cout << "3n + 1:" << overf << endl;
            cout << "something broke dude" << endl;
            cout << "integer overflow" << endl;
        }
    }

    return 0;
}

void checkNum(int maxValue, int n, int &even, int &odd, int &maxNum, int &steps)
{
    cout << "->(" << n << ")";
    if (n > maxNum)
    {
        maxNum = n;
    }

    if (n == 1)
    {
        return;
    }

    else if (n % 2 == 0)
    {
        steps++;
        even++;
        checkNum(maxValue, n / 2, even, odd, maxNum, steps);
    }
    else
    {
        steps++;
        if (3 * n + 1 < 0)
        {
            overd = n;
            overf = 3 * n + 1;
            throw 0; // int err
        }

        odd++;
        checkNum(maxValue, 3 * n + 1, even, odd, maxNum, steps);
    }
}
