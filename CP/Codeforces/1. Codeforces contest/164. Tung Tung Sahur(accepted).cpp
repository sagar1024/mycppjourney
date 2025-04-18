// D. Tung Tung Sahur

// time limit per test2 seconds
// memory limit per test256 megabytes

// You have two drums in front of you: a left drum and a right drum. A hit on the left can be recorded as "L", and a hit on the right as "R". The strange forces that rule this world are fickle: sometimes, a blow sounds once, and sometimes it sounds twice. Therefore, a hit on the left drum could have sounded as either "L" or "LL", and a hit on the right drum could have sounded as either "R" or "RR". The sequence of hits made is recorded in the string p, and the sounds heard are in the string s. Given p and s, determine whether it is true that the string s could have been the result of the hits from the string p. For example, if p="LR", then the result of the hits could be any of the strings "LR", "LRR", "LLR", and "LLRR", but the strings "LLLR" or "LRL" cannot.

// Input
// The first line contains an integer t (1≤t≤104) – the number of independent test cases. The first line of each test case contains the string p (1≤|p|≤2⋅105) consisting only of the characters "R" and "L", where |p| denotes the length of the string p. The second line of each test case contains the string s (1≤|p|≤|s|≤2⋅105) consisting only of the characters "R" and "L". It is guaranteed that the sum of |s| does not exceed 2⋅105 across all test cases.

// Output
// For each set of input data, output "YES" if s can be the heard sound, and "NO" otherwise. You may output in any case.

// Example
// InputCopy
// 5
// R
// RR
// LRLR
// LRLR
// LR
// LLLR
// LLLLLRL
// LLLLRRLL
// LLRLRLRRL
// LLLRLRRLLRRRL
// OutputCopy
// YES
// YES
// NO
// NO
// YES

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

vector<pair<char, int>> compress(const string &str)
{
    vector<pair<char, int>> result;

    int count = 1;
    for (size_t i = 1; i < str.size(); ++i)
    {
        if (str[i] == str[i - 1])
        {
            count++;
        }
        else
        {
            result.push_back({str[i - 1], count});
            count = 1;
        }
    }

    result.push_back({str.back(), count});

    return result;
}

void solve()
{
    string p, s;
    cin >> p >> s;

    vector<pair<char, int>> pc = compress(p);
    vector<pair<char, int>> sc = compress(s);

    if (pc.size() != sc.size())
    {
        cout << "NO\n";
        return;
    }

    for (size_t i = 0; i < pc.size(); ++i)
    {
        if (pc[i].first != sc[i].first)
        {
            cout << "NO\n";
            return;
        }
        if (sc[i].second < pc[i].second || sc[i].second > 2 * pc[i].second)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
