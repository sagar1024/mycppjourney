// E. Anna and the Valentine's Day Gift

// time limit per test2 seconds
// memory limit per test256 megabytes

// Sasha gave Anna a list a of n integers for Valentine's Day. Anna doesn't need this list, so she suggests destroying it by playing a game. Players take turns. Sasha is a gentleman, so he gives Anna the right to make the first move. On her turn, Anna must choose an element ai from the list and reverse the sequence of its digits. For example, if Anna chose the element with a value of 42, it would become 24; if Anna chose the element with a value of 1580, it would become 851. Note that leading zeros are removed. After such a turn, the number of elements in the list does not change. On his turn, Sasha must extract two elements ai and aj (i≠j) from the list, concatenate them in any order and insert the result back into the list. For example, if Sasha chose the elements equal to 2007 and 19, he would remove these two elements from the list and add the integer 200719 or 192007. After such a turn, the number of elements in the list decreases by 1. Players can't skip turns. The game ends when Sasha can't make a move, i.e. after Anna's move there is exactly one number left in the list. If this integer is not less than 10m (i.e., ≥10m), Sasha wins. Otherwise, Anna wins. It can be shown that the game will always end. Determine who will win if both players play optimally.

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. Then follows the description of the test cases. The first line of each test case contains integers n, m (1≤n≤2⋅105, 0≤m≤2⋅106) — the number of integers in the list and the parameter determining when Sasha wins. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the list that Sasha gave to Anna. It is guaranteed that the sum of n for all test cases does not exceed 2⋅105.

// Output
// For each test case, output:
// "Sasha", if Sasha wins with optimal play;
// "Anna", if Anna wins with optimal play.

// Example
// InputCopy
// 9
// 2 2
// 14 2
// 3 5
// 9 56 1
// 4 10
// 1 2007 800 1580
// 4 5
// 5000 123 30 4
// 10 10
// 6 4 6 2 3 1 10 9 10 7
// 1 1
// 6
// 1 1
// 10
// 8 9
// 1 2 9 10 10 2 10 2
// 4 5
// 10 10 10 10
// OutputCopy
// Sasha
// Anna
// Anna
// Sasha
// Sasha
// Anna
// Anna
// Anna
// Sasha

// Note
// Consider the first test case.
// Anna can reverse the integer 2, then Sasha can concatenate the integers 2 and 14, obtaining the integer 214, which is greater than 102=100. If Anna had reversed the integer 14, Sasha would have concatenated the integers 41 and 2, obtaining the integer 412, which is greater than 102=100. Anna has no other possible moves, so she loses.

// My original soln(wrong ans on tc3) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<ll> a(n);
//     vector<pair<int, ll>> trailingZeros; //{zeroCount,element}
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         if (a[i] % 10 == 0)
//         {
//             int x = a[i];
//             int count = 0;
//             while (x % 10 == 0)
//             {
//                 count++;
//                 x /= 10;
//             }
//             trailingZeros.push_back({count, a[i]});
//         }
//     }

//     //MAIN logic
//     // sort(a.begin(), a.end());
//     sort(trailingZeros.begin(), trailingZeros.end(), greater<pair<int, ll>>());
//     int ans = 0;
//     for (int i = 0; i < trailingZeros.size(); i++)
//     {
//         if (i < (trailingZeros.size() + 1) / 2)
//         {
//             int x = trailingZeros[i].second;
//             while (x % 10 == 0)
//             {
//                 x /= 10;
//             }

//             string x2 = to_string(x);
//             ans += x2.size();
//         }
//         else
//         {
//             int y = trailingZeros[i].second;
//             string y2 = to_string(y);

//             ans += y2.size();
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] % 10 != 0)
//         {
//             int x = a[i];
//             string x2 = to_string(x);
//             ans += x2.size();
//         }
//     }

//     if (ans <= m) cout << "Anna" << endl;
//     else cout << "Sasha" << endl;

//     return;
// }

// int32_t main()
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

#include <iostream>
#include <bits/stdc++.h>

#define all(arr) arr.begin(), arr.end()
using namespace std;

const int MAX_ELEMENTS = 200200;
int num_elements, threshold;
string elements[MAX_ELEMENTS];
int lengths[MAX_ELEMENTS], trailing_zeros[MAX_ELEMENTS];

void calculateTrailingZeros()
{
    memset(trailing_zeros, 0, sizeof(*trailing_zeros) * num_elements);
    for (int i = 0; i < num_elements; ++i)
    {
        lengths[i] = elements[i].size();
        for (auto it = elements[i].rbegin(); it != elements[i].rend() && *it == '0'; ++it)
        {
            ++trailing_zeros[i];
        }
    }
}

string determineWinner()
{
    int total_length_without_zeros = 0;
    for (int i = 0; i < num_elements; ++i)
    {
        total_length_without_zeros += lengths[i] - trailing_zeros[i];
    }

    sort(trailing_zeros, trailing_zeros + num_elements); //Only sorting first n elements
    reverse(trailing_zeros, trailing_zeros + num_elements);
    for (int i = 0; i < num_elements; ++i)
    {
        if (i % 2 == 1)
        {
            total_length_without_zeros += trailing_zeros[i];
        }
    }

    return (total_length_without_zeros - 1 < threshold ? "Anna" : "Sasha");
}

int main()
{
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        cin >> num_elements >> threshold;

        for (int i = 0; i < num_elements; ++i)
        {
            cin >> elements[i];
        }

        calculateTrailingZeros();
        cout << determineWinner() << endl;
    }

    return 0;
}
