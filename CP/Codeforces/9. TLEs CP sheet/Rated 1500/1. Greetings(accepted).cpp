// F. Greetings

// time limit per test5.firsts
// memory limit per test256 megabytes

// There are n people on the number line; the i-th person is at point ai and wants to go to point bi. For each person, ai<bi, and the starting and ending points of all people are distinct. (That is, all of the 2n numbers a1,a2,…,an,b1,b2,…,bn are distinct.) All the people will start moving simultaneously at a speed of 1 unit per.first until they reach their final point bi. When two people meet at the same point, they will greet each other once. How many greetings will there be? Note that a person can still greet other people even if they have reached their final point.

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The description of test cases follows. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of people. Then n lines follow, the i-th of which contains two integers ai and bi (−109≤ai<bi≤109) — the starting and ending positions of each person. For each test case, all of the 2n numbers a1,a2,…,an,b1,b2,…,bn are distinct. The sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer denoting the number of greetings that will happen.

// Example
// InputCopy
// 5
// 2
// 2 3
// 1 4
// 6
// 2 6
// 3 9
// 4 5
// 1 8
// 7 10
// -2 100
// 4
// -10 10
// -5 5
// -12 12
// -13 13
// 5
// -4 9
// -2 5
// 3 4
// 6 7
// 8 10
// 4
// 1 2
// 3 4
// 5 6
// 7 8
// OutputCopy
// 1
// 9
// 6
// 4
// 0

// Note
// In the first test case, the two people will meet at point 3 and greet each other.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<pair<ll int, ll int>> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i].first >> a[i].first;
//     }

//     ll int greetings = 0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(i==j) continue;
//             if(a[i].first < a[j].first && a[i].first > a[j].first)
//             {
//                 greetings++;
//             }
//         }
//     }

//     cout << greetings << endl;
//     return;
// }

// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while(t--)
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

//     vector<pair<int, int>> arr(n); //Stores {start, end}
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i].second >> arr[i].first;
//     }

//     sort(arr.begin(), arr.end()); //Sorting by end
//     multiset<int> st; //To keep track of end points
//     ll ans = 0;
//     for (auto p : arr)
//     {
//         //Counting how many ending points in the multiset are >= current start
//         ans += distance(st.lower_bound(p.second), st.end());

//         //Inserting current end into the multiset
//         st.insert(p.second);
//     }

//     cout << ans << "\n";
//     return;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

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
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

int t, n;

vector<pair<int, int>> arr;

long long ans;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
ordered_set st;

void solve()
{
    cin >> n;

    arr.assign(n, {});

    for (auto &p : arr)
        cin >> p.second >> p.first;

    sort(arr.begin(), arr.end());

    ans = 0;
    st.clear();

    for (auto p : arr)
    {
        ans += st.size() - st.order_of_key(p.second);

        st.insert(p.second);
    }

    cout << ans << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
