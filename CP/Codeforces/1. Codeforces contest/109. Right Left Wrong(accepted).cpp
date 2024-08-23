// D. Right Left Wrong

// time limit per test2 seconds
// memory limit per test256 megabytes

// Vlad found a strip of n cells, numbered from left to right from 1 to n. In the i-th cell, there is a positive integer ai and a letter si, where all si are either 'L' or 'R'. Vlad invites you to try to score the maximum possible points by performing any (possibly zero) number of operations. In one operation, you can choose two indices l and r (1≤l<r≤n) such that sl = 'L' and sr = 'R' and do the following:

// add al+al+1+⋯+ar−1+ar points to the current score;
// replace si with '.' for all l≤i≤r, meaning you can no longer choose these indices.

// For example, consider the following strip:
// 3
// 5
// 1
// 4
// 3
// 2
// L	R	L	L	L	R
// You can first choose l=1, r=2 and add 3+5=8 to your score.
// 3
// 5
// 1
// 4
// 3
// 2
// .	.	L	L	L	R
// Then choose l=3, r=6 and add 1+4+3+2=10 to your score.
// 3
// 5
// 1
// 4
// 3
// 2
// .	.	.	.	.	.
// As a result, it is impossible to perform another operation, and the final score is 18. What is the maximum score that can be achieved?

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. The first line of each test case contains one integer n (2≤n≤2⋅105) — the length of the strip. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤105) — the numbers written on the strip. The third line of each test case contains a string s of n characters 'L' and 'R'. It is guaranteed that the sum of the values of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output one integer — the maximum possible number of points that can be scored.

// Example
// InputCopy
// 4
// 6
// 3 5 1 4 3 2
// LRLLLR
// 2
// 2 8
// LR
// 2
// 3 9
// RL
// 5
// 1 2 3 4 5
// LRLRR
// OutputCopy
// 18
// 10
// 0
// 22

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    ll int sum = 0;
    for (int i=0; i<n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    string s;
    cin >> s;

    ll int ans = 0;
    ll int left=0, right=n-1;
    while(left<right)
    {
        while(s[left]=='R')
        {
            sum -= a[left];
            left++;
        }
        while(s[right]=='L')
        {
            sum -= a[right];
            right--;
        }

        if(left>right)
        {
            break;
        }

        ans += sum;
        sum -= a[left];
        left++;
        sum -= a[right];
        right--;
    }

    cout << ans << endl;
    return;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
