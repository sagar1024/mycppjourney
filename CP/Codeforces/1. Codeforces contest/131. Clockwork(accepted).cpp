// B. Clockwork

// time limit per test1.5 seconds
// memory limit per test512 megabytes

// You have a sequence of n time clocks arranged in a line, where the initial time on the i-th clock is ai. In each second, the following happens in order:

// Each clock's time decreases by 1. If any clock's time reaches 0, you lose immediately.
// You can choose to move to an adjacent clock or stay at the clock you are currently on.
// You can reset the time of the clock you are on back to its initial value ai.

// Note that the above events happen in order. If the time of a clock reaches 0 in a certain second, even if you can move to this clock and reset its time during that second, you will still lose. You can start from any clock. Determine if it is possible to continue this process indefinitely without losing.

// Input
// The first line of input contains a single integer t (1≤t≤104) — the number of test cases. For each test case, the first line contains a single integer n (2≤n≤5⋅105) — the number of time clocks. The second line contains n integers a1,a2,…,an (1≤ai≤109) — the initial times set on the clocks. It is guaranteed that the sum of n over all test cases does not exceed 5⋅105.

// Output
// For each test case, print "YES" (without quotes) if it is possible to continue this process indefinitely, or "NO" (without quotes) otherwise. You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

// Example
// InputCopy
// 5
// 2
// 4 10
// 2
// 2 2
// 3
// 4 10 5
// 3
// 5 3 5
// 5
// 12 13 25 17 30
// OutputCopy
// YES
// NO
// NO
// YES
// YES

// Note
// In the first test case, you can move back and forth between the two clocks, resetting them repeatedly.

// In the third test case, assuming that you start from clock 1 and follow the strategy below:
// Initially, a=[4,10,5].
// a becomes [3,9,4]. You move to clock 2 and reset its time, resulting in a=[3,10,4].
// a becomes [2,9,3]. You move to clock 3 and reset its time, resulting in a=[2,9,5].
// a becomes [1,8,4]. You move to clock 2 and reset its time, resulting in a=[1,10,4].
// a becomes [0,9,3]. You move to clock 1, but you lose because a1 reaches 0.
// It can be proven that no other strategy allows you to continue this process indefinitely.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> a(n);

//     bool all_good = true;
//     bool saviour = false;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         if(a[i]<=n*2)
//         {
//             all_good &= false;
//         }
//         if(a[i]>(n-1)*2 && !saviour)
//         {
//             saviour = true;
//         }
//     }

//     if(all_good)
//     {
//         cout << "YES" << endl;
//         return;
//     }
    
//     if(saviour)
//     {
//         cout << "YES" << endl;
//         return;
//     }

//     vector<pair<int,ll int>> diff; //Index, diff
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(i==j)
//             {
//                 continue;
//             }

//             int idx = abs(i-j);
//             ll int difference = abs(a[i]-a[j]);
//             //diff.push_back({idx,difference});

//             if(difference<=idx)
//             {
//                 cout << "NO" << endl;
//                 return;
//             }
//         }
//     }

//     cout << "YES" << endl;

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

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    bool yes = true;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(a[i] <= i*2 || a[i] <= (n-i-1)*2)
        {
            yes &= false;
        }
    }

    if(yes) cout << "YES" << endl;
    else cout << "NO" << endl;

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
