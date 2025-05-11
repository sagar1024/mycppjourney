// D. Inaccurate Subsequence Search

// time limit per test2 seconds
// memory limit per test256 megabytes

// Maxim has an array a of n integers and an array b of m integers (m≤n). Maxim considers an array c of length m to be good if the elements of array c can be rearranged in such a way that at least k of them match the elements of array b. For example, if b=[1,2,3,4] and k=3, then the arrays [4,1,2,3] and [2,3,4,5] are good (they can be reordered as follows: [1,2,3,4] and [5,2,3,4]), while the arrays [3,4,5,6] and [3,4,3,4] are not good. Maxim wants to choose every subsegment of array a of length m as the elements of array c. Help Maxim count how many selected arrays will be good. In other words, find the number of positions 1≤l≤n−m+1 such that the elements al,al+1,…,al+m−1 form a good array.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. The first line of each test case contains three integers n, m, and k (1≤k≤m≤n≤2⋅105) — the number of elements in arrays a and b, the required number of matching elements. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106) — the elements of array a. Elements of the array a are not necessarily unique. The third line of each test case contains m integers b1,b2,…,bm (1≤bi≤106) — the elements of array b. Elements of the array b are not necessarily unique. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105. Similarly, it is guaranteed that the sum of m over all test cases does not exceed 2⋅105.

// Output
// For each test case, output the number of good subsegments of array a on a separate line.

// Example
// InputCopy
// 5
// 7 4 2
// 4 1 2 3 4 5 6
// 1 2 3 4
// 7 4 3
// 4 1 2 3 4 5 6
// 1 2 3 4
// 7 4 4
// 4 1 2 3 4 5 6
// 1 2 3 4
// 11 5 3
// 9 9 2 2 10 9 7 6 3 6 3
// 6 9 7 8 10
// 4 1 1
// 4 1 5 6
// 6
// OutputCopy
// 4
// 3
// 2
// 4
// 1

// Note
// In the first example, all subsegments are good.
// In the second example, good subsegments start at positions 1, 2, and 3.
// In the third example, good subsegments start at positions 1 and 2.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     set<int> b;
//     for(int i=0; i<m; i++)
//     {
//         int x;
//         cin >> x;
//         b.insert(x);
//     }

//     set<int> currSubarr;
//     for(int i=0; i<m; i++)
//     {
//         if(b.find(a[i])!=b.end())
//         {
//             currSubarr.insert(a[i]);
//         }
//     }

//     int ans = 0;
//     if(currSubarr.size()>=k)
//     {
//         ans++;
//     }

//     for(int i=1; i<n-m+1; i++)
//     {
//         //Removing a[i-1] from currsubarr
//         currSubarr.erase(a[i-1]);

//         //Checking if the new a[i+m-1] exists in b
//         //If yes, then inserting it in the currsubarr
//         if(b.find(a[i+m-1])!=b.end())
//         {
//             currSubarr.insert(a[i+m-1]);
//         }

//         if(currSubarr.size()>=k)
//         {
//             ans++;
//         }
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

// Alternate soln -

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    unordered_map<int, int> b_freq;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b_freq[x]++;
    }

    unordered_map<int, int> window_freq;
    int match = 0;
    int ans = 0;

    //Initializing the first window
    for (int i = 0; i < m; i++)
    {
        int val = a[i];
        if (window_freq[val] < b_freq[val])
        {
            match++;
        }

        window_freq[val]++;
    }

    if (match >= k)
        ans++;

    //Sliding the window
    for (int i = m; i < n; i++)
    {
        int out = a[i - m];
        int in = a[i];

        //Remove outgoing element
        if (window_freq[out] <= b_freq[out])
        {
            match--;
        }
        window_freq[out]--;

        //Add incoming element
        if (window_freq[in] < b_freq[in])
        {
            match++;
        }

        window_freq[in]++;
        
        if (match >= k)
            ans++;
    }

    cout << ans << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
