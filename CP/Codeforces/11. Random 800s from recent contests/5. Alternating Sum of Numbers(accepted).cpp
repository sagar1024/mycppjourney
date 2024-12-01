// A. Alternating Sum of Numbers

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given a sequence of integers. Output the alternating sum of this sequence. In other words, output a1−a2+a3−a4+a5−…. That is, the signs of plus and minus alternate, starting with a plus.

// Input
// The first line of the test contains one integer t (1≤t≤1000) — the number of test cases. Then follow t test cases. The first line of each test case contains one integer n (1≤n≤50) — the length of the sequence. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤100).

// Output
// Output t lines. For each test case, output the required alternating sum of the numbers.

// Example
// InputCopy
// 4
// 4
// 1 2 3 17
// 1
// 100
// 2
// 100 100
// 5
// 3 1 4 1 5

// OutputCopy
// -15
// 100
// 0
// 10

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            sum += a[i];
        }
        else
        {
            sum -= a[i];
        }
    }

    cout << sum << endl;
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
