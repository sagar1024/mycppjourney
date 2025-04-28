// C. Card Game

// time limit per test2 seconds
// memory limit per test512 megabytes

// Alice and Bob are playing a game. They have n cards numbered from 1 to n. At the beginning of the game, some of these cards are given to Alice, and the rest are given to Bob. Card with number i beats card with number j if and only if i>j, with one exception: card 1 beats card n. The game continues as long as each player has at least one card. During each turn, the following occurs:
// Alice chooses one of her cards and places it face up on the table. Bob, seeing Alice's card, chooses one of his cards and places it face up on the table; if Alice's card beats Bob's card, both cards are taken by Alice. Otherwise, both cards are taken by Bob. A player can use a card that they have taken during one of the previous turns. The player who has no cards at the beginning of a turn loses. Determine who will win if both players play optimally.

// Input
// The first line contains a single integer t (1≤t≤5000) — the number of test cases. Each test case consists of two lines:
// the first line contains a single integer n (2≤n≤50) — the number of cards;
// the second line contains n characters, each either A or B. If the i-th character is A, then card number i is initially given to Alice; otherwise, it is given to Bob.

// Additional constraint on the input: in each test case, at least one card is initially given to Alice, and at least one card is initially given to Bob.

// Output
// For each test case, output Alice if Alice wins with optimal play, or Bob if Bob wins. It can be shown that if both players play optimally, the game will definitely end in a finite number of turns with one of the players winning.

// Example
// InputCopy
// 8
// 2
// AB
// 2
// BA
// 4
// ABAB
// 4
// BABA
// 3
// BAA
// 5
// AAAAB
// 5
// BAAAB
// 6
// BBBAAA
// OutputCopy
// Alice
// Bob
// Bob
// Bob
// Alice
// Alice
// Bob
// Alice

// Note
// In the first test case, Alice has only one card, and Bob has only one card. Since Alice's card beats Bob's card, she wins after the first turn.
// In the second test case, Alice has only one card, and Bob has only one card. Since Bob's card beats Alice's card, he wins after the first turn.

// In the third test case, there are two possible game scenarios:
// if Alice plays the card 1 on the first turn, Bob can respond with the card 2 and take both cards. Then, Alice has to play the card 3 on the second turn, and Bob will respond by playing the card 4. Then, he wins;
// if Alice plays the card 3 on the first turn, Bob can respond with the card 4 and take both cards. Then, Alice has to play the card 1, and Bob can respond either with the card 2 or the card 3. Then, he wins.

// In the fourth test case, there are two possible game scenarios:
// if Alice plays the card 2 on the first turn, Bob can respond with the card 3 and take both cards. Then, Alice has to play the card 4 on the second turn, and Bob will respond by playing the card 1. Then, he wins;
// if Alice plays the card 4 on the first turn, Bob can respond with the card 1 and take both cards. Then, Alice has to play the card 2, and Bob can respond either with the card 3 or the card 4. Then, he wins.

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     multiset<int> alice, bob;
//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] == 'A')
//             alice.insert(i + 1);
//         else
//             bob.insert(i + 1);
//     }

//     while (!alice.empty() && !bob.empty())
//     {
//         // Alice chooses a card
//         int alice_card;
//         if (alice.count(1) && bob.count(n))
//         {
//             alice_card = 1;
//             alice.erase(alice.find(1));
//         }
//         else
//         {
//             alice_card = *prev(alice.end());
//             alice.erase(prev(alice.end()));
//         }

//         // Bob responds
//         int bob_card;
//         if (bob.count(1) && alice_card == n)
//         {
//             bob_card = 1;
//             bob.erase(bob.find(1));
//         }
//         else
//         {
//             bob_card = *prev(bob.end());
//             bob.erase(prev(bob.end()));
//         }

//         // Determine who wins the fight
//         bool alice_wins = false;

//         if (alice_card == 1 && bob_card == n)
//             alice_wins = true; // special rule
//         else if (bob_card == 1 && alice_card == n)
//             alice_wins = false; // special rule inverted
//         else if (alice_card > bob_card)
//             alice_wins = true;
//         else
//             alice_wins = false;

//         if (alice_wins)
//         {
//             alice.insert(alice_card);
//             alice.insert(bob_card);
//         }
//         else
//         {
//             bob.insert(alice_card);
//             bob.insert(bob_card);
//         }
//     }

//     if (alice.empty())
//         cout << "Bob" << endl;
//     else
//         cout << "Alice" << endl;

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

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n == 2)
    {
        if (s[0] == 'A' || s[1] == 'A')
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
        return;
    }

    if (n == 3)
    {
        int cntA = 0, cntB = 0;
        for (int i = 0; i < 3; i++)
        {
            if (s[i] == 'A')
                cntA++;
            else
                cntB++;
        }
        if (cntA > cntB)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
        return;
    }

    bool alice1 = (s[0] == 'A');
    bool alice2 = (s[1] == 'A');
    bool alice_n1 = (s[n - 2] == 'A');
    bool alice_n = (s[n - 1] == 'A');
    if (alice_n && !alice_n1)
    {
        cout << "Alice" << endl;
    }
    else if (!alice_n && alice_n1)
    {
        cout << "Bob" << endl;
    }
    else if (alice_n && alice_n1)
    {
        cout << "Alice" << endl;
    }
    else
    {
        if (alice1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
