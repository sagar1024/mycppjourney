// B. Cost of the Array

// time limit per test1 second
// memory limit per test256 megabytes

// You are given an array a of length n and an even integer k (2≤k≤n). You need to split the array a into exactly k non-empty subarrays† such that each element of the array a belongs to exactly one subarray. Next, all subarrays with even indices (second, fourth, …, k-th) are concatenated into a single array b. After that, 0 is added to the end of the array b. The cost of the array b is defined as the minimum index i such that bi≠i. For example, the cost of the array b=[1,2,4,5,0] is 3, since b1=1, b2=2, and b3≠3. Determine the minimum cost of the array b that can be obtained with an optimal partitioning of the array a into subarrays. An array x is a subarray of an array y if x can be obtained from y by the deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers n and k (2≤k≤n≤2⋅105, k is even) — the length of the array a and the number of subarrays. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the minimum cost of the array b that can be obtained.

// Example
// InputCopy
// 4
// 3 2
// 1 1 1
// 8 8
// 1 1 2 2 3 3 4 4
// 5 4
// 1 1 1 2 2
// 5 4
// 1 1 1000000000 2 2
// OutputCopy
// 2
// 5
// 2
// 1

// Note
// In the first test case, there are only two possible partitionings: [[1],[1,1]] and [[1,1],[1]]. In either case, b1=1, and b2≠2, so the cost is 2.
// In the second test case, there is only one possible partitioning, where b=[1,2,3,4,0], so the cost is 5 (b5=0≠5).
// In the third test case, the following partitioning works: [[1],[1,1],[2],[2]]. Then b=[1,1,2,0], and the cost is 2.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll int> a(n), a2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if ((i + 1) % 2 == 0)
        {
            a2.push_back(a[i]); //Elements at even index
        }
    }

    a2.push_back(0ll);
    ll int res = INT_MAX;
    if (n == k)
    {
        for (ll int i = 0; i < a2.size(); i++)
        {
            if (a2[i] != i + 1)
            {
                res = min(res, i + 1);
            }
        }
    }
    else
    {
        for (ll int i = 1; i < n - k + 1; i++)
        {
            if (a[i] != i + 1)
            {
                res = min(res, i + 1);
            }
        }

        if (a[n - k + 1] != 1)
        {
            res = min(res, 1ll);
        }
    }

    cout << res << endl;
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
