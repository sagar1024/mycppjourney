// A. Diverse Game

// time limit per test1 second
// memory limit per test256 megabytes

// Petr, watching Sergey's stream, came up with a matrix a, consisting of n rows and m columns (the number in the i-th row and j-th column is denoted as ai,j), which contains all integers from 1 to n⋅m. But he didn't like the arrangement of the numbers, and now he wants to come up with a new matrix b, consisting of nrows and m columns, which will also contain all integers from 1 to n⋅m, such that for any 1≤i≤n,1≤j≤m it holds that ai,j≠bi,j. You are given the matrix a, construct any matrix b that meets Petr's requirements, or determine that it is impossible. Hurry up! Otherwise, he will donate all his money to the stream in search of an answer to his question.

// Input
// Each test consists of multiple test cases. The first line contains an integer t (1≤t≤103) — the number of test cases. Then follows the description of the test cases. The first line of each test case contains two integers n and m (1≤n,m≤10) — the number of rows and columns of matrix a. The next n lines contain m integers each, describing matrix a. The i-th of these lines contains the elements of matrix ai,1,ai,2,…,ai,m. It is guaranteed that all numbers in matrix a are distinct and 1≤ai,j≤n⋅m. It is guaranteed that the sum of n⋅m over all test cases does not exceed 5⋅104.

// Output
// For each test case, output n⋅m integers — any suitable matrix b, or −1 if such a matrix does not exist.

// Example
// InputCopy
// 5
// 1 1
// 1
// 2 1
// 2
// 1
// 1 5
// 2 4 5 3 1
// 2 4
// 1 2 3 4
// 5 6 7 8
// 3 3
// 4 2 1
// 9 8 3
// 6 7 5
// OutputCopy
// -1
// 1 
// 2 
// 4 5 3 1 2 
// 6 7 8 5 
// 2 3 4 1 
// 8 3 9 
// 7 5 6 
// 2 1 4 

// Note
// In the first test case, there is only one element in the matrix, so matrix b is the only matrix and it does not fit.
// In the second test case a1,1=2≠1=b1,1, a2,1=1≠2=b2,1.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
        }
    }

    if(n==1 && m==1)
    {
        cout << "-1" << endl;
        return;
    }

    vector<int> flattened;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            flattened.push_back({a[i][j]});
        }
    }

    rotate(flattened.begin(),flattened.begin()+1, flattened.end());

    //OUTPUT
    int index = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(j==0) cout << flattened[index++];
            else cout << " " << flattened[index++];
        }
        cout << endl;
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
