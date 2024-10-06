// A. Unit Array

// time limit per test1 second
// memory limit per test256 megabytes

// Given an array a of length n, which elements are equal to −1 and 1. Let's call the array a good if the following conditions are held at the same time:
// a1+a2+…+an≥0;
// a1⋅a2⋅…⋅an=1.

// In one operation, you can select an arbitrary element of the array ai and change its value to the opposite. In other words, if ai=−1, you can assign the value to ai:=1, and if ai=1, then assign the value to ai:=−1. Determine the minimum number of operations you need to perform to make the array a good. It can be shown that this is always possible.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤500) — the number of test cases. The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤100) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (ai=±1) — the elements of the array a.

// Output
// For each test case, output a single integer — the minimum number of operations that need to be done to make the a array good.

// Example
// InputCopy
// 7
// 4
// -1 -1 1 -1
// 5
// -1 -1 -1 1 1
// 4
// -1 1 -1 1
// 3
// -1 -1 -1
// 5
// 1 1 1 1 1
// 1
// -1
// 2
// -1 -1
// OutputCopy
// 1
// 1
// 0
// 3
// 0
// 1
// 2

// Note
// In the first test case, we can assign the value a1:=1. Then a1+a2+a3+a4=1+(−1)+1+(−1)=0≥0 and a1⋅a2⋅a3⋅a4=1⋅(−1)⋅1⋅(−1)=1. Thus, we performed 1 operation.
// In the second test case, we can assign a1:=1. Then a1+a2+a3+a4+a5=1+(−1)+(−1)+1+1=1≥0 and a1⋅a2⋅a3⋅a4⋅a5=1⋅(−1)⋅(−1)⋅1⋅1=1. Thus, we performed 1 operation.
// In the third test case, a1+a2+a3+a4=(−1)+1+(−1)+1=0≥0 and a1⋅a2⋅a3⋅a4=(−1)⋅1⋅(−1)⋅1=1. Thus, all conditions are already satisfied and no operations are needed.
// In the fourth test case, we can assign the values a1:=1,a2:=1,a3:=1. Then a1+a2+a3=1+1+1=3≥0 and a1⋅a2⋅a3=1⋅1⋅1=1. Thus, we performed 3 operations.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    int sum = 0;
    int count = 0; //Num of -1s(should be even)
    //bool allMinus = true;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if(a[i]==-1)
        {
            count++;
        }
    }

    // if(allMinus)
    // {
    //     cout << n << endl;
    //     return;
    // }
    // if(count%2==0)
    // {
    //     if(sum>=0)
    //     {
    //         cout << "0" << endl;
    //     }
    //     else
    //     {
    //         cout << "2" << endl;
    //     }
    // }
    // else
    // {
    //     if(sum>=0)
    //     {
    //         cout << "1" << endl;
    //     }
    //     else
    //     {
    //         cout << ((count - (n-count))+1)/2 << endl;
    //     }
    // }

    int minus = count;
    int plus = n - count;

    int ans = 0;
    while(plus<minus)
    {
        plus++;
        minus--;
        ans++;
    }

    if(minus%2!=0) ans += 1;

    cout << ans << endl;
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
