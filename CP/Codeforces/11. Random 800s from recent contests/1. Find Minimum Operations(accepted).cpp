// A. Find Minimum Operations

// time limit per test1 second
// memory limit per test256 megabytes

// You are given two integers n and k. In one operation, you can subtract any power of k from n. Formally, in one operation, you can replace n by (n−kx) for any non-negative integer x. Find the minimum number of operations required to make n equal to 0.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The only line of each test case contains two integers n and k (1≤n,k≤109).

// Output
// For each test case, output the minimum number of operations on a new line.

// Example
// InputCopy
// 6
// 5 2
// 3 5
// 16 4
// 100 3
// 6492 10
// 10 1
// OutputCopy
// 2
// 3
// 1
// 4
// 21
// 10

// Note
// In the first test case, n=5 and k=2. We can perform the following sequence of operations:
// Subtract 20=1 from 5. The current value of n becomes 5−1=4.
// Subtract 22=4 from 4. The current value of n becomes 4−4=0.
// It can be shown that there is no way to make n equal to 0 in less than 2 operations. Thus, 2 is the answer.

// In the second test case, n=3 and k=5. We can perform the following sequence of operations:
// Subtract 50=1 from 3. The current value of n becomes 3−1=2.
// Subtract 50=1 from 2. The current value of n becomes 2−1=1.
// Subtract 50=1 from 1. The current value of n becomes 1−1=0.
// It can be shown that there is no way to make n equal to 0 in less than 3 operations. Thus, 3 is the answer.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    ll int n, k;
    cin >> n >> k;

    ll int ans = 0;
    if(n<k || k==1)
    {
        cout << n << endl;
        return;
    }
    else
    {
        while(n)
        {
            ans += n%k;
            n /= k;
        }
    }

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
