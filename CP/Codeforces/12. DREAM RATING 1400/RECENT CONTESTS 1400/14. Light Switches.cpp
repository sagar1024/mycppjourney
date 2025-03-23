// C. Light Switches

// time limit per test2 seconds
// memory limit per test256 megabytes

// There is an apartment consisting of n rooms, each with its light initially turned off. To control the lights in these rooms, the owner of the apartment decided to install chips in the rooms so that each room has exactly one chip, and the chips are installed at different times. Specifically, these times are represented by the array a1,a2,…,an, where ai is the time (in minutes) at which a chip is installed in the i-th room. As soon as a chip is installed, it changes the room's light status every k minutes — it turns on the light for k minutes, then turns it off for the next k minutes, then turns it back on for the next k minutes, and so on. In other words, the light status is changed by the chip at minute ai, ai+k, ai+2k, ai+3k, … for the i-th room. What is the earliest moment when all rooms in the apartment have their lights turned on?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains two integers n and k (1≤k≤n≤2⋅105) — the number of rooms in the apartment and the period of the chips. The second line contains n distinct integers a1,a2,…,an (1≤ai≤109) — the moments when the chips are installed. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print a single integer — the answer to the question (in minutes). If there is no such moment that the lights are turned on in all the rooms, print −1 instead.

// Example
// InputCopy
// 9
// 4 4
// 2 3 4 5
// 4 3
// 2 3 4 5
// 4 3
// 3 4 8 9
// 3 3
// 6 2 1
// 1 1
// 1
// 7 5
// 14 34 6 25 46 7 17
// 6 5
// 40 80 99 60 90 50
// 6 5
// 64 40 50 68 70 10
// 2 1
// 1 1000000000
// OutputCopy
// 5
// -1
// 10
// 8
// 1
// 47
// 100
// -1
// -1

// Note
// In the first test case, all lights will be on by the minute 5 without any of them being turned off by the chips. The answer is 5.
// In the second test case, due to k=3, the 1-st light will be on at minutes 2,3,4,8,9,10,14,…; meanwhile, the 4-th light will be on at minutes 5,6,7,11,12,13,17,…. These two sequences don't have any number in common, so they will never be on at the same time.
// In the third test case, it can be seen that the 1-st and 2-nd lights will be turned off at minutes 6 and 7, but the chips will turn them back on at minutes 9 and 10. The 3-rd and 4-th lights will also be on at minute 10, so the answer is 10.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    

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
