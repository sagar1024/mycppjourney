// A. Brogramming Contest

// time limit per test1 second
// memory limit per test256 megabytes

// One day after waking up, your friend challenged you to a brogramming contest. In a brogramming contest, you are given a binary string∗ s of length n and an initially empty binary string t. During a brogramming contest, you can make either of the following moves any number of times: remove some suffix† from s and place it at the end of t, or remove some suffix from t and place it at the end of s. To win the brogramming contest, you must make the minimum number of moves required to make s contain only the character 0 and t contain only the character 1. Find the minimum number of moves required. A binary string is a string consisting of characters 0 and 1. A string a is a suffix of a string b if a can be obtained from deletion of several (possibly, zero or all) elements from the beginning of b.

// Input
// The first line contains an integer t (1≤t≤100) — the number of test cases. The first line of each test case is an integer n (1≤n≤1000) — the length of the string s. The second line of each test case contains the binary string s. The sum of n across all test cases does not exceed 1000.

// Output
// For each testcase, output the minimum number of moves required.

// Example
// InputCopy
// 5
// 5
// 00110
// 4
// 1111
// 3
// 001
// 5
// 00000
// 3
// 101
// OutputCopy
// 2
// 1
// 1
// 0
// 3

// Note
// An optimal solution to the first test case is as follows:
// s=00110, t= empty string.s=00, t=110.s=000, t=11.
// It can be proven that there is no solution using less than 2 moves.
// In the second test case, you have to move the whole string from s to t in one move.
// In the fourth test case, you don't have to do any moves.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     int z=0, o=0; //Zeros and ones
//     bool trailing_ones = false;
//     int cnt = 0;
//     for(int i=0; i<n; i++)
//     {
//         if(s[i]=='0') z++;
//         if(s[i]=='1') o++;
//         if(i>0 && s[i-1]!=s[i]) cnt++;
//     }

//     if(cnt==1) trailing_ones = true;

//     string new_s = '0' + s;
//     new_s += '0';
//     int contiguous_ones = 0;
//     for(int i=1; i<new_s.size(); i++)
//     {
//         if(new_s[i-1]!=new_s[i]) contiguous_ones++;
//     }

//     contiguous_ones = (contiguous_ones+1)/2;

//     if(o==0) cout << "0" << endl; //All 0s
//     else if(o==n) cout << "1" << endl; //All 1s
//     else if(trailing_ones) cout << "1" << endl;
//     else
//     {
//         if(s[n-1]=='0') cout << 2*contiguous_ones << endl;
//         else cout << 2*contiguous_ones-1 << endl;
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

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
            ans++;
    }

    if (s[0] == '1') ans++;
    cout << ans << endl;

    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
