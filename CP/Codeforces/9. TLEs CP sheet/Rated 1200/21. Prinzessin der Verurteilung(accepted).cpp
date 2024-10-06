// B. Prinzessin der Verurteilung

// time limit per test2 seconds
// memory limit per test256 megabytes

// I, Fischl, Prinzessin der Verurteilung, descend upon this land by the call of fate an — Oh, you are also a traveler from another world? Very well, I grant you permission to travel with me. It is no surprise Fischl speaks with a strange choice of words. However, this time, not even Oz, her raven friend, can interpret her expressions! Maybe you can help us understand what this young princess is saying? You are given a string of n lowercase Latin letters, the word that Fischl just spoke. You think that the MEX of this string may help you find the meaning behind this message. The MEX of the string is defined as the shortest string that doesn't appear as a contiguous substring in the input. If multiple strings exist, the lexicographically smallest one is considered the MEX. Note that the empty substring does NOT count as a valid MEX. A string a is lexicographically smaller than a string b if and only if one of the following holds:
// a is a prefix of b, but a≠b;
// in the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.

// A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end. Find out what the MEX of the string is!

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). Description of the test cases follows. The first line of each test case contains an integer n (1≤n≤1000) — the length of the word. The second line for each test case contains a single string of n lowercase Latin letters. The sum of n over all test cases will not exceed 1000.

// Output
// For each test case, output the MEX of the string on a new line.

// Example
// InputCopy
// 3
// 28
// qaabzwsxedcrfvtgbyhnujmiklop
// 13
// cleanairactbd
// 10
// aannttoonn
// OutputCopy
// ac
// f
// b

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

    // vector<int> freq(30);
    // for(int i=0; i<30; i++)
    // {
    //     freq[s[i]-'a']++;
    // }

    //ALT Logic -

    set<string> substrings;

    //Collecting all substrings of length 1 to 5
    for (int i = 0; i < n; i++)
    {
        string current = "";

        //Here, 3 is also fine as 26^3 is more than 1000 but26^2 is not
        for (int k = 0; k < 5 && i + k < n; k++)
        {
            current += s[i + k];
            substrings.insert(current);
        }
    }

    //Checking for the smallest missing substring of lengths 1 to 5
    //String for each length from 1 to 5
    for (int len = 1; len <= 5; len++)
    {
        string t(len, 'a'); //Initializing a string 't' of length 'len' with all 'a'

        while (true)
        {
            if (!substrings.count(t))
            {
                cout << t << '\n';
                return;
            }

            int idx = len - 1;
            while (idx >= 0 && t[idx] == 'z')
            {
                t[idx] = 'a'; //Resetting 'z' to 'a' and move to the left
                idx--;
            }

            if (idx < 0) break; //All combinations have been checked
            t[idx]++;  //Moving to the next lexicographical string
        }
    }

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
