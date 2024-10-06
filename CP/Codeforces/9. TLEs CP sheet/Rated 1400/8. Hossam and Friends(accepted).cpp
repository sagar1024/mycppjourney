// B. Hossam and Friends

// time limit per test2 seconds
// memory limit per test256 megabytes

// Hossam makes a big party, and he will invite his friends to the party. He has n friends numbered from 1 to n. They will be arranged in a queue as follows: 1,2,3,…,n. Hossam has a list of m pairs of his friends that don't know each other. Any pair not present in this list are friends. A subsegment of the queue starting from the friend a and ending at the friend b is [a,a+1,a+2,…,b]. A subsegment of the queue is called good when all pairs of that segment are friends. Hossam wants to know how many pairs (a,b) there are (1≤a≤b≤n), such that the subsegment starting from the friend a and ending at the friend b is good.

// Input
// The input consists of multiple test cases. The first line contains a single integer t (1≤t≤2⋅104), the number of test cases. Description of the test cases follows. The first line of each test case contains two integer numbers n and m (2≤n≤105, 0≤m≤105) representing the number of friends and the number of pairs, respectively. The i-th of the next m lines contains two integers xi and yi (1≤xi,yi≤n, xi≠yi) representing a pair of Hossam's friends that don't know each other. Note that pairs can be repeated. It is guaranteed that the sum of n over all test cases does not exceed 105, and the sum of m over all test cases does not exceed 105.

// Output
// For each test case print an integer — the number of good subsegments.

// Example
// InputCopy
// 2
// 3 2
// 1 3
// 2 3
// 4 2
// 1 2
// 2 3
// OutputCopy
// 4
// 5

// Note
// In the first example, the answer is 4.
// The good subsegments are:
// [1]
// [2]
// [3]
// [1, 2]
// In the second example, the answer is 5.
// The good subsegments are:
// [1]
// [2]
// [3]
// [4]
// [3, 4]

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int MAX = 1e5+5;
vector<int> a(MAX);

void solve()
{
    int n, m;
    cin >> n >> m;

    //vector<int> a(n);
    for(int i=1; i<=n; i++)
    {
        //Initially, all values are set to n
        //Meaning every subsegment starting at i is good up to the last element
        a[i] = n;
    }

    // vector<pair<int,int>> notFriends(m);
    // for(int i=0; i<m; i++)
    // {
    //     cin >> notFriends[i].first >> notFriends[i].second;
    // }

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;

        if(x>y)
        {
            swap(x,y);
        }

        //For each pair (x, y) where x and y are friends who don't know each other
        //We enforce that the segment starting at x cannot be good beyond y-1
        a[x] = min(a[x], y-1);
    }

    for(int i=n-1; i; i--)
    {
        //Ensuring that if a subsegment starting at i+1 is bad at some point mn[i+1]
        //Then the subsegment starting at i cannot extend beyond that point either
        a[i] = min(a[i], a[i+1]);
    }

    //The ans starts with n because each single element subsegment [i, i] is trivially good
    //For each index i, the number of good subsegments starting at i is mn[i] - i + 1
    //This is the number of elements in the segment [i, mn[i]]
    //Here mn[i] - i computes how many good subsegments start at i & end at any point from i to mn[i]
    ll int ans = n;
    for(int i=0; i<n; i++)
    {
        ans += a[i]-i;
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
