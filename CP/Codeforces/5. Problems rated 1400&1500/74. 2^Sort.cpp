// G. 2^Sort

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Given an array a of length n and an integer k, find the number of indices 1≤i≤n−k such that the subarray [ai,…,ai+k] with length k+1 (not with length k) has the following property: If you multiply the first element by 20, the second element by 21, ..., and the (k+1)-st element by 2k, then this subarray is sorted in strictly increasing order. More formally, count the number of indices 1≤i≤n−k such that 20⋅ai<21⋅ai+1<22⋅ai+2<⋯<2k⋅ai+k.

// Input
// The first line contains an integer t (1≤t≤1000) — the number of test cases. The first line of each test case contains two integers n, k (3≤n≤2⋅105, 1≤k<n) — the length of the array and the number of inequalities. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array. The sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the number of indices satisfying the condition in the statement.

// Example
// inputCopy
// 6
// 4 2
// 20 22 19 84
// 5 1
// 9 5 3 2 1
// 5 2
// 9 5 3 2 1
// 7 2
// 22 12 16 4 3 22 12
// 7 3
// 22 12 16 4 3 22 12
// 9 3
// 3 9 12 3 9 12 3 9 12

// outputCopy
// 2
// 3
// 2
// 3
// 1
// 0

// Note

// In the first test case, both subarrays satisfy the condition:
// i=1: the subarray [a1,a2,a3]=[20,22,19], and 1⋅20<2⋅22<4⋅19.
// i=2: the subarray [a2,a3,a4]=[22,19,84], and 1⋅22<2⋅19<4⋅84.

// In the second test case, three subarrays satisfy the condition:
// i=1: the subarray [a1,a2]=[9,5], and 1⋅9<2⋅5.
// i=2: the subarray [a2,a3]=[5,3], and 1⋅5<2⋅3.
// i=3: the subarray [a3,a4]=[3,2], and 1⋅3<2⋅2.
// i=4: the subarray [a4,a5]=[2,1], but 1⋅2=2⋅1, so this subarray doesn't satisfy the condition.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<long long int> givenArray(n);
    for(int i=0; i<n; i++)
    {
        cin >> givenArray[i];
    }

    int count = 0;
    for(int i=k; i<n; i++)
    {
        bool yes = true;
        for(int j=1; j<=k; j++)
        {
            if(givenArray[j-1]<givenArray[j]*2)
            {
                continue;
            }
            else
            {
                yes = false;
                break;
            }
        }

        if(yes)
        {
            count++;
        }
    }

    cout << count << endl;
    return;
}

int32_t main()
{
    fastio;
    
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
