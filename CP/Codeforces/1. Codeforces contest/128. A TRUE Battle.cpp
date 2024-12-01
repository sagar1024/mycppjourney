// C. A TRUE Battle

// time limit per test2 seconds
// memory limit per test256 megabytes

// Alice and Bob are playing a game. There is a list of n booleans, each of which is either true or false, given as a binary string ∗ of length n (where 1 represents true, and 0 represents false). Initially, there are no operators between the booleans. Alice and Bob will take alternate turns placing and or or between the booleans, with Alice going first. Thus, the game will consist of n−1 turns since there are n booleans. Alice aims for the final statement to evaluate to true, while Bob aims for it to evaluate to false. Given the list of boolean values, determine whether Alice will win if both players play optimally. To evaluate the final expression, repeatedly perform the following steps until the statement consists of a single true or false: If the statement contains an and operator, choose any one and replace the subexpression surrounding it with its evaluation. Otherwise, the statement contains an or operator. Choose any one and replace the subexpression surrounding the or with its evaluation. For example, the expression true or false and false is evaluated as true or (false and false) = true or false = true. It can be shown that the result of any compound statement is unique. A binary string is a string that only consists of characters 0 and 1

// Input
// The first line contains t (1≤t≤104) — the number of test cases. The first line of each test case contains an integer n (2≤n≤2⋅105) — the length of the string. The second line contains a binary string of length n, consisting of characters 0 and 1 — the list of boolean values. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each testcase, output "YES" (without quotes) if Alice wins, and "NO" (without quotes) otherwise. You can output "YES" and "NO" in any case (for example, strings "yES", "yes" and "Yes" will be recognized as a positive response).

// Example
// InputCopy
// 5
// 2
// 11
// 3
// 010
// 12
// 101111111100
// 10
// 0111111011
// 8
// 01000010
// OutputCopy
// YES
// NO
// YES
// YES
// NO

// Note
// In the first testcase, Alice can place and between the two booleans. The game ends as there are no other places to place operators, and Alice wins because true and true is true.
// In the second testcase, Alice can place or between the middle true and the left false. Bob can place and between the middle true and the right false. The statement false or true and false is false.
// Note that these examples may not be the best strategies for either Alice or Bob.

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     bool ans = (s[0]-'0') || (s[1]-'0'); //Alice makes the first move
//     bool flip = true;
//     for(int i=2; i<n; i++)
//     {
//         //BOB
//         if(flip)
//         {
//             ans = ans && (s[i]-'0');
//             flip = !flip;
//         }

//         //ALICE
//         else
//         {
//             ans = ans || (s[i]-'0');
//             flip = !flip;
//         }
//     }

//     if(ans) cout << "YES" << endl;
//     else cout << "NO" << endl;

//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     bool yes = false;
//     for(int i=0; i<n-1; i++)
//     {
//         if(s[i]=='1' && s[i+1]=='1')
//         {
//             yes = true;
//             break;
//         }
//     }

//     if(yes) cout << "YES" << endl;
//     else cout << "NO" << endl;

//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

//Alternate soln -


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

    vector<char> a;
    a.push_back(s[0]);
    for(int i=1; i<n; i+=2)
    {
        if((s[i]-'0') && (s[i+1]-'0') && (i+1)<n)
        {
            a.push_back('1');
        }
        else
        {
            a.push_back('0');
        }
    }

    bool yes = false;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]=='1')
        {
            yes = true;
            break;
        }
    }

    if(yes) cout << "YES" << endl;
    else cout << "NO" << endl;

    return;
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
