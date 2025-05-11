// D. Card Game

// time limit per test2 seconds
// memory limit per test256 megabytes

// Two players are playing an online card game. The game is played using a 32-card deck. Each card has a suit and a rank. There are four suits: clubs, diamonds, hearts, and spades. We will encode them with characters 'C', 'D', 'H', and 'S', respectively. And there are 8 ranks, in increasing order: '2', '3', '4', '5', '6', '7', '8', '9'. Each card is denoted by two letters: its rank and its suit. For example, the 8 of Hearts is denoted as 8H. At the beginning of the game, one suit is chosen as the trump suit. In each round, players make moves like this: the first player places one of his cards on the table, and the second player must beat this card with one of their cards. After that, both cards are moved to the discard pile. A card can beat another card if both cards have the same suit and the first card has a higher rank than the second. For example, 8S can beat 4S. Additionally, a trump card can beat any non-trump card, regardless of the rank of the cards, for example, if the trump suit is clubs ('C'), then 3C can beat 9D. Note that trump cards can be beaten only by the trump cards of higher rank. There were n rounds played in the game, so the discard pile now contains 2n cards. You want to reconstruct the rounds played in the game, but the cards in the discard pile are shuffled. Find any possible sequence of n rounds that might have been played in the game.

// Input
// The first line contains integer t (1≤t≤100) — the number of test cases. Then t test cases follow. The first line of a test case contains the integer number n (1≤n≤16). The second line of a test case contains one character, the trump suit. It is one of "CDHS". The third line of a test case contains the description of 2n cards. Each card is described by a two-character string, the first character is the rank of the card, which is one of "23456789", and the second one is the suit of the card, which is one of "CDHS". All cards are different.

// Output
// For each test case print the answer to it: Print n lines. In each line, print the description of two cards, in the same format as in the input: the first card that was played by the first player, and then the card that was used by the second player to beat it. If there is no solution, print a single line "IMPOSSIBLE". If there are multiple solutions, print any of them.

// Example
// InputCopy
// 8
// 3
// S
// 3C 9S 4C 6D 3S 7S
// 2
// C
// 3S 5D 9S 6H
// 1
// H
// 6C 5D
// 1
// S
// 7S 3S
// 1
// H
// 9S 9H
// 1
// S
// 9S 9H
// 1
// C
// 9D 8H
// 2
// C
// 9C 9S 6H 8C
// OutputCopy
// 3C 4C
// 6D 9S
// 3S 7S
// IMPOSSIBLE
// IMPOSSIBLE
// 3S 7S
// 9S 9H
// 9H 9S
// IMPOSSIBLE
// 6H 9C
// 9S 8C

// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// int get_rank(char r)
// {
//     return r - '0'; // since ranks are from '2' to '9'
// }

// bool can_beat(string a, string b, char trump)
// {
//     char rankA = a[0], suitA = a[1];
//     char rankB = b[0], suitB = b[1];
//     if (suitA == suitB)
//         return get_rank(rankA) > get_rank(rankB);
//     if (suitA == trump && suitB != trump)
//         return true;
//     return false;
// }

// bool backtrack(vector<string> &cards, char trump, vector<pair<string, string>> &result, vector<bool> &used, int n)
// {
//     if (result.size() == n) return true;
//     for (int i = 0; i < cards.size(); ++i)
//     {
//         if (used[i]) continue;
//         for (int j = 0; j < cards.size(); ++j)
//         {
//             if (i == j || used[j]) continue;
//             string first = cards[i];
//             string second = cards[j];
//             if (can_beat(second, first, trump))
//             {
//                 used[i] = used[j] = true;
//                 result.push_back({first, second});

//                 if (backtrack(cards, trump, result, used, n)) return true;
//                 result.pop_back();
//                 used[i] = used[j] = false;
//             }
//         }
//     }

//     return false;
// }

// void solve()
// {
//     int n;
//     cin >> n;

//     char trump;
//     cin >> trump;

//     vector<string> cards(2 * n);
//     for (int i = 0; i < 2 * n; ++i)
//     {
//         cin >> cards[i];
//     }

//     vector<bool> used(2 * n, false);
//     vector<pair<string, string>> result;
//     if (backtrack(cards, trump, result, used, n))
//     {
//         for (auto &p : result)
//         {
//             cout << p.first << " " << p.second << "\n";
//         }
//     }
//     else
//     {
//         cout << "IMPOSSIBLE\n";
//     }

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

// Alternate soln -

// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// int rank_value(char r)
// {
//     return r - '0'; //Ranks are '2' to '9'
// }

// bool can_beat(const string &attacker, const string &defender, char trump)
// {
//     char ra = attacker[0], sa = attacker[1];
//     char rd = defender[0], sd = defender[1];
//     if (sa == sd) return rank_value(ra) > rank_value(rd);
//     if (sa == trump && sd != trump) return true;

//     return false;
// }

// bool find_pairs(vector<string> &cards, char trump, vector<bool> &used, vector<pair<string, string>> &result, int n)
// {
//     if (result.size() == n) return true;
//     for (int i = 0; i < cards.size(); ++i)
//     {
//         if (used[i]) continue;
//         for (int j = 0; j < cards.size(); ++j)
//         {
//             if (i == j || used[j]) continue;
//             string a = cards[i], b = cards[j];
//             if (can_beat(b, a, trump))
//             {
//                 used[i] = used[j] = true;
//                 result.push_back({a, b});

//                 if (find_pairs(cards, trump, used, result, n)) return true;
//                 result.pop_back();
//                 used[i] = used[j] = false;
//             }
//         }
//     }

//     return false;
// }

// void solve()
// {
//     int n;
//     cin >> n;

//     char trump;
//     cin >> trump;

//     vector<string> cards(2 * n);
//     for (int i = 0; i < 2 * n; ++i)
//         cin >> cards[i];

//     vector<bool> used(2 * n, false);
//     vector<pair<string, string>> result;
//     if (find_pairs(cards, trump, used, result, n))
//     {
//         for (auto &p : result)
//         {
//             cout << p.first << " " << p.second << "\n";
//         }
//     }
//     else
//     {
//         cout << "IMPOSSIBLE\n";
//     }

//     return;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string suites = "CDHS";

    string ts;
    cin >> ts;
    
    int trump = suites.find(ts[0]);
    vector<int> bs[4];
    for (int i = 0; i < 2 * n; i++)
    {
        string s;
        cin >> s;
        bs[suites.find(s[1])].push_back(s[0] - '2');
    }

    vector<string> res;
    vector<string> left;
    for (int i = 0; i < 4; i++)
    {
        sort(bs[i].begin(), bs[i].end());
        if (i == trump)
            continue;
        if (bs[i].size() % 2 == 1)
        {
            int x = bs[i].back();
            left.push_back(string() + char('2' + x) + suites[i]);
            bs[i].pop_back();
        }
        for (int j = 0; j < (int)bs[i].size(); j++)
        {
            int x = bs[i][j];
            res.push_back(string() + char('2' + x) + suites[i]);
        }
    }

    if ((int)left.size() > (int)bs[trump].size())
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (string s : left)
        {
            res.push_back(s);
            int x = bs[trump].back();
            bs[trump].pop_back();
            res.push_back(string() + char('2' + x) + suites[trump]);
        }
        for (int j = 0; j < (int)bs[trump].size(); j++)
        {
            int x = bs[trump][j];
            res.push_back(string() + char('2' + x) + suites[trump]);
        }
        for (int i = 0; i < 2 * n; i += 2)
        {
            cout << res[i] << " " << res[i + 1] << "\n";
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
