// C. Constanze's Machine

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Constanze is the smartest girl in her village but she has bad eyesight. One day, she was able to invent an incredible machine! When you pronounce letters, the machine will inscribe them onto a piece of paper. For example, if you pronounce 'c', 'o', 'd', and 'e' in that order, then the machine will inscribe "code" onto the paper. Thanks to this machine, she can finally write messages without using her glasses. However, her dumb friend Akko decided to play a prank on her. Akko tinkered with the machine so that if you pronounce 'w', it will inscribe "uu" instead of "w", and if you pronounce 'm', it will inscribe "nn" instead of "m"! Since Constanze had bad eyesight, she was not able to realize what Akko did. The rest of the letters behave the same as before: if you pronounce any letter besides 'w' and 'm', the machine will just inscribe it onto a piece of paper. The next day, I received a letter in my mailbox. I can't understand it so I think it's either just some gibberish from Akko, or Constanze made it using her machine. But since I know what Akko did, I can just list down all possible strings that Constanze's machine would have turned into the message I got and see if anything makes sense. But I need to know how much paper I will need, and that's why I'm asking you for help. Tell me the number of strings that Constanze's machine would've turned into the message I got. But since this number can be quite large, tell me instead its remainder when divided by 109+7. If there are no strings that Constanze's machine would've turned into the message I got, then print 0.

// Input
// Input consists of a single line containing a string s (1≤|s|≤105) — the received message. s contains only lowercase Latin letters.

// Output
// Print a single integer — the number of strings that Constanze's machine would've turned into the message s, modulo 109+7.

// Examples
// inputCopy
// ouuokarinn
// outputCopy
// 4
// inputCopy
// banana
// outputCopy
// 1
// inputCopy
// nnn
// outputCopy
// 3
// inputCopy
// amanda
// outputCopy
// 0

// Note
// For the first example, the candidate strings are the following: "ouuokarinn", "ouuokarim", "owokarim", and "owokarinn".
// For the second example, there is only one: "banana".
// For the third example, the candidate strings are the following: "nm", "mn" and "nnn".
// For the last example, there are no candidate strings that the machine can turn into "amanda", since the machine won't inscribe 'm'.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define vll vector<long long int>
// #define forn(i,n) for(int i=0; i<n; i++)

// long long int mod = 1e9+7;
// void solve()
// {
//     string s;
//     cin >> s;

//     int misprintCount = 0;
//     int triplets = 0;
//     for(int i=1; i<s.size(); i++)
//     {
//         if(s[i]=='m' || s[i]=='w')
//         {
//             cout << "0" << endl;
//             return;
//         }
//         else if((s[i-1]=='n' && s[i]=='n'))
//         {
//             if(s[i+1]=='n' && i<s.size()-1)
//             {
//                 triplets++;
//             }

//             misprintCount++;
//         }
//         else if(s[i-1]=='u' && s[i]=='u')
//         {
//             if(s[i+1]=='u' && i<s.size()-1)
//             {
//                 triplets++;
//             }

//             misprintCount++;
//         }
//     }

//     long long int stringCount = ((int)pow(2,misprintCount-triplets) + triplets*3)%mod;
//     cout << stringCount << endl;

//     return;
// }

// int32_t main()
// {
//     fastio;
//     solve();

//     return 0;
// }

//Alternate soln(tutorial help) -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vll vector<long long int>
#define forn(i,n) for(int i=0; i<n; i++)

long long int N = 1000000007;

int32_t main()
{
    fastio;
    
    string s;
    cin >> s;

    for(char x: s)
    {
        if(x=='m' || x=='w')
        {
            cout << "0" << endl;
            return 0;
        }
    }

    int n = s.size();
    vector<int> dp(n+1);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<n; i++)
    {
        dp[i] = dp[i-1];
        if(s[i-1]==s[i-2] && (s[i-1]=='n' || s[i-1]=='u'))
        {
            dp[i] = (dp[i] + dp[i-2])%N;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
