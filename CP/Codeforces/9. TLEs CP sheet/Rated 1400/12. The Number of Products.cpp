// B. The Number of Products

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given a sequence a1,a2,…,an consisting of n non-zero integers (i.e. ai≠0). You have to calculate two following values:

// the number of pairs of indices (l,r) (l≤r) such that al⋅al+1…ar−1⋅ar is negative;
// the number of pairs of indices (l,r) (l≤r) such that al⋅al+1…ar−1⋅ar is positive;

// Input
// The first line contains one integer n (1≤n≤2⋅105) — the number of elements in the sequence. The second line contains n integers a1,a2,…,an (−109≤ai≤109;ai≠0) — the elements of the sequence.

// Output
// Print two integers — the number of subsegments with negative product and the number of subsegments with positive product, respectively.

// Examples
// InputCopy
// 5
// 5 -3 3 -1 1
// OutputCopy
// 8 7
// InputCopy
// 10
// 4 2 -4 3 1 2 -4 3 2 3
// OutputCopy
// 28 27
// InputCopy
// 5
// -1 -2 -3 -4 -5
// OutputCopy
// 9 6

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXN = 200000 + 13;

void process()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    ll ans0 = 0;
    int lastZeroPos = -1;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            lastZeroPos = i;
        }
        if (lastZeroPos != -1)
        {
            ans0 += lastZeroPos + 1;
        }
    }

    ll ansP = 0;
    int cnt1 = 0, cnt2 = 0;
    int balance = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            cnt1 = cnt2 = 0;
            balance = 0;
            continue;
        }
        if (balance % 2 == 0)
        {
            ++cnt1;
        }
        else
        {
            ++cnt2;
        }
        if (a[i] < 0)
        {
            ++balance;
        }
        ansP += (balance % 2 == 0) ? cnt1 : cnt2;
    }

    ll totalSubarrays = static_cast<ll>(n) * (n + 1) / 2;
    cout << totalSubarrays - ans0 - ansP << ' ' << ansP << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        process();
    }

    return 0;
}
