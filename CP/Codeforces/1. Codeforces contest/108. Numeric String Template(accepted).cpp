// C. Numeric String Template

// time limit per test2 seconds
// memory limit per test256 megabytes

// Kristina has an array a, called a template, consisting of n integers. She also has m strings, each consisting only of lowercase Latin letters. The strings are numbered from 1 to m. She wants to check which strings match the template. A string s is considered to match the template if all of the following conditions are simultaneously satisfied:

// The length of the string s is equal to the number of elements in the array a.
// The same numbers from a correspond to the same symbols from s. So, if ai=aj, then si=sj for (1≤i,j≤n).
// The same symbols from s correspond to the same numbers from a. So, if si=sj, then ai=aj for (1≤i,j≤n).

// In other words, there must be a one-to-one correspondence between the characters of the string and the elements of the array. For example, if a = [3,5,2,1,3], then the string "abfda" matches the template, while the string "afbfa" does not, since the character "f" corresponds to both numbers 1 and 5.

// Input
// The first line of input contains a single integer t (1≤t≤104) — the number of test cases. The following descriptions are for the test cases. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of elements in the array a. The second line of each test case contains exactly n integers ai (−109≤ai≤109) — the elements of the array a. The third line of each test case contains a single integer m (1≤m≤2⋅105) — the number of strings to check for template matching. Following are m strings, each containing a non-empty string sj (1≤|sj|≤2⋅105), consisting of lowercase Latin letters. It is guaranteed that the sum of n across all test cases does not exceed 2⋅105, and that the sum of the lengths of all strings does not exceed 2⋅105.

// Output
// For each test case, output m lines. On the i-th line (1≤i≤m) output:

// "YES", if the string with index i matches the template;
// "NO" otherwise.

// You may output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

// Example
// InputCopy
// 3
// 5
// 3 5 2 1 3
// 2
// abfda
// afbfa
// 2
// 1 2
// 3
// ab
// abc
// aa
// 4
// 5 -3 5 -3
// 4
// aaaa
// bcbc
// aba
// cbcb
// OutputCopy
// YES
// NO
// YES
// NO
// NO
// NO
// YES
// NO
// YES

// Note
// The first test case is explained in the problem statement.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     int m;
//     cin >> m;

//     while(m--)
//     {
//         string s;
//         cin >> s;

//         int len = s.size();
//         if(len!=n)
//         {
//             cout << "NO" << endl;
//             continue;
//         }

//         unordered_map<int,char> mp1, mp2;
//         for(int i=0; i<n; i++)
//         {
//             mp1[a[i]] = s[i];
//             mp2[s[i]] = a[i];
//         }

//     }
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

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool matchesTemplate(const vector<ll int> &templateArray, const string &s)
{
    if (templateArray.size() != s.size())
    {
        return false;
    }

    unordered_map<char, ll int> charToNum;
    unordered_map<ll int, char> numToChar;

    for (size_t i = 0; i < s.size(); ++i)
    {
        char ch = s[i];
        ll int num = templateArray[i];

        if (charToNum.find(ch) != charToNum.end())
        {
            if (charToNum[ch] != num)
            {
                return false;
            }
        }
        else
        {
            charToNum[ch] = num;
        }

        if (numToChar.find(num) != numToChar.end())
        {
            if (numToChar[num] != ch)
            {
                return false;
            }
        }
        else
        {
            numToChar[num] = ch;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll int> templateArray(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> templateArray[i];
        }

        int m;
        cin >> m;

        vector<string> strings(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> strings[i];
        }

        for (const string &s : strings)
        {
            if (matchesTemplate(templateArray, s))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
