// A. Permutation Counting

// time limit per test2 seconds
// memory limit per test256 megabytes

// You have some cards. An integer between 1 and n is written on each card: specifically, for each i from 1 to n, you have ai cards which have the number i written on them. There is also a shop which contains unlimited cards of each type. You have k coins, so you can buy k new cards in total, and the cards you buy can contain any integer between 1 and n. After buying the new cards, you rearrange all your cards in a line. The score of a rearrangement is the number of (contiguous) subarrays of length n which are a permutation of [1,2,…,n]. What's the maximum score you can get?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows. The first line of each test case contains two integers n, k (1≤n≤2⋅105, 0≤k≤1012) — the number of distinct types of cards and the number of coins. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1012) — the number of cards of type i you have at the beginning. It is guaranteed that the sum of n over all test cases does not exceed 5⋅105.

// Output
// For each test case, output a single line containing an integer: the maximum score you can get.

// Example
// InputCopy
// 8
// 1 10
// 1
// 2 4
// 8 4
// 3 4
// 6 1 8
// 3 9
// 7 6 2
// 5 3
// 6 6 7 4 6
// 9 7
// 7 6 1 7 6 2 4 3 3
// 10 10
// 1 3 1 2 1 9 3 5 7 5
// 9 8
// 5 8 7 5 1 3 2 9 8
// OutputCopy
// 11
// 15
// 15
// 22
// 28
// 32
// 28
// 36

// Note
// In the first test case, the final (and only) array we can get is [1,1,1,1,1,1,1,1,1,1,1] (including 11 single 1s), which contains 11 subarrays consisting of a permutation of [1].
// In the second test case, we can buy 0 cards of type 1 and 4 cards of type 2, and then we rearrange the cards as following: [1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2]. There are 8 subarrays equal to [1,2] and 7 subarrays equal to [2,1], which make a total of 15 subarrays which are a permutation of [1,2]. It can also be proved that this is the maximum score we can get.
// In the third test case, one of the possible optimal rearrangements is [3,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,3].

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     ll int n, k;
//     cin >> n >> k;

//     vector<ll int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a.begin(),a.end());
//     vector<ll int> diff;
//     for(int i=1; i<n; i++)
//     {
//         diff.push_back(abs(a[i-1]-a[i]));
//     }

//     ll int ans = a[0];
//     for(int i=0; i<diff.size(); i++)
//     {
//         for(int j=1; j<=diff[i]; j++)
//         {
//             k -= i+1;
//             if(k<=0) break;
//             ans++;
//         }
//         if(k<=0) break;
//     }

//     cout << ans << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

bool canMakeX(vector<ll int> &a, ll int k, ll int x) {
    ll int need = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < x) {
            need += (x - a[i]);
            if (need > k) return false;
        }
    }
    return need <= k;
}

void solve()
{
    ll int n, k;
    cin >> n >> k;

    vector<ll int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll int low = 0, high = 1e18;
    ll int ans = 0;
    while (low <= high)
    {
        ll int mid = (low + high) / 2;
        if (canMakeX(a, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;
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
