// A. Extremely Round

// time limit per test3 seconds
// memory limit per test512 megabytes

// Let's call a positive integer extremely round if it has only one non-zero digit. For example, 5000, 4, 1, 10, 200 are extremely round integers; 42, 13, 666, 77, 101 are not. You are given an integer n. You have to calculate the number of extremely round integers x such that 1≤x≤n.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Then, t lines follow. The i-th of them contains one integer n (1≤n≤999999) — the description of the i-th test case.

// Output
// For each test case, print one integer — the number of extremely round integers x such that 1≤x≤n.

// Example
// InputCopy
// 5
// 9
// 42
// 13
// 100
// 111
// OutputCopy
// 9
// 13
// 10
// 19
// 19

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    string s;
    cin >> s;

    int len = s.size();

    ll x = 0;
    if(len>1)
    {
        x += (len-1)*9;
        x += s[0]-'0';
    }
    else
    {
        x += stoll(s);
    }

    cout << x << endl;
    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
