// A. Increasing Sequence

// time limit per test1 second
// memory limit per test256 megabytes

// You are given a sequence a1,a2,…,an. A sequence b1,b2,…,bn is called good, if it satisfies all of the following conditions:

// bi is a positive integer for i=1,2,…,n;
// bi≠ai for i=1,2,…,n;
// b1<b2<…<bn.

// Find the minimum value of bn among all good sequences b1,b2,…,bn.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows. The first line of each test case contains a single integer n (1≤n≤100). The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109).

// Output
// For each test case, print a single integer — the minimum value of bn among all good sequences b.

// Example
// InputCopy
// 3
// 5
// 1 3 2 6 7
// 4
// 2 3 4 5
// 1
// 1
// OutputCopy
// 8
// 4
// 2

// Note
// In the first test case, b=[2,4,5,7,8] is a good sequence. It can be proved that there is no good b with b5<8.
// In the second test case, b=[1,2,3,4] is an optimal good sequence.
// In the third test case, b=[2] is an optimal good sequence.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     int b = 1;
//     for(int i=0; i<n; i++)
//     {
//         if(a[i]==b)
//         {
//             b = a[i]+1;
//         }
//         else
//         {
//             b++;
//             while(a[i]==b && i<n)
//             {
//                 b = a[i]+1;
//                 i++;
//             }
//         }
//     }

//     cout << b << endl;
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
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    int b = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(a[0]!=1)
        {
            b = 1;
        }
        else
        {
            b = 2;
        }
    }

    for(int i=1; i<n; i++)
    {
        if(a[i]==b+1)
        {
            b = b+2;
        }
        else
        {
            b = b+1;
        }
    }

    cout << b << endl;
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
