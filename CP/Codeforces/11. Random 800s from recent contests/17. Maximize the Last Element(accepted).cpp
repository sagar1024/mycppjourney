// A. Maximize the Last Element

// time limit per test1 second
// memory limit per test256 megabytes

// You are given an array a of n integers, where n is odd. In one operation, you will remove two adjacent elements from the array a, and then concatenate the remaining parts of the array. For example, given the array [4,7,4,2,9], we can obtain the arrays [4,2,9] and [4,7,9] by the operations [4,7––––,4,2,9]→[4,2,9] and [4,7,4,2––––,9]→[4,7,9] respectively. However, we cannot obtain the array [7,2,9] as it requires deleting non-adjacent elements [4–,7,4–,2,9]. You will repeatedly perform this operation until exactly one element remains in a. Find the maximum possible value of the remaining element in a.

// Input
// Each test contains multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. The description of test cases follows. The first line of each test case contains a single integer n (1≤n≤99; n is odd) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤100) — the elements of the array a. Note that there is no bound on the sum of n over all test cases.

// Output
// For each test case, output a single integer — the maximum possible value of the remaining element in a.

// Example
// InputCopy
// 4
// 1
// 6
// 3
// 1 3 2
// 5
// 4 7 4 2 9
// 7
// 3 1 4 1 5 9 2
// OutputCopy
// 6
// 2
// 9
// 5

// Note
// In the first test case, the array a is [6]. Since there is only one element, no operations are needed. The maximum possible value of the remaining element is 6.
// In the second test case, the array a is [1,3,2]. We can remove the first two elements [1,3––––,2]→[2], or remove the last two elements [1,3,2––––]→[1]. Therefore, the maximum possible value of the remaining element is 2.
// In the third test case, the array a is [4,7,4,2,9]. One way to maximize the remaining element is [4,7,4––––,2,9]→[4,2––––,9]→[9]. Therefore, the maximum possible value of the remaining element is 9.
// In the fourth test case, the array a is [3,1,4,1,5,9,2]. It can be shown that the maximum possible value of the remaining element is 5.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    // int n;
    // cin >> n;

    // vector<ll int> a(n);
    // vector<pair<int,int>> a2;
    // for(int i=0; i<n; i++)
    // {
    //     cin >> a[i];
    //     a2.push_back({a[i],i+1});
    // }

    // sort(a2.begin(),a2.end(),greater<int>());
    // int ans = 0;
    // for(int i=0; i<n; i++)
    // {
    //     if(a2[i].second % 2 == 1)
    //     {
    //         ans = a2[i].first;
    //         break;
    //     }
    // }

    // cout << ans << endl;

    //ALTERNATE soln -
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //We are only concerned with the elements at odd indices (1-based)
    int ans = a[0];  //Since n is odd, a[0] will always exist
    for (int i = 0; i < n; i += 2)
    {
        ans = max(ans, a[i]);
    }

    cout << ans << endl;
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
