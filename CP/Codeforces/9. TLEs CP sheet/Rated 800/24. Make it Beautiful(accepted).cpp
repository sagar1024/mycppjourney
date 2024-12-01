// A. Make it Beautiful

// time limit per test3 seconds
// memory limit per test512 megabytes

// An array a is called ugly if it contains at least one element which is equal to the sum of all elements before it. If the array is not ugly, it is beautiful. For example:
// the array [6,3,9,6] is ugly: the element 9 is equal to 6+3;
// the array [5,5,7] is ugly: the element 5 (the second one) is equal to 5;
// the array [8,4,10,14] is beautiful: 8≠0, 4≠8, 10≠8+4, 14≠8+4+10, so there is no element which is equal to the sum of all elements before it.

// You are given an array a such that 1≤a1≤a2≤⋯≤an≤100. You have to reorder the elements of a in such a way that the resulting array is beautiful. Note that you are not allowed to insert new elements or erase existing ones, you can only change the order of elements of a. You are allowed to keep the array a unchanged, if it is beautiful.

// Input
// The first line contains one integer t (1≤t≤2000) — the number of test cases. Each test case consists of two lines. The first line contains one integer n (2≤n≤50). The second line contains n integers a1,a2,…,an (1≤a1≤a2≤⋯≤an≤100).

// Output
// For each test case, print the answer as follows:
// if it is impossible to reorder the elements of a in such a way that it becomes beautiful, print NO;
// otherwise, in the first line, print YES. In the second line, print n integers — any beautiful array which can be obtained from a by reordering its elements. If there are multiple such arrays, print any of them.

// Example
// InputCopy
// 4
// 4
// 3 3 6 6
// 2
// 10 10
// 5
// 1 2 3 4 5
// 3
// 1 4 4
// OutputCopy
// YES
// 3 6 3 6
// NO
// YES
// 2 4 1 5 3
// YES
// 1 4 4

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> a(n);
//     //bool allSame = true;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         // if(i>0 && a[i-1]!=a[i])
//         // {
//         //     allSame &= false;
//         // }
//     }

//     // if(allSame)
//     // {
//     //     cout << "NO" << endl;
//     //     return;
//     // }

//     // sort(a.begin(),a.end());
//     // deque<int> b;
//     // for(int i=0; i<n; i++)
//     // {
//     //     if(i%2==0) b.push_front(a[i]);
//     //     else
//     //     {
//     //         b.push_back(a[i]);
//     //     }
//     // }

//     // cout << "YES" << endl;
//     // for(int i=0; i<n; i++)
//     // {
//     //     if(i==0) cout << b[i];
//     //     else cout << " " << b[i];
//     // }

//     // cout << endl;

//     sort(a.begin(),a.end());
//     int maxx = *max_element(a.begin(),a.end());
//     if(maxx!=a[0])
//     {
//         cout << "NO" << endl;
//         return;
//     }

//     cout << "YES" << endl;
//     cout << maxx;
//     for(int i=0; i<n-1; i++)
//     {
//         cout << " " << a[i];
//     }

//     cout << endl;

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
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    if (a[0] == a[n - 1])
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<int> result;
    result.push_back(a[n - 1]);
    for (int i = 0; i < n - 1; i++)
    {
        result.push_back(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }

    cout << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
