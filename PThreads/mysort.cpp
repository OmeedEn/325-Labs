#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
using namespace std;

struct sortStruct
{
    int *pstart;
    int size;
};

void bubbleSort(int numbers[], int x)
{
    bool swap;
    for (int i = 0; i < x - 1; i++)
    {
        swap = false;

        for (int c = 0; c < x - i - 1; c++)
        {
            if (numbers[c] > numbers[c + 1])
            {
                int temp = numbers[c];
                numbers[c] = numbers[c + 1];
                numbers[c + 1] = temp;
                swap = true;
            }
        }
        if (!swap)
        {
            break;
        }
    }
}
void *printHelper(void *ptr)
{
    sortStruct *arg = (sortStruct *)ptr;
    bool swapped;
    for (int i = 0; i < arg->size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < arg->size - i - 1; j++)
        {
            if (arg->pstart[j] > arg->pstart[j + 1])
            {
                swap(arg->pstart[j], arg->pstart[j + 1]);
                swapped = true;
            }
        }
    }
}

void merge(int *left, int *right, int leftsize, int rightsize)
{
    int temp[leftsize + rightsize];
    int l = 0, r = 0, z = 0;
    while (1 < leftsize && r < rightsize)
    {
        if (left[1] < right[r])
        {
            temp[z++] = left[l++];
        }
        else
        {
            temp[z++] = right[r++];
        }
    }
    if (l == leftsize)
    {
        while (r < rightsize)
            temp[z++] = right[r++];
    }
    else if (r == rightsize)
    {
        while (1 < leftsize)
            temp[z++] = left[l++];
    }
    for (int i = 0; i < z; i++)
    {
        left[i] = temp[i];
    }
}
/* print the elements
void print(int p, int size)
{
    for (int i = 0; i < size; i++)
        cout <<(p + i) << ",";
}

// print the structures
void *printHelper(void*ptr)
{
    P arg = (P)ptr;
    cout << "Print start:" << *(arg->pstart) << " count:"
         << arg->size << " wait:" << arg->wait << endl;
    sleep(arg->wait);
    print(arg->pstart, arg->size);
    cout << endl;
    return NULL;
}*/
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
    //  if (argc < 3)
    // {
    //     cout << "Please enter 2 parameters\n";
    //     cout << "    Parameter 1: input file";
    //     cout << "    Parameter 2: output file";
    //     exit(EXIT_SUCCESS);
    // }
    // for (int i = 0; i < argc; i++)
    // {
    //     cout << "argv[" << i << "]:" << argv[i] << "\n";
    // }
    // string input = argv[1];
    //     string output = argv[2];

    // ifstream fin;
    int sortedNums[1000000];
    // fin.open(input, ifstream::in);
    // string currentNum;
    // int n = 0;
    // int x = 0;
    // while (getline(fin, currentNum)){

    //     sortedNums[x] = stoi(currentNum);
    //     x++;
    //     n++;
    // }

    const int maxi = 1000000; // maximum
    sortStruct s1;
    s1.pstart = sortedNums;
    s1.size = 100000;

    sortStruct s2;
    s2.pstart = &(sortedNums[100000]);
    s2.size = 100000;

    sortStruct s3;
    s3.pstart = sortedNums + 200000;
    s3.size = 100000;

    sortStruct s4;
    s4.pstart = sortedNums + 300000;
    s4.size = 100000;

    sortStruct s5;
    s5.pstart = sortedNums + 400000;
    s5.size = 100000;

    sortStruct s6;
    s6.pstart = sortedNums + 500000;
    s6.size = 100000;

    sortStruct s7;
    s7.pstart = sortedNums + 600000;
    s7.size = 100000;

    sortStruct s8;
    s8.pstart = sortedNums + 700000;
    s8.size = 100000;

    sortStruct s9;
    s9.pstart = sortedNums + 800000;
    s9.size = 100000;

    sortStruct s10;
    s10.pstart = sortedNums + 900000;
    s10.size = 100000;

    int div = maxi / 10;
    int nums[maxi];
    int *c1 = nums;
    int *c2 = nums + 100000; // segment 10 times of a 100,000 each
    int *c3 = nums + 200000;
    int *c4 = nums + 300000;
    int *c5 = nums + 400000;
    int *c6 = nums + 500000;
    int *c7 = nums + 600000;
    int *c8 = nums + 700000;
    int *c9 = nums + 800000;
    int *c10 = nums + 900000;

    pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;
    int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7, iret8, iret9;
    /* Create independent threads each of which will execute function */
    iret0 = pthread_create(&thread0, NULL, printHelper, (void *)&s1);
    iret1 = pthread_create(&thread1, NULL, printHelper, (void *)&s2);
    iret2 = pthread_create(&thread2, NULL, printHelper, (void *)&s3);
    iret3 = pthread_create(&thread3, NULL, printHelper, (void *)&s4);
    iret4 = pthread_create(&thread4, NULL, printHelper, (void *)&s5);
    iret5 = pthread_create(&thread5, NULL, printHelper, (void *)&s6);
    iret6 = pthread_create(&thread6, NULL, printHelper, (void *)&s7);
    iret7 = pthread_create(&thread7, NULL, printHelper, (void *)&s8);
    iret8 = pthread_create(&thread8, NULL, printHelper, (void *)&s9);
    iret9 = pthread_create(&thread9, NULL, printHelper, (void *)&s10);

    bubbleSort(c1, div); // bubble sort each portion of the numbers
    bubbleSort(c2, div);
    bubbleSort(c3, div);
    bubbleSort(c4, div);
    bubbleSort(c5, div);
    bubbleSort(c6, div);
    bubbleSort(c7, div);
    bubbleSort(c8, div);
    bubbleSort(c9, div);
    bubbleSort(c10, div);

    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    pthread_join(thread7, NULL);
    pthread_join(thread8, NULL);
    pthread_join(thread9, NULL);

    merge(s1.pstart, s2.pstart, s1.size, s2.size);
    merge(s3.pstart, s4.pstart, s3.size, s4.size);
    merge(s5.pstart, s6.pstart, s5.size, s6.size);
    merge(s7.pstart, s8.pstart, s7.size, s7.size);
    merge(s9.pstart, s10.pstart, s9.size, s10.size);
    merge(s1.pstart, s3.pstart, s1.size * 2, s3.size * 2);
    merge(s5.pstart, s7.pstart, s1.size * 2, s7.size * 2);
    merge(s1.pstart, s5.pstart, s1.size * 4, s5.size * 4);
    merge(s1.pstart, s9.pstart, s1.size * 8, s9.size * 2);

    /*ofstream fout;
    fout.open(output, ios::out | ios::trunc);
    for (int i = 0; i < n; i++)
    {
        fout << sortedNums[i] << endl;
    }
    */
    // send output to mysort.out
    ofstream fout(argv[2], ios::out | ios::trunc);

    // print output in file
    for (int i = 0; i < counter; i++)
    {
        fout << arr[i] << endl;
    }
    fout.close();
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <thread>
// #include <iostream>
// #include <fstream>
// #include <unistd.h>
// using namespace std;

// typedef struct pThread
// {
//     int *pstart;
//     int size;
//     int wait;
// } P;

// void bubbleSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 // swap
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

// // print the elements
// void print(int *p, int size)
// {
//     for (int i = 0; i < size; i++)
//         cout << *(p + i) << ",";
// }

// // print the structures
// void *printHelper(void *ptr)
// {
//     P *arg = (P *)ptr;
//     cout << "Print start:" << *(arg->pstart) << " count:"
//          << arg->size << " wait:" << arg->wait << endl;
//     print(arg->pstart, arg->size);
//     cout << endl;
//     return NULL;
// }

// void merge(int *left, int *right, int leftsize, int rightsize)
// {
//     int temp[leftsize + rightsize];
//     int l = 0, r = 0, z = 0;
//     while (l < leftsize && r < rightsize)
//     {
//         if (left[l] < right[r])
//         {
//             temp[z++] = left[l++];
//         }
//         else
//         {
//             temp[z++] = right[r++];
//         }
//     }
//     // remaining elements from left and right arrays
//     while (l < leftsize)
//     {
//         temp[z++] = left[l++];
//     }
//     while (r < rightsize)
//     {
//         temp[z++] = right[r++];
//     }
//     // elements from temp back to left and right arrays
//     for (int i = 0; i < z; i++)
//     {
//         left[i] = temp[i];
//     }
// }

// int main(int argc, char *argv[])
// {
//     if (argc < 3)
//     {
//         cout << "Please enter 2 parameters\n";
//         cout << "    Parameter 1: input file";
//         cout << "    Parameter 2: output file";
//         exit(EXIT_SUCCESS);
//     }
//     for (int i = 0; i < argc; i++)
//     {
//         cout << "argv[" << i << "]:" << argv[i] << endl;
//     }
//     int counter = 0; // counter

//     ifstream fin(argv[1]);
//     int num;
//     // count elements
//     while (fin >> num)
//     {
//         counter++;
//     }
//     fin.close();
//     fin.open(argv[1]);
//     int *arr = new int[counter];
//     for (int i = 0; i < counter; ++i)
//     {
//         fin >> arr[i];
//     }
//     cout << "\narray complete\n";
//     fin.close();

//     const int maxi = 1000000; // maximum

//     P s1;
//     s1.pstart = arr;
//     s1.size = 100000;
//     s1.wait = 10;

//     P s2;
//     s2.pstart = arr + 100000;
//     s2.size = 100000;
//     s2.wait = 9;

//     P s3;
//     s3.pstart = arr + 200000;
//     s3.size = 100000;
//     s3.wait = 8;

//     P s4;
//     s4.pstart = arr + 300000;
//     s4.size = 100000;
//     s4.wait = 7;

//     P s5;
//     s5.pstart = arr + 400000;
//     s5.size = 100000;
//     s5.wait = 6;

//     P s6;
//     s6.pstart = arr + 500000;
//     s6.size = 100000;
//     s6.wait = 5;

//     P s7;
//     s7.pstart = arr + 600000;
//     s7.size = 100000;
//     s7.wait = 4;

//     P s8;
//     s8.pstart = arr + 700000;
//     s8.size = 100000;
//     s8.wait = 3;

//     P s9;
//     s9.pstart = arr + 800000;
//     s9.size = 100000;
//     s9.wait = 2;

//     P s10;
//     s10.pstart = arr + 900000;
//     s10.size = 100000;
//     s10.wait = 1;

//     int div = maxi / 10;
//     int nums[maxi];
//     int *c1 = nums;
//     int *c2 = nums + 100000; // segment 10 times of a 100,000 each
//     int *c3 = nums + 200000;
//     int *c4 = nums + 300000;
//     int *c5 = nums + 400000;
//     int *c6 = nums + 500000;
//     int *c7 = nums + 600000;
//     int *c8 = nums + 700000;
//     int *c9 = nums + 800000;
//     int *c10 = nums + 900000;

//     bubbleSort(c1, div); // bubble sort each portion of the numbers
//     bubbleSort(c2, div);
//     bubbleSort(c3, div);
//     bubbleSort(c4, div);
//     bubbleSort(c5, div);
//     bubbleSort(c6, div);
//     bubbleSort(c7, div);
//     bubbleSort(c8, div);
//     bubbleSort(c9, div);
//     bubbleSort(c10, div);

//     pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;
//     int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7, iret8, iret9;
//     /* Create independent threads each of which will execute function */
//     iret0 = pthread_create(&thread0, NULL, printHelper, (void *)&s1);
//     iret1 = pthread_create(&thread1, NULL, printHelper, (void *)&s2);
//     iret2 = pthread_create(&thread2, NULL, printHelper, (void *)&s3);
//     iret3 = pthread_create(&thread3, NULL, printHelper, (void *)&s4);
//     iret4 = pthread_create(&thread4, NULL, printHelper, (void *)&s5);
//     iret5 = pthread_create(&thread5, NULL, printHelper, (void *)&s6);
//     iret6 = pthread_create(&thread6, NULL, printHelper, (void *)&s7);
//     iret7 = pthread_create(&thread7, NULL, printHelper, (void *)&s8);
//     iret8 = pthread_create(&thread8, NULL, printHelper, (void *)&s9);
//     iret9 = pthread_create(&thread9, NULL, printHelper, (void *)&s10);

//     pthread_join(thread0, NULL);
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
//     pthread_join(thread3, NULL);
//     pthread_join(thread4, NULL);
//     pthread_join(thread5, NULL);
//     pthread_join(thread6, NULL);
//     pthread_join(thread7, NULL);
//     pthread_join(thread8, NULL);
//     pthread_join(thread9, NULL);

//     merge(s1.pstart, s2.pstart, s1.size, s2.size);
//     merge(s3.pstart, s4.pstart, s3.size, s4.size);
//     merge(s5.pstart, s6.pstart, s5.size, s6.size);
//     merge(s7.pstart, s8.pstart, s7.size, s7.size);
//     merge(s9.pstart, s10.pstart, s9.size, s10.size);

//     // send output to mysort.out
//     ofstream fout(argv[2], ios::out | ios::trunc);

//     // print output in file
//     for (int i = 0; i < counter; i++)
//     {
//         fout << arr[i] << endl;
//     }

//     fout.close();
//     cout << "it has been sorted\n";

//     return 0;
// }

//     int numOfItems = counter;
//     cout << "Starting Bubble Sort with " << numOfItems << " items" << endl;
//     bubbleSort(arr, numOfItems);
//     cout << "Ending Bubble Sort" << endl;

//     // send output to mysort.out
//     ofstream fout(argv[2], ios::out | ios::trunc);

//     // print output in file
//     for (int i = 0; i < counter; i++)
//     {
//         fout << arr[i] << endl;
//     }

//     fout.close();
//     cout << "it has been sorted\n";
//     return 0;
// }

// merge(s1, 10, s2, 10); // pass in the size because there are going to be subarrays of different sizes

// void merge(a1, s1, a2, s2)
// {
//     int temp[s1 + s2];

//     loop-> // implement a loop
//         compare the first item in each array
//             copy the smallest to temp

//                 when all the numbers compares,
//         temp copy All the numbers from temp back
// }
