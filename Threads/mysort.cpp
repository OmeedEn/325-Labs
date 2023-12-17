// Omeed Enshaie
// CECS 325-02
// Prog 5 Threads
// Due Date(10/31/2023)
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.

#include <fstream>
#include <iostream>
#include <string>
#include <thread>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    // Output array
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void sort(int threadNum, int arr[], int n)
{
    radixSort(arr, n);
}

void merge(int *left, int *right, int leftS, int rightS)
{
    int temp[leftS + rightS];
    int l = 0, r = 0, z = 0;
    while (l < leftS && r < rightS)
    {
        if (left[l] < right[r])
        {
            temp[z++] = left[l++];
        }
        else
        {
            temp[z++] = right[r++];
        }
    }
    if (l == leftS)
    {
        while (r < rightS)
            temp[z++] = right[r++];
    }
    else if (r == rightS)
    {
        while (l < leftS)
            temp[z++] = left[l++];
    }
    for (int i = 0; i < z; i++)
    {
        left[i] = temp[i];
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Please enter 1 parameter\n";
        cout << "   Parameter 1:    \n";
        exit(EXIT_SUCCESS);
    }

    string output = argv[1];

    ifstream fin;
    int *nums = new int[1000000];
    int thread_count = 8; // we want 8 threads
    fin.open(argv[1], ifstream::in);
    string curr;
    int i = 0;
    int n = 0;

    while (getline(fin, curr)) // inputs numbers from input file into the string curr, found online
    {
        nums[n] = stoi(curr); //convert from string to integers
        n++;//increment the int
        i++;
    }

    int div = n / thread_count;
    thread threads[8];

    for (int i = 0; i < thread_count; i++)
    {
        threads[i] = thread(sort, i, nums + i * div, div);
    }

    for (int i = 0; i < thread_count; i++)
    {
        threads[i].join();
    }

    while (div < n)
    {
        for (int i = 0; i < n; i += 2 * div)
        {
            merge(nums + i, nums + i + div, div, min(div, n - i - div));
        }
        div *= 2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << "\n";
    }
}
