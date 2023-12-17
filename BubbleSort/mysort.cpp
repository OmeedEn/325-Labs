// Omeed Enshaie
// CECS 325-02
// Prog 3 Bubble Sort
// Due Date(10/10/2023)
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Please enter 2 parameters\n";
        cout << "    Parameter 1: input file";
        cout << "    Parameter 2: output file";
        exit(EXIT_SUCCESS);
    }

    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]:" << argv[i] << endl;
    }

    int counter = 0; // counter

    ifstream fin(argv[1]);
    int num;

    // count elements
    while (fin >> num)
    {
        counter++;
    }

    fin.close();
    fin.open(argv[1]);

    int *arr = new int[counter];

    for (int i = 0; i < counter; ++i)
    {
        fin >> arr[i];
    }

    cout << "\narray complete\n";
    fin.close();

    int numOfItems = counter;
    cout << "Starting Bubble Sort with " << numOfItems << " items" << endl;
    bubbleSort(arr, numOfItems);
    cout << "Ending Bubble Sort" << endl;

    // send output to mysort.out
    ofstream fout(argv[2], ios::out | ios::trunc);

    // print output in file
    for (int i = 0; i < counter; i++)
    {
        fout << arr[i] << endl;
    }

    fout.close();
    cout << "it has been sorted\n";
    return 0;
}
