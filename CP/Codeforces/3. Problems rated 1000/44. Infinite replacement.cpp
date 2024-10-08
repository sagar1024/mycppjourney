// C. Infinite Replacement

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// You are given a string s, consisting only of Latin letters 'a', and a string t, consisting of lowercase Latin letters. In one move, you can replace any letter 'a' in the string s with a string t. Note that after the replacement string s might contain letters other than 'a'. You can perform an arbitrary number of moves (including zero). How many different strings can you obtain? Print the number, or report that it is infinitely large. Two strings are considered different if they have different length, or they differ at some index.

// Input
// The first line contains a single integer q (1≤q≤104) — the number of testcases. The first line of each testcase contains a non-empty string s, consisting only of Latin letters 'a'. The length of s doesn't exceed 50. The second line contains a non-empty string t, consisting of lowercase Latin letters. The length of t doesn't exceed 50.

// Output
// For each testcase, print the number of different strings s that can be obtained after an arbitrary amount of moves (including zero). If the number is infinitely large, print -1. Otherwise, print the number.

// Example
// inputCopy
// 3
// aaaa
// a
// aa
// abc
// a
// b
// outputCopy
// 1
// -1
// 2

// Note
// In the first example, you can replace any letter 'a' with the string "a", but that won't change the string. So no matter how many moves you make, you can't obtain a string other than the initial one.
// In the second example, you can replace the second letter 'a' with "abc". String s becomes equal to "aabc". Then the second letter 'a' again. String s becomes equal to "aabcbc". And so on, generating infinitely many different strings.
// In the third example, you can either leave string s as is, performing zero moves, or replace the only 'a' with "b". String s becomes equal to "b", so you can't perform more moves on it.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        string t;
        cin >> t;

        if(t.size()==1 && t[0]=='a')
        {
            cout << 1 <<  endl;
            continue;
        }
        else if(t.size()==1 && t[0]!='a')
        {
            cout << 2 << endl;
            continue;
        }
        else if(t.size()>1)
        {
            bool containsA = false;
            for(int i=0; i<t.size(); i++)
            {
                if(t[i]=='a')
                {
                    containsA = true;
                }
            }
            if(containsA)
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                int count = 0;
                for(int i=0; i<s.size(); i++)
                {
                    if(s[i]=='a')
                    {
                        count++;
                    }
                }

                cout << count << endl;
            }
        }
    }

    return 0;
}
