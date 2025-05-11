// C. Find B

// time limit per test3 seconds
// memory limit per test256 megabytes

// An array a of length m is considered good if there exists an integer array b of length m such that the following conditions hold:
// ∑i=1mai=∑i=1mbi;
// ai≠bi for every index i from 1 to m;
// bi>0 for every index i from 1 to m.

// You are given an array c of length n. Each element of this array is greater than 0. You have to answer q queries. During the i-th query, you have to determine whether the subarray cli,cli+1,…,cri is good.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. The first line of each test case contains two integers n and q (1≤n,q≤3⋅105) — the length of the array c and the number of queries. The second line of each test case contains n integers c1,c2,…,cn (1≤ci≤109). Then q lines follow. The i-th of them contains two integers li and ri (1≤li≤ri≤n) — the borders of the i-th subarray. Additional constraints on the input: the sum of n over all test cases does not exceed 3⋅105; the sum of q over all test cases does not exceed 3⋅105.

// Output
// For each query, print YES if the subarray is good. Otherwise, print NO. You can output each letter of the answer in any case (upper or lower). For example, the strings yEs, yes, Yes, and YES will all be recognized as positive responses.

// Example
// InputCopy
// 1
// 5 4
// 1 2 1 4 5
// 1 5
// 4 4
// 3 4
// 1 3
// OutputCopy
// YES
// NO
// YES
// NO

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// bool good(vector<ll int> &a, int n, int left, int right)
// {
//     if(left==right) return false;
//     map<int,int> mp;
//     for(int i=left; i<=right; i++)
//     {
//         mp[a[i]] += 1;
//     }

//     int len = right - left + 1;
//     for(auto &p : mp)
//     {
//         if(p.second > len/2) return false;
//     }

//     return true;
// }

// void solve()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<ll int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     while(q--)
//     {
//         int l, r;
//         cin >> l >> r;

//         l--; r--;

//         if(good(a,n,l,r)) cout << "YES" << endl;
//         else cout << "NO" << endl;
//     }

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

// Alternate soln -

// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<int> c(n);
//     unordered_map<int, int> first, last;
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> c[i];

//         if (!first.count(c[i])) first[c[i]] = i;
//         last[c[i]] = i;
//     }

//     while (q--)
//     {
//         int l, r;
//         cin >> l >> r;

//         l--; r--;

//         if (first[c[l]] < l || last[c[r]] > r) cout << "YES" << endl;
//         else cout << "NO" << endl;
//     }

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

#define ll long long
using namespace std;

const int N = 300043;
int a[N];
long long sum[N];
int cnt1[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    memset(sum, 0, sizeof(sum[0]) * (n + 5));
    memset(cnt1, 0, sizeof(cnt1[0]) * (n + 5));

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
        cnt1[i + 1] = cnt1[i] + (a[i] == 1);
    }

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l;

        int cur_cnt1 = cnt1[r] - cnt1[l];
        long long cur_sum = sum[r] - sum[l];

        if ((r - l) + cur_cnt1 <= cur_sum && r - l > 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
