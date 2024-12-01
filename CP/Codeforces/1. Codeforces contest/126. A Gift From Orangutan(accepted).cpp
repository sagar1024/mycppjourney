// A. A Gift From Orangutan

// time limit per test1 second
// memory limit per test256 megabytes

// While exploring the jungle, you have bumped into a rare orangutan with a bow tie! You shake hands with the orangutan and offer him some food and water. In return... The orangutan has gifted you an array a of length n. Using a, you will construct two arrays b and c, both containing n elements, in the following manner:
// bi=min(a1,a2,…,ai) for each 1≤i≤n.
// ci=max(a1,a2,…,ai) for each 1≤i≤n.

// Define the score of a as ∑ni=1ci−bi (i.e. the sum of ci−bi over all 1≤i≤n). Before you calculate the score, you can shuffle the elements of a however you want. Find the maximum score that you can get if you shuffle the elements of a optimally.

// Input
// The first line contains t (1≤t≤100) — the number of test cases. The first line of each test case contains an integer n (1≤n≤1000) — the number of elements in a. The following line contains n integers a1,a2,…,an (1≤ai≤1000) — the elements of the array a. It is guaranteed that the sum of n over all test cases does not exceed 1000.

// Output
// For each test case, output the maximum score that you can get.

// Example
// InputCopy
// 3
// 1
// 69
// 3
// 7 6 5
// 5
// 1 1 1 2 2
// OutputCopy
// 0
// 4
// 4

// Note
// In the first test case, there is no other way to rearrange a. So, b=[69] and c=[69]. The only possible score is 69−69=0.
// In the second test case, you can rearrange a as [7,5,6]. Here, b=[7,5,5] and c=[7,7,7]. The score in this case is (7−7)+(7−5)+(7−5)=4. It can be shown this is the maximum possible score.

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a.begin(),a.end());
//     int ans = 0;
//     for(int i=0; i<n; i++)
//     {
//         ans += abs(a[i]-a[n-1-i]);
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

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll> a(n), b1, b2;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     b1 = b2 = a;
//     sort(b1.begin(), b1.end());
//     sort(b2.begin(), b2.end(),greater<int>());
//     ll ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ans += abs(b1[i]-b2[i]);
//     }

//     cout << ans << endl;
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

//Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a.begin(),a.end());
//     int ans = 0;
//     int subtractor = a[0];
//     for(int i=0; i<n; i++)
//     {
//         ans += a[i]-subtractor;
//     }

//     cout << ans << endl;
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

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    int ans = (a[n-1]-a[0])*(n-1);

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
