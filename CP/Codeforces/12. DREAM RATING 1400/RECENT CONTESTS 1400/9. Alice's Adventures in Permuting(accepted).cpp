// B. Alice's Adventures in Permuting

// time limit per test1 second
// memory limit per test256 megabytes

// Alice mixed up the words transmutation and permutation! She has an array a specified via three integers n, b, c: the array a has length n and is given via ai=b⋅(i−1)+c for 1≤i≤n. For example, if n=3, b=2, and c=1, then a=[2⋅0+1,2⋅1+1,2⋅2+1]=[1,3,5]. Now, Alice really enjoys permutations of [0,…,n−1] and would like to transform a into a permutation. In one operation, Alice replaces the maximum element of a with the MEX of a. If there are multiple maximum elements in a, Alice chooses the leftmost one to replace. Can you help Alice figure out how many operations she has to do for a to become a permutation for the first time? If it is impossible, you should report it. A permutation of length n is an array consisting of n distinct integers from 0 to n−1 in arbitrary order. Please note, this is slightly different from the usual definition of a permutation. For example, [1,2,0,4,3] is a permutation, but [0,1,1] is not a permutation (1 appears twice in the array), and [0,2,3] is also not a permutation (n=3 but there is 3 in the array). The MEX of an array is the smallest non-negative integer that does not belong to the array. For example, the MEX of [0,3,1,3] is 2 and the MEX of [5] is 0.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤105). The description of the test cases follows. The only line of each test case contains three integers n, b, c (1≤n≤1018; 0≤b, c≤1018) — the parameters of the array.

// Output
// For each test case, if the array can never become a permutation, output −1. Otherwise, output the minimum number of operations for the array to become a permutation.

// Example
// InputCopy
// 7
// 10 1 0
// 1 2 3
// 100 2 1
// 3 0 1
// 3 0 0
// 1000000000000000000 0 0
// 1000000000000000000 1000000000000000000 1000000000000000000
// OutputCopy
// 0
// 1
// 50
// 2
// -1
// -1
// 1000000000000000000

// Note
// In the first test case, the array is already [0,1,…,9], so no operations are required.
// In the third test case, the starting array is [1,3,5,…,199]. After the first operation, the 199 gets transformed into a 0. In the second operation, the 197 gets transformed into a 2. If we continue this, it will take exactly 50 operations to get the array [0,1,2,3,…,99].
// In the fourth test case, two operations are needed: [1,1,1]→[0,1,1]→[0,2,1].
// In the fifth test case, the process is [0,0,0]→[1,0,0]→[2,0,0]→[1,0,0]→[2,0,0]. This process repeats forever, so the array is never a permutation and the answer is −1.

#include <bits/stdc++.h>
using namespace std;

#define ll long long
using namespace std;

void solve()
{
    ll int n, b, c;
    cin >> n >> b >> c;

    if(b==0)
    {
        if(c>=n) cout << n << endl;
        else if(c>=n-2) cout << n-1 << endl;
        else cout << "-1" << endl;
    }
    else
    {
        if(c>=n) cout << n << endl;
        else cout << n - max(0ll, 1 + (n - c - 1) / b) << endl;
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
