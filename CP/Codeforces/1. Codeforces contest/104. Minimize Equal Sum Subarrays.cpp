// B. Minimize Equal Sum Subarrays

// time limit per test1.5 seconds
// memory limit per test256 megabytes

// It is known that Farmer John likes Permutations, but I like them too!
// — Sun Tzu, The Art of Constructing Permutations

// You are given a permutation∗ p of length n. Find a permutation q of length n that minimizes the number of pairs (i,j) (1≤i≤j≤n) such that pi+pi+1+…+pj=qi+qi+1+…+qj. A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

// Input
// The first line contains t (1≤t≤104) — the number of test cases. The first line of each test case contains n (1≤n≤2⋅105). The following line contains n space-separated integers p1,p2,…,pn (1≤pi≤n) — denoting the permutation p of length n. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output one line containing any permutation of length n (the permutation q) such that q minimizes the number of pairs.

// Example
// InputCopy
// 3
// 2
// 1 2
// 5
// 1 2 3 4 5
// 7
// 4 7 5 1 2 6 3
// OutputCopy
// 2 1
// 3 5 4 2 1
// 6 2 1 4 7 3 5

// Note
// For the first test, there exists only one pair (i,j) (1≤i≤j≤n) such that pi+pi+1+…+pj=qi+qi+1+…+qj, which is (1,2). It can be proven that no such q exists for which there are no pairs.

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    for (int i=0; i<n; i++)
    {
        cin >> p[i];
    }

    //Reversing the permutation to minimize matching pairs
    // for (int i = 0; i < n; ++i)
    // {
    //     q[i] = p[n - i - 1];
    // }
    
    //Rotating array one step
    q[0] = p[n-1];
    for(int i=1; i<n; i++)
    {
        q[i] = p[i-1];
    }

    for (int i=0; i<n; i++)
    {
        if(i==0) cout << q[i];
        else cout << " " << q[i];
    }

    cout << endl;
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
