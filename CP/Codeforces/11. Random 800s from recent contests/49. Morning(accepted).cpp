// A. Morning

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given a four-digit pin code consisting of digits from 0 to 9 that needs to be entered. Initially, the cursor points to the digit 1. In one second, you can perform exactly one of the following two actions: Press the cursor to display the current digit, Move the cursor to any adjacent digit. The image above shows the device you are using to enter the pin code. For example, for the digit 5, the adjacent digits are 4 and 6, and for the digit 0, there is only one adjacent digit, 9. Determine the minimum number of seconds required to enter the given four-digit pin code.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) - the number of the test cases. This is followed by their description. The single line of each test case describes the pin code as a string of length 4, consisting of digits from 0 to 9.

// Output
// For each test case, output the minimum number of seconds required to enter the given pin code.

// Example
// InputCopy
// 10
// 1111
// 1236
// 1010
// 1920
// 9273
// 0000
// 7492
// 8543
// 0294
// 8361
// OutputCopy
// 4
// 9
// 31
// 27
// 28
// 13
// 25
// 16
// 33
// 24

// Note
// In the first test case, the cursor needs to be pressed 4 times.

// In the second test case, it can be done in 9 seconds as follows:
// Press the cursor.
// Move the cursor to the digit 2.
// Press the cursor.
// Move the cursor to the digit 3.
// Press the cursor.
// Move the cursor to the digit 4.
// Move the cursor to the digit 5.
// Move the cursor to the digit 6.
// Press the cursor.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     string s;
//     cin >> s;

//     int ans = 0;
//     int prev = 1;
//     for(int i=0; i<s.size(); i++)
//     {
//         if(s[i]=='0')
//         {
//             if(prev!=0)
//             {
//                 ans += (s[i]-'0')-prev+11;
//             }
//             else
//             {
//                 ans += 1;
//             }
//         }
//         else
//         {
//             if(prev!=0)
//             {
//                 ans += abs((s[i]-'0')-prev)+1;
//             }
//             else
//             {
//                 ans += abs((s[i]-'0')-prev)+9;
//             }
//         }
//         prev = s[i]-'0';
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

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int a = s[0]-'0';
    if(a==0)
    {
        a = 10;
    }

    int b = s[1]-'0';
    if(b==0)
    {
        b = 10;
    }
    
    int c = s[2]-'0';
    if(c==0)
    {
        c = 10;
    }
    
    int d = s[3]-'0';
    if(d==0)
    {
        d = 10;
    }

    int ans = abs(a-1)+abs(b-a)+abs(c-b)+abs(d-c)+4;

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
