// E. Min Max MEX

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an array a of length n and a number k. A subarray is defined as a sequence of one or more consecutive elements of the array. You need to split the array a into k non-overlapping subarrays b1,b2,…,bk such that the union of these subarrays equals the entire array. Additionally, you need to maximize the value of x, which is equal to the minimum MEX(bi), for i∈[1..k]. MEX(v) denotes the smallest non-negative integer that is not present in the array v.

// Input
// The first line contains an integer t (1≤t≤104)  — the number of test cases. The first line of each test case contains two integers n, k (1≤k≤n≤2⋅105)  — the length of the array and the number of segments to split the array into. The second line of each test case contains n integers ai (0≤ai≤109)  — the elements of the array. It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

// Output
// For each query, output a single number  — the maximum value x such that there exists a partition of the array a into k subarrays where the minimum MEX equals x.

// Example
// InputCopy
// 7
// 1 1
// 0
// 5 1
// 0 1 3 2 4
// 6 2
// 2 1 0 0 1 2
// 5 5
// 0 0 0 0 0
// 5 2
// 2 3 4 5 6
// 6 2
// 0 0 1 1 2 2
// 4 4
// 1 0 0 0
// OutputCopy
// 1
// 5
// 3
// 1
// 0
// 1
// 0

#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

bool can(int x, int k, const vector<int> &a)
{
    int count = 0;
    unordered_set<int> seen;
    for (int num : a)
    {
        if (num < x)
            seen.insert(num);
        if (seen.size() == x)
        {
            count++;
            seen.clear();
        }
    }

    return count >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int l = 0, r = n, ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (can(m, k, a))
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << ans << endl;
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
