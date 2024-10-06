// C. Longest Good Array

// time limit per test2 seconds
// memory limit per test256 megabytes

// Today, Sakurako was studying arrays. An array a of length n is considered good if and only if:

// the array a is increasing, meaning ai−1<ai for all 2≤i≤n;
// the differences between adjacent elements are increasing, meaning ai−ai−1<ai+1−ai for all 2≤i<n.

// Sakurako has come up with boundaries l and r and wants to construct a good array of maximum length, where l≤ai≤r for all ai. Help Sakurako find the maximum length of a good array for the given l and r.

// Input
// The first line contains a single integer t (1≤t≤104)  — the number of test cases. The only line of each test case contains two integers l and r (1≤l≤r≤109).

// Output
// For each test case, output a single integer  — the length of the longest good array Sakurako can form given l and r.

// Example
// InputCopy
// 5
// 1 2
// 1 5
// 2 2
// 10 20
// 1 1000000000

// OutputCopy
// 2
// 3
// 1
// 5
// 44721

// Note
// For l=1 and r=5, one possible array could be (1,2,5). It can be proven that an array of length 4 does not exist for the given l and r.
// For l=2 and r=2, the only possible array is (2).
// For l=10 and r=20, the only possible array is (10,11,13,16,20).

// My original soln -

// #include <iostream>
// #include <cmath>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int l, r;
//     cin >> l >> r;

//     if(l==r)
//     {
//         cout << "1" << endl;
//         return;
//     }

//     //Calculate the maximum number n such that n*(n+1)/2 <= r-l+1
//     long long maxSum = r - l + 1;
//     long long left = 0, right = 44721; //since n*(n+1)/2 must fit in 2 * 10^9, sqrt(2*10^9) ~ 44721
//     while (left < right)
//     {
//         long long mid = (left + right + 1) / 2; //To avoid infinite loop with (left + right)/2
//         if (mid * (mid + 1) / 2 <= maxSum)
//         {
//             left = mid;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }

//     cout << left+1 << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long l, r;
    cin >> l >> r;

    //We need to find the maximum n such that l+n*(n-1)/2 <= r
    long long max_len = 0;

    //Binary search to find the maximum n
    long long left = 0, right = 1e9; //large range to cover all possibilities

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long required = l + (mid * (mid - 1)) / 2;

        if (required <= r)
        {
            max_len = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << max_len << endl;
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
