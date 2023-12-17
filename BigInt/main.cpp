#include <iostream>
#include <limits.h>
#include "BigInt.h"

using namespace std;

int main()
{
    BigInt a = 1;
    BigInt b = BigInt(5) + BigInt(5);
    cout << b << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         // int sum = i + j;
    //         // BigInt sum = a * BigInt(i);
    //         BigInt sum2 = a + BigInt(i + j);
    //         cout << sum2 << endl;
    //     }
    // }
}
