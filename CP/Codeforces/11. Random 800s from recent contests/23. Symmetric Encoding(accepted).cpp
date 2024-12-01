// B. Symmetric Encoding

// time limit per test2 seconds
// memory limit per test256 megabytes

// Polycarp has a string s, which consists of lowercase Latin letters. He encodes this string using the following algorithm:

// first, he constructs a new auxiliary string r, which consists of all distinct letters of the string s, written in alphabetical order;
// then the encoding happens as follows: each character in the string s is replaced by its symmetric character from the string r (the first character of the string r will be replaced by the last, the second by the second from the end, and so on).

// For example, encoding the string s="codeforces" happens as follows:
// the string r is obtained as "cdefors";
// the first character s1='c' is replaced by 's';
// the second character s2='o' is replaced by 'e';
// the third character s3='d' is replaced by 'r';
// ...
// the last character s10='s' is replaced by 'c'.

// The string r and replacements for s="codeforces". Thus, the result of encoding the string s="codeforces" is the string "serofedsoc". Write a program that performs decoding — that is, restores the original string s from the encoding result.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of the string b. The second line of each test case contains a string b of length n, consisting of lowercase Latin letters — the result of encoding the original string s. It is guaranteed that the sum of the values of n over all test cases in the test does not exceed 2⋅105.

// Output
// For each test case, output the string s from which the encoding result b was obtained.

// Example
// InputCopy
// 5
// 10
// serofedsoc
// 3
// ttf
// 9
// tlrhgmaoi
// 1
// w
// 15
// hnndledmnhlttin
// OutputCopy
// codeforces
// fft
// algorithm
// w
// meetinthemiddle

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<char> distinct_chars(s.begin(),s.end()); //Storing only unique chars of string in a set
    string r(distinct_chars.begin(),distinct_chars.end()); //Creating a string wth those unique chars

    //Mapping the symmetric values
    map<char,char> encoding;
    int len = r.size();
    for(int i=0; i<len; i++)
    {
        encoding[r[i]] = r[len-i-1];
    }

    string ans;
    for(const auto x: s)
    {
        ans += encoding[x];
    }

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
