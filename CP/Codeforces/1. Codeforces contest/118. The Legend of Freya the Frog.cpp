// C. The Legend of Freya the Frog

// time limit per test2 seconds
// memory limit per test256 megabytes

// Freya the Frog is traveling on the 2D coordinate plane. She is currently at point (0,0) and wants to go to point (x,y). In one move, she chooses an integer d such that 0≤d≤k and jumps d spots forward in the direction she is facing. Initially, she is facing the positive x direction. After every move, she will alternate between facing the positive x direction and the positive y direction (i.e., she will face the positive y direction on her second move, the positive x direction on her third move, and so on). What is the minimum amount of moves she must perform to land on point (x,y)?

// Input
// The first line contains an integer t (1≤t≤104) — the number of test cases. Each test case contains three integers x, y, and k (0≤x,y≤109,1≤k≤109).

// Output
// For each test case, output the number of jumps Freya needs to make on a new line.

// Example
// InputCopy
// 3
// 9 11 3
// 0 10 8
// 1000000 100000 10

// OutputCopy
// 8
// 4
// 199999

// Note
// In the first sample, one optimal set of moves is if Freya jumps in the following way: (0,0) → (2,0) → (2,2) → (3,2) → (3,5) → (6,5) → (6,8) → (9,8) → (9,11). This takes 8 jumps.

//My original soln -

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long x, y, k;
    cin >> x >> y >> k;

    long long moves = 0;
    long long current_x = 0, current_y = 0;

    while (current_x < x || current_y < y)
    {
        if (moves % 2 == 0)
        {
            long long distance = min(k, x - current_x);
            current_x += distance;
        }
        else
        {
            long long distance = min(k, y - current_y);
            current_y += distance;
        }
        moves++;
    }

    cout << moves << endl;
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
