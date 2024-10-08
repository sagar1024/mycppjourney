// B. Playing in a Casino

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Galaxy Luck, a well-known casino in the entire solar system, introduces a new card game. In this game, there is a deck that consists of n cards. Each card has m numbers written on it. Each of the n players receives exactly one card from the deck. Then all players play with each other in pairs, and each pair of players plays exactly once. Thus, if there are, for example, four players in total, then six games are played: the first against the second, the first against the third, the first against the fourth, the second against the third, the second against the fourth and the third against the fourth. Each of these games determines the winner in some way, but the rules are quite complicated, so we will not describe them here. All that matters is how many chips are paid out to the winner. Let the first player's card have the numbers a1,a2,…,am, and the second player's card — b1,b2,…,bm. Then the winner of the game gets |a1−b1|+|a2−b2|+⋯+|am−bm| chips from the total pot, where |x| denotes the absolute value of x. To determine the size of the total pot, it is necessary to calculate the winners' total winnings for all games. Since there can be many cards in a deck and many players, you have been assigned to write a program that does all the necessary calculations.

// Input
// Each test consists of several test cases. The first line contains one integer t (1≤t≤1000) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers n and m (1≤n⋅m≤3⋅105) — the number of cards in the deck and the count of numbers on the one card. Each of the following n lines of the test case set contains m integers ci,j (1≤ci,j≤106) — a description of the i-th card. It is guaranteed that the total n⋅m in all tests does not exceed 3⋅105.

// Output
// For each test case, print one number — the total amount of winnings from all games.

// Example
// inputCopy
// 3
// 3 5
// 1 4 2 8 5
// 7 9 2 1 4
// 3 8 5 3 1
// 1 4
// 4 15 1 10
// 4 3
// 1 2 3
// 3 2 1
// 1 2 1
// 4 2 7
// outputCopy
// 50
// 0
// 31

// Note
// Consider the first test case.
// In the game between the first and second player, the winner receives |1−7|+|4−9|+|2−2|+|8−1|+|5−4|=19 chips.
// In the game between the first and third player, the winner receives |1−3|+|4−8|+|2−5|+|8−3|+|5−1|=18 in chips.
// In the game between the second and third player, the winner receives |7−3|+|9−8|+|2−5|+|1−3|+|4−1|=13 chips.
// The total is 19+18+13=50 chips.

// My original soln(tle on tc4) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<long int>> cardDescription(n, vector<long int>(m));
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
//             cin >> cardDescription[i][j];
//         }
//     }

//     long long int sum = 0;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i+1; j<n; j++)
//         {
//             for(int k=0; k<m; k++)
//             {
//                 sum += abs(cardDescription[i][k] - cardDescription[j][k]);
//             }
//         }
//     }

//     cout << sum << endl;
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
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> cardDescription(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> cardDescription[i][j];
        }
    }

    long long totalWinnings = 0;
    for (int j = 0; j < m; j++)
    {
        vector<int> column(n);
        for (int i = 0; i < n; i++)
        {
            column[i] = cardDescription[i][j];
        }

        //Sorting the column
        sort(column.begin(), column.end());
        long long prefixSum = 0;
        for (int i = 0; i < n; i++)
        {
            //For column[i], there are i numbers before it (smaller)
            //And n-i-1 numbers after it (larger)
            totalWinnings += (long long)column[i] * i - prefixSum;
            prefixSum += column[i];
        }
    }

    cout << totalWinnings << endl;
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

