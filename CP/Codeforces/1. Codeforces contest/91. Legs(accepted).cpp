// A. Legs
// time limit per test2 seconds
// memory limit per test256 megabytes

// It's another beautiful day on Farmer John's farm. After Farmer John arrived at his farm, he counted n legs. It is known only chickens and cows live on the farm, and a chicken has 2 legs while a cow has 4. What is the minimum number of animals Farmer John can have on his farm assuming he counted the legs of all animals?

// Input
// The first line contains single integer t (1≤t≤103) — the number of test cases. Each test case contains an integer n (2≤n≤2⋅103, n is even).

// Output
// For each test case, output an integer, the minimum number of animals Farmer John can have on his farm.

// Example
// InputCopy
// 3
// 2
// 6
// 8
// OutputCopy
// 1
// 2
// 2

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int cows = n / 4;
        int remaining_legs = n % 4;
        int chickens = remaining_legs / 2;

        cout << cows + chickens << endl;
    }

    return 0;
}
