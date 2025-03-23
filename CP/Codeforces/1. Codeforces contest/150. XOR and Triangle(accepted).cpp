// C. XOR and Triangle

// time limit per test2 seconds
// memory limit per test256 megabytes

// This time, the pink soldiers have given you an integer x (x≥2). Please determine if there exists a positive integer y that satisfies the following conditions. y is strictly less than x. There exists a non-degenerate triangle∗ with side lengths x, y, x⊕y. Here, ⊕ denotes the bitwise XOR operation. Additionally, if there exists such an integer y, output any. A triangle with side lengths a, b, c is non-degenerate when a+b>c, a+c>b, b+c>a.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤2000). The description of the test cases follows. The only line of each test case contains a single integer x (2≤x≤109).

// Output
// For each test case, print one integer on a separate line. The integer you must output is as follows: If there exists an integer y satisfying the conditions, output the value of y (1≤y<x); Otherwise, output −1. If there exist multiple integers that satisfy the conditions, you may output any.

// Example
// InputCopy
// 7
// 5
// 2
// 6
// 3
// 69
// 4
// 420
// OutputCopy
// 3
// -1
// 5
// -1
// 66
// -1
// 320

// Note
// In the first test case, there exists a non-degenerate triangle with side lengths 3, 5, and 3⊕5=6. Therefore, y=3 is a valid answer.
// In the second test case, 1 is the only possible candidate for y, but it cannot make a non-degenerate triangle. Therefore, the answer is −1.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
using namespace std;

bool isValidTriangle(ll int a, ll int b, ll int c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void solve()
{
    ll int x;
    cin >> x;

    ll int found = -1;
    int count1 = 1000000;
    for (ll int y = 1; y < x; ++y)
    {
        ll int z = x ^ y;
        if (isValidTriangle(x, y, z))
        {
            found = y;
            cout << found << endl;
            return;
        }

        count1--;
        if(count1 == 0)
        {
            break;
        }
    }

    int count2 = 1000000;
    for(ll int y = x-1; y >= 1; y--)
    {
        ll int z = x ^ y;
        if (isValidTriangle(x, y, z))
        {
            found = y;
            cout << found << endl;
            return;
        }

        count2--;
        if(count2 == 0)
        {
            break;
        }
    }

    cout << "-1" << endl;

    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
