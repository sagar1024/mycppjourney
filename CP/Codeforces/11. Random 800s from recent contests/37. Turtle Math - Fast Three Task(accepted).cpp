// B. Turtle Math: Fast Three Task

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an array a1,a2,…,an. In one move, you can perform either of the following two operations: Choose an element from the array and remove it from the array. As a result, the length of the array decreases by 1; Choose an element from the array and increase its value by 1. You can perform any number of moves. If the current array becomes empty, then no more moves can be made. Your task is to find the minimum number of moves required to make the sum of the elements of the array a divisible by 3. It is possible that you may need 0 moves. Note that the sum of the elements of an empty array (an array of length 0) is equal to 0.

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤105). The second line of each test case contains n integers a1,a2,…,an (1≤ai≤104). The sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer: the minimum number of moves.

// Example
// InputCopy
// 8
// 4
// 2 2 5 4
// 3
// 1 3 2
// 4
// 3 7 6 8
// 1
// 1
// 4
// 2 2 4 2
// 2
// 5 5
// 7
// 2 4 8 1 9 3 4
// 2
// 4 10
// OutputCopy
// 1
// 0
// 0
// 1
// 1
// 2
// 1
// 1

// Note
// In the first test case, initially the array a=[2,2,5,4]. One of the optimal ways to make moves is:
// remove the current 4th element and get a=[2,2,5];
// As a result, the sum of the elements of the array a will be divisible by 3 (indeed, a1+a2+a3=2+2+5=9).
// In the second test case, initially, the sum of the array is 1+3+2=6, which is divisible by 3. Therefore, no moves are required. Hence, the answer is 0.
// In the fourth test case, initially, the sum of the array is 1, which is not divisible by 3. By removing its only element, you will get an empty array, so its sum is 0. Hence, the answer is 1.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> a(n);

//     ll int sum = 0;
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }

//     if(sum%3==0)
//     {
//         cout << "0" << endl;
//         return;
//     }

//     ll int ans = 0;
//     bool yes = false;
//     for(int i=0; i<n; i++)
//     {
//         if(sum%3==a[i]%3)
//         {
//             ans = a[i];
//             yes = true;
//             break;
//         }
//     }

//     if(yes)
//     {
//         cout << ans << endl;
//         return;
//     }

//     if(sum%3==1) cout << "2" << endl;
//     else if(sum%3==2) cout << "1" << endl;

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

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);

    ll int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if(sum%3==0)
    {
        cout << "0" << endl;
        return;
    }

    bool yes = false;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(sum%3==a[i]%3)
        {
            ans = a[i];
            yes = true;
            break;
        }
    }

    if(sum%3==2 || yes)
    {
        cout << "1" << endl;
        return;
    }

    if(sum%3==1)
    {
        cout << "2" << endl;
        return;
    }

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
