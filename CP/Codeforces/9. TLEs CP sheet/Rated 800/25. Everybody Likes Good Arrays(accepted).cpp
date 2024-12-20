// A. Everybody Likes Good Arrays!

// time limit per test1 second
// memory limit per test256 megabytes

// An array a is good if for all pairs of adjacent elements, ai and ai+1 (1≤i<n) are of different parity. Note that an array of size 1 is trivially good. You are given an array of size n. In one operation you can select any pair of adjacent elements in which both elements are of the same parity, delete them, and insert their product in the same position. Find the minimum number of operations to form a good array.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows. The first line of each test case contains an integer n (1≤n≤100). The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109).

// Output
// For each test case print an integer, the minimum number of operations required to form a good array.

// Example
// InputCopy
// 3
// 5
// 1 7 11 2 13
// 4
// 1 2 3 4
// 6
// 1 1 1 2 2 3
// OutputCopy
// 2
// 0
// 3

// Note
// Consider the first test case. Select the 2-nd and the 3-rd integers and apply the operation on them. The array changes from [1,7,11,2,13] to [1,77,2,13]. Next, select the 1-st and the 2-nd integers, array changes from [1,77,2,13] to [77,2,13]. Thus we require 2 operations. It can be proved that this is the minimum number of operations.
// In the second test case, the given array is already good. So we require 0 operations.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int count = 0;
    for(int i=1; i<n; i++)
    {
        if(a[i-1]%2==a[i]%2)
        {
            count++;
        }
    }

    cout << count << endl;

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
