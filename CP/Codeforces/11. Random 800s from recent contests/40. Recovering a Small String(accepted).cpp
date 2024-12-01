// A. Recovering a Small String

// time limit per test1 second
// memory limit per test256 megabytes

// Nikita had a word consisting of exactly 3 lowercase Latin letters. The letters in the Latin alphabet are numbered from 1 to 26, where the letter "a" has the index 1, and the letter "z" has the index 26. He encoded this word as the sum of the positions of all the characters in the alphabet. For example, the word "cat" he would encode as the integer 3+1+20=24, because the letter "c" has the index 3 in the alphabet, the letter "a" has the index 1, and the letter "t" has the index 20. However, this encoding turned out to be ambiguous! For example, when encoding the word "ava", the integer 1+22+1=24 is also obtained. Determine the lexicographically smallest word of 3 letters that could have been encoded. A string a is lexicographically smaller than a string b if and only if one of the following holds:
// a is a prefix of b, but a≠b;
// in the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.

// Input
// The first line of the input contains a single integer t (1≤t≤100) — the number of test cases in the test. This is followed by the descriptions of the test cases. The first and only line of each test case contains an integer n (3≤n≤78) — the encoded word.

// Output
// For each test case, output the lexicographically smallest three-letter word that could have been encoded on a separate line.

// Example
// InputCopy
// 5
// 24
// 70
// 3
// 55
// 48
// OutputCopy
// aav
// rzz
// aaa
// czz
// auz

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    map<int,char> mp;
    mp[1] = 'a';
    mp[2] = 'b';
    mp[3] = 'c';
    mp[4] = 'd';
    mp[5] = 'e';
    mp[6] = 'f';
    mp[7] = 'g';
    mp[8] = 'h';
    mp[9] = 'i';
    mp[10] = 'j';
    mp[11] = 'k';
    mp[12] = 'l';
    mp[13] = 'm';
    mp[14] = 'n';
    mp[15] = 'o';
    mp[16] = 'p';
    mp[17] = 'q';
    mp[18] = 'r';
    mp[19] = 's';
    mp[20] = 't';
    mp[21] = 'u';
    mp[22] = 'v';
    mp[23] = 'w';
    mp[24] = 'x';
    mp[25] = 'y';
    mp[26] = 'z';

    string ans;
    for(int i=1; i<=26; i++)
    {
        for(int j=1; j<=26; j++)
        {
            for(int k=0; k<=26; k++)
            {
                if(i+j+k==n)
                {
                    ans += mp[i];
                    ans += mp[j];
                    ans += mp[k];

                    cout << ans << endl;
                    return;
                }
            }
        }
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
