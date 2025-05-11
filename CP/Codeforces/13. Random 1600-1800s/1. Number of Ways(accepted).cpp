// C. Number of Ways

// time limit per test2 seconds
// memory limit per test256 megabytes

// You've got array a[1], a[2], ..., a[n], consisting of n integers. Count the number of ways to split all the elements of the array into three contiguous parts so that the sum of elements in each part is the same. More formally, you need to find the number of such pairs of indices i, j (2 ≤ i ≤ j ≤ n - 1), that .

// Input
// The first line contains integer n (1 ≤ n ≤ 5·105), showing how many numbers are in the array. The second line contains n integers a[1], a[2], ..., a[n] (|a[i]| ≤  109) — the elements of array a.

// Output
// Print a single integer — the number of ways to split the array into three parts with the same sum.

// Examples
// InputCopy
// 5
// 1 2 3 0 3
// OutputCopy
// 2
// InputCopy
// 4
// 0 1 -1 0
// OutputCopy
// 1
// InputCopy
// 2
// 4 1
// OutputCopy
// 0

#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int a[1000010];
long long cnt[1000010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    long long s = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s += a[i];
    }

    if (s % 3 != 0)
        cout << "0\n";
    else
    {
        s /= 3;
        long long ss = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            ss += a[i];
            if (ss == s) cnt[i] = 1;
        }
        for (int i = n - 2; i >= 0; --i)
            cnt[i] += cnt[i + 1];

        long long ans = 0;
        ss = 0;
        for (int i = 0; i + 2 < n; ++i)
        {
            ss += a[i];
            if (ss == s) ans += cnt[i + 2];
        }

        cout << ans << "\n";
    }

    return 0;
}
