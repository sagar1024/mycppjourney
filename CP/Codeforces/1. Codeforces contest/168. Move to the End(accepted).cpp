// B. Move to the End

// time limit per test2 seconds
// memory limit per test512 megabytes

// You are given an array a consisting of n integers. For every integer k from 1 to n, you have to do the following:
// choose an arbitrary element of a and move it to the right end of the array (you can choose the last element, then the array won't change);
// print the sum of k last elements of a;
// move the element you've chosen on the first step to its original position (restore the original array a).

// For every k, you choose the element which you move so that the value you print is the maximum possible. Calculate the value you print for every k.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Each test case consists of two lines:
// the first line contains one integer n (1≤n≤2⋅105);
// the second line contains n integers a1,a2,…,an (1≤ai≤109).

// Additional constraint on the input: the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, print n integers. The i-th of these integers should be equal to the maximum value you can print if k=i.

// Example
// InputCopy
// 4
// 7
// 13 5 10 14 8 15 13
// 6
// 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
// 1
// 42
// 2
// 7 5
// OutputCopy
// 15 28 42 50 63 73 78 
// 1000000000 2000000000 3000000000 4000000000 5000000000 6000000000 
// 42 
// 7 12

// Note
// Let's consider the first test case from the statement:
// when k=1, you can move the 6-th element to the end, the array becomes [13,5,10,14,8,13,15], and the value you print is 15;
// when k=2, you can move the 6-th element to the end, the array becomes [13,5,10,14,8,13,15], and the value you print is 13+15=28;
// when k=3, you can move the 4-th element to the end, the array becomes [13,5,10,8,15,13,14], and the value you print is 15+13+14=42;
// when k=4, you can move the 5-th element to the end, the array becomes [13,5,10,14,15,13,8], and the value you print is 14+15+13+8=50;
// when k=5, you can move the 1-st element to the end, the array becomes [5,10,14,8,15,13,13], and the value you print is 14+8+15+13+13=63;
// when k=6, you can move the 1-st element to the end, the array becomes [5,10,14,8,15,13,13], and the value you print is 10+14+8+15+13+13=73;
// when k=7, you can move the 6-th element to the end, the array becomes [13,5,10,14,8,13,15], and the value you print is 13+5+10+14+8+13+15=78.

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     vector<ll> suff(n + 2, 0);
//     for (int i = n - 1; i >= 0; i--)
//     {
//         suff[i] = suff[i + 1] + a[i];
//     }

//     vector<ll> ans(n);
//     ll best = 0;
//     best = *max_element(a.begin(), a.end());
//     ans[0] = best;
//     for (int k = 2; k <= n; k++)
//     {
//         ll sum_last_k_minus_1 = suff[n - (k - 1)];
//         ll move_best = 0;
//         for (int i = 0; i <= n - (k - 1) - 1; i++)
//         {
//             move_best = max(move_best, a[i]);
//         }
//         ans[k-1] = sum_last_k_minus_1 + move_best;
//     }

//     for(auto x : ans)
//     {
//         cout << x << " ";
//     }

//     cout << endl;
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

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<long long> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     for (int k = 1; k <= n; k++)
//     {
//         long long max_sum = 0;
//         long long original_sum = 0;
//         for (int i = n - k; i < n; i++)
//         {
//             original_sum += a[i];
//         }

//         max_sum = original_sum;
//         for (int i = 0; i < n; i++)
//         {
//             long long new_sum;

//             if (i >= n - k)
//             {
//                 new_sum = original_sum;
//                 new_sum -= a[i];
//                 if (n - k - 1 >= 0)
//                 {
//                     new_sum += a[n - k - 1];
//                 }
//             }
//             else
//             {
//                 new_sum = original_sum;
//                 new_sum -= a[n - k];
//                 new_sum += a[i];
//             }

//             max_sum = max(max_sum, new_sum);
//         }

//         cout << max_sum << " ";
//     }

//     cout << endl;
//     return;
// }

// int main()
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
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> suff_sum(n + 2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suff_sum[i] = a[i] + suff_sum[i + 1];
    }

    vector<ll> pref_max(n, 0);
    pref_max[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref_max[i] = max(pref_max[i - 1], a[i]);
    }

    for (int k = 1; k <= n; k++)
    {
        ll ans = suff_sum[n - k];
        if (n - k - 1 >= 0)
        {
            ans = max(ans, suff_sum[n - (k - 1)] + pref_max[n - k - 1]);
        }

        cout << ans << " ";
    }

    cout << endl;
    
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
