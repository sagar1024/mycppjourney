// A. Don't Try to Count

// time limit per test2 seconds
// memory limit per test256 megabytes

// Given a string x of length n and a string s of length m (n⋅m≤25), consisting of lowercase Latin letters, you can apply any number of operations to the string x. In one operation, you append the current value of x to the end of the string x. Note that the value of x will change after this. For example, if x="aba", then after applying operations, x will change as follows: "aba" → "abaaba" → "abaabaabaaba". After what minimum number of operations s will appear in x as a substring? A substring of a string is defined as a contiguous segment of it.

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains two numbers n and m (1≤n⋅m≤25) — the lengths of strings x and s, respectively. The second line of each test case contains the string x of length n. The third line of each test case contains the string s of length m.

// Output
// For each test case, output a single number — the minimum number of operations after which s will appear in x as a substring. If this is not possible, output −1.

// Example
// InputCopy
// 12
// 1 5
// a
// aaaaa
// 5 5
// eforc
// force
// 2 5
// ab
// ababa
// 3 5
// aba
// ababa
// 4 3
// babb
// bbb
// 5 1
// aaaaa
// a
// 4 2
// aabb
// ba
// 2 8
// bk
// kbkbkbkb
// 12 2
// fjdgmujlcont
// tf
// 2 2
// aa
// aa
// 3 5
// abb
// babba
// 1 19
// m
// mmmmmmmmmmmmmmmmmmm
// OutputCopy
// 3
// 1
// 2
// -1
// 1
// 0
// 1
// 3
// 1
// 0
// 2
// 5

// Note
// In the first test case of the example, after 2 operations, the string will become "aaaa", and after 3 operations, it will become "aaaaaaaa", so the answer is 3.
// In the second test case of the example, after applying 1 operation, the string will become "eforceforc", where the substring is highlighted in red.
// In the fourth test case of the example, it can be shown that it is impossible to obtain the desired string as a substring.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     string x, s;
//     cin >> x >> s;

//     vector<string> a;
//     for(int i=0; i<=6; i++)
//     {
//         a.push_back(x);
//         x += x;
//     }

//     bool flag = true;
//     int ans1 = 0;
//     for(int i=0; i<a.size(); i++)
//     {
//         for(int j=0; j<a[i].size(); j++)
//         {
//             flag = true;
//             for(int k=j; k<s.size(); k++)
//             {
//                 if(a[i][k]==s[k])
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag)
//             {
//                 ans1 = a[i].size();
//                 break;
//             }
//         }
//         if(flag)
//         {
//             break;
//         }
//     }

//     if(!flag)
//     {
//         cout << "-1" << endl;
//         return;
//     }

//     int ans2 = 0;
//     while(ans1>n)
//     {
//         ans1 /= 2;
//         ans2++;
//     }

//     cout << ans2 << endl;
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

// Alternate soln -

#include <iostream>
#include <string>

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::string x, s;
    std::cin >> x >> s;

    for (int i = 0; i <= 6; ++i)
    {
        if (x.find(s) != std::string::npos)
        {
            std::cout << i << std::endl;
            return;
        }
        x += x;
    }
    std::cout << -1 << std::endl;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
