// C. Beautiful Triple Pairs

// time limit per test4 seconds
// memory limit per test256 megabytes

// Polycarp was given an array a of n integers. He really likes triples of numbers, so for each j (1≤j≤n−2) he wrote down a triple of elements [aj,aj+1,aj+2]. Polycarp considers a pair of triples b and c beautiful if they differ in exactly one position, that is, one of the following conditions is satisfied:
// b1≠c1 and b2=c2 and b3=c3;
// b1=c1 and b2≠c2 and b3=c3;
// b1=c1 and b2=c2 and b3≠c3.

// Find the number of beautiful pairs of triples among the written triples [aj,aj+1,aj+2].

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (3≤n≤2⋅105) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106) — the elements of the array. It is guaranteed that the sum of the values of n for all test cases in the test does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the number of beautiful pairs of triples among the pairs of the form [aj,aj+1,aj+2]. Note that the answer may not fit into 32-bit data types.

// Example
// InputCopy
// 8
// 5
// 3 2 2 2 3
// 5
// 1 2 1 2 1
// 8
// 1 2 3 2 2 3 4 2
// 4
// 2 1 1 1
// 8
// 2 1 1 2 1 1 1 1
// 7
// 2 1 1 1 1 1 1
// 6
// 2 1 1 1 1 1
// 5
// 2 1 1 1 1
// OutputCopy
// 2
// 0
// 3
// 1
// 8
// 4
// 3
// 2

// Note
// In the first example, a=[3,2,2,2,3], Polycarp will write the following triples:
// [3,2,2];
// [2,2,2];
// [2,2,3].
// The beautiful pairs are triple 1 with triple 2 and triple 2 with triple 3.
// In the third example, a=[1,2,3,2,2,3,4,2], Polycarp will write the following triples:
// [1,2,3];
// [2,3,2];
// [3,2,2];
// [2,2,3];
// [2,3,4];
// [3,4,2];
// The beautiful pairs are triple 1 with triple 4, triple 2 with triple 5, and triple 3 with triple 6.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    map<tuple<int,int,int>, int> cnt;
    ll int ans = 0;

    for(int i=0; i<n-2; i++)
    {
        tuple<int,int,int> currTriplet = make_tuple(a[i],a[i+1],a[i+2]);

        vector<tuple<int,int,int>> mist(3);
        
        mist[0] = make_tuple(0,a[i+1],a[i+2]);
        mist[1] = make_tuple(a[i],0,a[i+2]);
        mist[2] = make_tuple(a[i],a[i+1],0);

        for (auto& trip : mist)
        {
            ans += cnt[trip] - cnt[currTriplet];
            cnt[trip]++;
        }

        cnt[currTriplet]++;
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
