// B. Turtle and Piggy Are Playing a Game 2

// time limit per test1 second
// memory limit per test256 megabytes

// Turtle and Piggy are playing a game on a sequence. They are given a sequence a1,a2,…,an, and Turtle goes first. Turtle and Piggy alternate in turns (so, Turtle does the first turn, Piggy does the second, Turtle does the third, etc.). The game goes as follows: Let the current length of the sequence be m. If m=1, the game ends. If the game does not end and it's Turtle's turn, then Turtle must choose an integer i such that 1≤i≤m−1, set ai to max(ai,ai+1), and remove ai+1. If the game does not end and it's Piggy's turn, then Piggy must choose an integer i such that 1≤i≤m−1, set ai to min(ai,ai+1), and remove ai+1. Turtle wants to maximize the value of a1 in the end, while Piggy wants to minimize the value of a1 in the end. Find the value of a1 in the end if both players play optimally. You can refer to notes for further clarification.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first line of each test case contains a single integer n (2≤n≤105) — the length of the sequence. The second line of each test case contains n integers a1,a2,…,an (1≤ai≤105) — the elements of the sequence a. It is guaranteed that the sum of n over all test cases does not exceed 105.

// Output
// For each test case, output a single integer — the value of a1 in the end if both players play optimally.

// Example
// InputCopy
// 5
// 2
// 1 2
// 3
// 1 1 2
// 3
// 1 2 3
// 5
// 3 1 2 2 3
// 10
// 10 2 5 2 7 9 2 5 10 7
// OutputCopy
// 2
// 1
// 2
// 2
// 7

// Note
// In the first test case, initially a=[1,2]. Turtle can only choose i=1. Then he will set a1 to max(a1,a2)=2 and remove a2. The sequence a becomes [2]. Then the length of the sequence becomes 1, and the game will end. The value of a1 is 2, so you should output 2.

// In the second test case, one of the possible game processes is as follows:
// Initially a=[1,1,2].
// Turtle can choose i=2. Then he will set a2 to max(a2,a3)=2 and remove a3. The sequence a will become [1,2].
// Piggy can choose i=1. Then he will set a1 to min(a1,a2)=1 and remove a2. The sequence a will become [1].
// The length of the sequence becomes 1, so the game will end. The value of a1 will be 1 in the end.
// In the fourth test case, one of the possible game processes is as follows:

// Initially a=[3,1,2,2,3].
// Turtle can choose i=4. Then he will set a4 to max(a4,a5)=3 and remove a5. The sequence a will become [3,1,2,3].
// Piggy can choose i=3. Then he will set a3 to min(a3,a4)=2 and remove a4. The sequence a will become [3,1,2].
// Turtle can choose i=2. Then he will set a2 to max(a2,a3)=2 and remove a3. The sequence a will become [3,2].
// Piggy can choose i=1. Then he will set a1 to min(a1,a2)=2 and remove a2. The sequence a will become [2].
// The length of the sequence becomes 1, so the game will end. The value of a1 will be 2 in the end.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    cout << a[n/2] << endl;

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
