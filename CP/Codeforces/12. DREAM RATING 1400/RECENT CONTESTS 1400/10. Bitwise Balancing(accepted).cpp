// C. Bitwise Balancing

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given three non-negative integers b, c, and d. Please find a non-negative integer a∈[0,261] such that (a|b)−(a&c)=d, where | and & denote the bitwise OR operation and the bitwise AND operation, respectively. If such an a exists, print its value. If there is no solution, print a single integer −1. If there are multiple solutions, print any of them.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤105). The description of the test cases follows. The only line of each test case contains three positive integers b, c, and d (0≤b,c,d≤1018).

// Output
// For each test case, output the value of a, or −1 if there is no solution. Please note that a must be non-negative and cannot exceed 261.

// Example
// InputCopy
// 3
// 2 2 2
// 4 2 6
// 10 2 14
// OutputCopy
// 0
// -1
// 12

// Note
// In the first test case, (0|2)−(0&2)=2−0=2. So, a=0 is a correct answer.
// In the second test case, no value of a satisfies the equation.
// In the third test case, (12|10)−(12&2)=14−0=14. So, a=12 is a correct answer.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    ll int a = 0, b, c, d;
    cin >> b >> c >> d;

    ll int bitb, bitc, bitd;
    ll int mask = 1;

    for (ll int i = 0; i < 62; i++)
    {
        // ll int bitb = (b >> i) & 1;
        // ll int bitc = (c >> i) & 1;
        // ll int bitd = (d >> i) & 1;

        if (b&mask) bitb = 1;
        else bitb = 0;
        if (c&mask) bitc = 1;
        else bitc = 0;
        if (d&mask) bitd = 1;
        else bitd = 0;

        //Ensures that no invalid bit combinations exist
        //Meaning there is no possible value of a
        //That can satisfy the equation: (a | b) - (a & c) = d for some bit positions

        //Case 1: bitb == 1, bitc == 0, bitd == 0
        //Since bitb = 1, a | b will always be 1 (because 1 OR anything = 1)
        //Since bitc = 0, a & c will always be 0 (because 0 AND anything = 0)
        //That means: (a | 1) - (a & 0) = 1 - 0 = 1
        //But bitd = 0, which means 1 != 0 (contradiction!), so no valid a exists.

        //Case 2: bitb == 0, bitc == 1, bitd == 1
        //Since bitb = 0, a | b = a, so this part is just a
        //Since bitc = 1, a & c = a (because 1 AND anything = anything)
        //That means: d = (a | 0) - (a & 1) = a - a = 0
        //But bitd = 1, which means 0 != 1 (contradiction!), so no valid a exists.

        if ((bitb && !bitc && !bitd) || (!bitb && bitc && bitd))
        {
            cout << "-1" << endl;
            return;
        }

        //If b, c, and d all exists
        //Then compute the value of a, at that bit
        if (bitb && bitc)
        {
            //a += (1LL - bit_d) * (1LL << i);
            a += (1ll-bitd)*mask; //1 if bit_d is 0, 0 if bit_d is 1
        }
        else
        {
            a += bitd*mask;
        }

        mask = mask << 1;
    }

    cout << a << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
