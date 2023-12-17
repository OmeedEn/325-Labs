// Omeed Enshaie
// CECS 325-02
// Prog 7 BigInt
// Due Date(12/01/2023)
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "bigInt.h"
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

BigInt::BigInt()
{
    v.push_back(0);
}

BigInt::BigInt(int n)
{
    if (n == 0)
    {
        v.push_back(0);
    }
    else
    {
        while (n > 0)
        {
            v.push_back(n % 10);
            n /= 10;
        }
    }
}

BigInt::BigInt(string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (isdigit(str[i]))
        {
            v.push_back(str[i] - '0');
        }
    }

    if (v.size() > 0)
    {
        v.push_back(0);
    }
}

int BigInt::operator[](int index) const
{
    if (index < 0 || index >= v.size())
        throw out_of_range("index out of range");
    else
        return v[index];
}

int BigInt::size() const
{
    return v.size();
}

BigInt BigInt::operator+(BigInt num)
{
    BigInt result;
    result.v.clear();

    int carry = 0;
    int sum = 0;
    int i = 0;
    int j = 0;

    while (i < v.size() || j < num.size() || carry > 0)
    {
        sum = carry;

        if (i < v.size())
        {
            sum += v[i];
            i++;
        }
        if (j < num.size())
        {
            sum += num.v[j];
            j++;
        }

        // carry for the next iteration
        carry = sum / 10;
        result.v.push_back((sum % 10));
    }
    return result;
}

BigInt BigInt::operator++()
{
    *this = *this + BigInt(1);
    return *this;
}

BigInt BigInt::operator++(int)
{
    BigInt num = *this;
    ++(*this);
    return num;
}

BigInt BigInt::operator*(BigInt num)
{
    BigInt product;
    BigInt sum = *this;

    for (BigInt i = 0; i < num; i = i + 1) // use the operator we have above
    {
        product = product + sum;
    }

    return product;
}

BigInt BigInt::half()
{
    BigInt half;
    half.v.clear();
    int carry = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = carry * 10 + (v[i]);
        carry = curr % 2;
        half.v.push_back(curr / 2);
    }

    reverse(half.v.begin(), half.v.end()); // reverse the least sig digit w the most

    while (half.size() > 0 && half.v.back() == 0)
    {
        half.v.pop_back(); // delete leading zeros
    }

    return half;
}

bool BigInt::isOdd()
{
    bool odd = false;
    if (v[0] % 2 == 1)
    {
        odd = true;
    }
    return odd;
}

bool BigInt::isEven()
{
    return !isOdd();
}

bool BigInt::operator==(BigInt num)
{
    return v == num.v;
}

bool BigInt::operator<(BigInt num)
{
    if (v.size() != num.size())
    {
        return v.size() < num.size();
    }
    for (int i = v.size() - 1; i >= 0; --i)
    {
        if (v[i] != num.v[i])
        {
            return v[i] < num.v[i];
        }
    }
    return false;
}

ostream &operator<<(ostream &out, const BigInt &n)
{
    int length = n.size();

    if (length <= 8)
    {
        for (int i = length - 1; i >= 0; --i)
        {
            out << (int)n[i];
        }
    }
    else
    {
        out << (int)n[length - 1] << '.';
        for (int i = length - 2; i >= max(0, length - 8); --i)
        {
            out << (int)n[i];
        }
        out << 'e' << (length - 1);
    }

    return out;
}
