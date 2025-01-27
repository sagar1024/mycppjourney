// B. Qingshan Loves Strings

// time limit per test1 second
// memory limit per test256 megabytes

// Qingshan has a string s, while Daniel has a string t. Both strings only contain 0 and 1.

// A string a of length k is good if and only if
// ai≠ai+1 for all i=1,2,…,k−1.

// For example, 1, 101, 0101 are good, while 11, 1001, 001100 are not good. Qingshan wants to make s good. To do this, she can do the following operation any number of times (possibly, zero):
// insert t to any position of s (getting a new s).

// Please tell Qingshan if it is possible to make s good.

// Input
// The input consists of multiple test cases. The first line contains a single integer T (1≤T≤2000) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers n and m (1≤n,m≤50) — the length of the strings s and t, respectively. The second line of each test case contains a string s of length n. The third line of each test case contains a string t of length m. It is guaranteed that s and t only contain 0 and 1.

// Output
// For each test case, print "YES" (without quotes), if it is possible to make s good, and "NO" (without quotes) otherwise. You can print letters in any case (upper or lower).

// Example
// InputCopy
// 5
// 1 1
// 1
// 0
// 3 3
// 111
// 010
// 3 2
// 111
// 00
// 6 7
// 101100
// 1010101
// 10 2
// 1001001000
// 10
// OutputCopy
// Yes
// Yes
// No
// No
// No

// Note
// In the first test case, s is good initially, so you can get a good s by doing zero operations.

// In the second test case, you can do the following two operations (the inserted string t is underlined):
// 1010––––11
// 10101010––––1
// and get s=101010101, which is good.

// In the third test case, there is no way to make s good after any number of operations.

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// bool isGoodPossible(int n, int m, const string &s, const string &t)
// {
//     // Check if `s` is good initially
//     bool is_s_good = true;
//     for (int i = 0; i < n - 1; ++i)
//     {
//         if (s[i] == s[i + 1])
//         {
//             is_s_good = false;
//             break;
//         }
//     }

//     if (is_s_good)
//         return true;

//     // Check if `t` is good
//     bool is_t_good = true;
//     for (int i = 0; i < m - 1; ++i)
//     {
//         if (t[i] == t[i + 1])
//         {
//             is_t_good = false;
//             break;
//         }
//     }

//     if (!is_t_good)
//         return false;

//     // Check if `t` is "10...01" or "01...10"
//     bool is_t_10 = (t[0] == '1' && t[m - 1] == '0');
//     bool is_t_01 = (t[0] == '0' && t[m - 1] == '1');

//     // Check for substrings "11" or "00" in `s`
//     bool has_11_in_s = false, has_00_in_s = false;
//     for (int i = 0; i < n - 1; ++i)
//     {
//         if (s[i] == '1' && s[i + 1] == '1')
//             has_11_in_s = true;
//         if (s[i] == '0' && s[i + 1] == '0')
//             has_00_in_s = true;
//     }

//     if (is_t_10 && !has_11_in_s)
//         return true;
//     if (is_t_01 && !has_00_in_s)
//         return true;

//     return false;
// }

// int main()
// {
//     int T;
//     cin >> T;
//     vector<string> results;

//     for (int i = 0; i < T; ++i)
//     {
//         int n, m;
//         cin >> n >> m;
//         string s, t;
//         cin >> s >> t;

//         if (isGoodPossible(n, m, s, t))
//         {
//             results.push_back("YES");
//         }
//         else
//         {
//             results.push_back("NO");
//         }
//     }

//     for (const string &result : results)
//     {
//         cout << result << endl;
//     }

//     return 0;
// }

// Alt code -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool ok(std::string s)
{
    for (size_t i = 1; i < s.length(); ++i)
        if (s[i] == s[i - 1]) return false;
    return true;
}

void solve()
{
    std::string s, t;
    int l1, l2;
    std::cin >> l1 >> l2;
    std::cin >> s >> t;
    if (ok(s))
    {
        std::cout << "Yes" << std::endl;
        return;
    }

    if (!ok(t) || *t.begin() != *t.rbegin())
    {
        std::cout << "No" << std::endl;
        return;
    }

    int zz = 0, oo = 0;
    for (size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            if (s[i] == '0') zz = true;
            if (s[i] == '1') oo = true;
        }
    }

    if (zz && t[0] == '0')
    {
        std::cout << "No" << std::endl;
        return;
    }
    if (oo && t[0] == '1')
    {
        std::cout << "No" << std::endl;
        return;
    }

    std::cout << "Yes" << std::endl;
    return;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--) solve();
    
    return 0;
}
