// A. Bazoka and Mocha's Array

// time limit per test1 second
// memory limit per test256 megabytes

// Mocha likes arrays, so before her departure, Bazoka gave her an array a consisting of n positive integers as a gift. Now Mocha wants to know whether array a could become sorted in non-decreasing order after performing the following operation some (possibly, zero) times: Split the array into two parts — a prefix and a suffix, then swap these two parts. In other words, let a=x+y. Then, we can set a:=y+x. Here + denotes the array concatenation operation. For example, if a=[3,1,4,1,5], we can choose x=[3,1] and y=[4,1,5], satisfying a=x+y. Then, we can set a:=y+x=[4,1,5,3,1]. We can also choose x=[3,1,4,1,5] and y=[], satisfying a=x+y. Then, we can set a:=y+x=[3,1,4,1,5]. Note that we are not allowed to choose x=[3,1,1] and y=[4,5], neither are we allowed to choose x=[1,3] and y=[5,1,4], as both these choices do not satisfy a=x+y.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤50) — the length of the array a. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106) — the elements of array a.

// Output
// For each test case, output "Yes" if a could become non-decreasing after performing the operation any number of times, and output "No" if not. You can output "Yes" and "No" in any case (for example, strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive response).

// Example
// InputCopy
// 3
// 6
// 1 1 4 5 1 4
// 5
// 7 9 2 2 3
// 3
// 1 2 3
// OutputCopy
// No
// Yes
// Yes

// Note
// In the first test case, it can be proven that a cannot become non-decreasing after performing the operation any number of times.
// In the second test case, we can perform the following operations to make a sorted in non-decreasing order:
// Split the array into two parts: x=[7] and y=[9,2,2,3], then swap these two parts. The array will become y+x=[9,2,2,3,7].
// Split the array into two parts: x=[9] and y=[2,2,3,7], then swap these two parts. The array will become y+x=[2,2,3,7,9], which is non-decreasing.

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
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     int count = 1;
//     bool yes = true;
//     for(int i=1; i<n; i++)
//     {
//         if(a[i-1]>a[i])
//         {
//             if(count>0) count--;
//             else
//             {
//                 yes = false;
//                 break;
//             }
//         }
//     }

//     if(yes) cout << "Yes" << endl;
//     else cout << "No" << endl;

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
#include <bits/stdc++.h>

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

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    
    vector<int> doubled_a = a;
    doubled_a.insert(doubled_a.end(), a.begin(), a.end());

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (vector<int>(doubled_a.begin() + i, doubled_a.begin() + i + n) == sorted_a)
        {
            found = true;
            break;
        }
    }

    if (found) cout << "Yes" << endl;
    else cout << "No" << endl;

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
