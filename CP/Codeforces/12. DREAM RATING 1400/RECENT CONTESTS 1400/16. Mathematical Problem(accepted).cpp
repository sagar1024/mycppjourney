// D. Mathematical Problem

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given a string s of length n>1, consisting of digits from 0to 9. You must insert exactly n−2 symbols + (addition) or × (multiplication) into this string to form a valid arithmetic expression. In this problem, the symbols cannot be placed before the first or after the last character of the string s, and two symbols cannot be written consecutively. Also, note that the order of the digits in the string cannot be changed. Let's consider s=987009: From this string, the following arithmetic expressions can be obtained: 9×8+70×0+9=81, 98×7×0+0×9=0, 9+8+7+0+09=9+8+7+0+9=33. Note that the number 09 is considered valid and is simply transformed into 9. From this string, the following arithmetic expressions cannot be obtained: +9×8×70+09 (symbols should only be placed between digits), 98×70+0+9 (since there are 6 digits, there must be exactly 4 symbols). The result of the arithmetic expression is calculated according to the rules of mathematics — first all multiplication operations are performed, then addition. You need to find the minimum result that can be obtained by inserting exactly n−2 addition or multiplication symbols into the given string s.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Then follows their description. The first line of each test case contains a single integer n (2≤n≤20) — the length of the string s. The second line of each test case contains a string s of length n, consisting of digits from 0 to 9.

// Output
// For each test case, output the minimum result of the arithmetic expression that can be obtained by inserting exactly n−2 addition or multiplication symbols into the given string.

// Example
// InputCopy
// 18
// 2
// 10
// 2
// 74
// 2
// 00
// 2
// 01
// 3
// 901
// 3
// 101
// 5
// 23311
// 6
// 987009
// 7
// 1111111
// 20
// 99999999999999999999
// 20
// 00000000000000000000
// 4
// 0212
// 18
// 057235283621345395
// 4
// 1112
// 20
// 19811678487321784121
// 4
// 1121
// 4
// 2221
// 3
// 011
// OutputCopy
// 10
// 74
// 0
// 1
// 9
// 1
// 19
// 0
// 11
// 261
// 0
// 0
// 0
// 12
// 93
// 12
// 24
// 0

// Note
// In the first four test cases, we cannot add symbols, so the answer will be the original number.
// In the fifth test case, the optimal answer looks as follows: 9×01=9×1=9.
// In the sixth test case, the optimal answer looks as follows: 1×01=1×1=1.
// In the seventh test case, the optimal answer looks as follows: 2+3+3+11=19.
// In the eighth test case, one of the optimal answers looks as follows: 98×7×0+0×9=0.

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

    //Edge cases
    //String with no symbols
    if(n==2)
    {
        ll int x = stoll(s);
        cout << x << endl;
        return;
    }

    //All 1s
    bool yes = true;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!='1') yes &= false;
    }
    if(yes)
    {
        //cout << n-2+11 << endl;
        cout << 11 << endl;
        return;
    }

    ll int currRes = 0;
    ll int minRes = LLONG_MAX;
    for(int i=0; i<n-1; i++)
    {
        //string curr;
        ll int currNum = (s[i]-'0')*10 + s[i+1]-'0';
        currRes += currNum;
        for(int j=0; j<n; j++)
        {
            if(j==i || j==i+1)
            {
                continue;
            }

            ll int x = s[j]-'0';
            if(x==0)
            {
                currRes *= 0;
                break;
            }
            else if(x==1) currRes *= 1;
            else
            {
                if(currRes==1)
                {
                    currRes *= s[j]-'0';
                }
                else
                {
                    currRes += s[j]-'0';
                }
            }
        }

        minRes = min(minRes,currRes);
        currRes = 0;
    }

    cout << minRes << endl;
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
