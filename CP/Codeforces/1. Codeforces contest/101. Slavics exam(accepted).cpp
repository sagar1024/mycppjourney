// D. Slavic's Exam

// time limit per test2 seconds
// memory limit per test256 megabytes

// Slavic has a very tough exam and needs your help in order to pass it. Here is the question he is struggling with: There exists a string s, which consists of lowercase English letters and possibly zero or more "?". Slavic is asked to change each "?" to a lowercase English letter such that string t becomes a subsequence (not necessarily continuous) of the string s. Output any such string, or say that it is impossible in case no string that respects the conditions exists.

// Input
// The first line contains a single integer T (1≤T≤104) — the number of test cases. The first line of each test case contains a single string s (1≤|s|≤2⋅105, and s consists only of lowercase English letters and "?"-s)  – the original string you have. The second line of each test case contains a single string t (1≤|t|≤|s|, and t consists only of lowercase English letters)  – the string that should be a subsequence of string s. The sum of |s| over all test cases doesn't exceed 2⋅105, where |x| denotes the length of the string x.

// Output
// For each test case, if no such string exists as described in the statement, output "NO" (without quotes). Otherwise, output "YES" (without quotes). Then, output one line — the string that respects all conditions. You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response). If multiple answers are possible, you can output any of them.

// Example
// InputCopy
// 5
// ?????
// xbx
// ab??e
// abcde
// ayy?x
// a
// ab??e
// dac
// paiu
// mom
// OutputCopy
// YES
// xabax
// YES
// abcde
// YES
// ayyyx
// NO
// NO

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    int j = 0; //Pointer for t

    //Trying to replace '?' in s and match t
    for (int i = 0; i < n; ++i)
    {
        if (j < m && s[i] == t[j])
        {
            j++;
        }
        else if (s[i] == '?')
        {
            if (j < m)
            {
                s[i] = t[j];
                j++;
            }
            else
            {
                s[i] = 'a'; //Replacing remaining '?' with 'a' or any letter
            }
        }
    }

    //Checking if all characters of t are matched
    if (j == m)
    {
        cout << "YES" << endl;
        cout << s << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
