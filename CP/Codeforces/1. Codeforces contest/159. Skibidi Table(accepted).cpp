// D. Skibidi Table

// time limit per test2 seconds
// memory limit per test256 megabytes

// Vadim loves filling square tables with integers. But today he came up with a way to do it for fun! Let's take, for example, a table of size 2×2, with rows numbered from top to bottom and columns numbered from left to right. We place 1 in the top left cell, 2 in the bottom right, 3 in the bottom left, and 4 in the top right. That's all he needs for fun! Fortunately for Vadim, he has a table of size 2n×2n. He plans to fill it with integers from 1 to 22n in ascending order. To fill such a large table, Vadim will divide it into 4 equal square tables, filling the top left one first, then the bottom right one, followed by the bottom left one, and finally the top right one. Each smaller table will be divided into even smaller ones as he fills them until he reaches tables of size 2×2, which he will fill in the order described above. Now Vadim is eager to start filling the table, but he has q questions of two types: what number will be in the cell at the x-th row and y-th column;in which cell coordinates will the number d be located. Help answer Vadim's questions.

// Input
// Each test consists of several sets of input data. The first line contains a single integer t (1≤t≤10)  — the number of sets of input data. The following lines describe the input data sets. In the first line of each data set, there is an integer n, describing the size of the table (1≤n≤30). In the second line of each data set, there is an integer q  — the number of questions (1≤q≤20000). In the following q lines of each data set, the questions are described in the following formats:
// -> x y  — What number will be in the cell (1≤x,y≤2n);
// <- d  — In which cell coordinates will the number (1≤d≤22n) be located.

// It is guaranteed that the sum of q over all test cases does not exceed 20000.

// Output
// Output the answers to each question on a separate line.

// Example
// InputCopy
// 2
// 2
// 5
// -> 4 3
// <- 15
// <- 4
// -> 3 1
// -> 1 3
// 1
// 8
// -> 1 1
// -> 1 2
// -> 2 1
// -> 2 2
// <- 1
// <- 2
// <- 3
// <- 4
// OutputCopy
// 7
// 2 3
// 1 2
// 9
// 13
// 1
// 4
// 3
// 2
// 1 1
// 2 2
// 2 1
// 1 2

// Note
// This is how the filled table from the first example looks: (diagram)

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll get_number(int n, ll x, ll y, ll base)
{
    if (n == 1)
    {
        // 2x2 base pattern
        if (x == 1 && y == 1) return base + 0;
        if (x == 2 && y == 2) return base + 1;
        if (x == 2 && y == 1) return base + 2;
        if (x == 1 && y == 2) return base + 3;
    }

    ll size = 1LL << (n - 1); //Half size
    ll add = 1LL << (2 * n - 2); //Offset added per quadrant
    if (x <= size && y <= size)
    {
        // Top-left
        return get_number(n - 1, x, y, base);
    }
    else if (x > size && y > size)
    {
        // Bottom-right
        return get_number(n - 1, x - size, y - size, base + add);
    }
    else if (x > size && y <= size)
    {
        // Bottom-left
        return get_number(n - 1, x - size, y, base + 2 * add);
    }
    else
    {
        // Top-right
        return get_number(n - 1, x, y - size, base + 3 * add);
    }
}

pair<ll, ll> get_position(int n, ll d, ll base, ll x_off, ll y_off)
{
    if (n == 1)
    {
        if (d == base + 0)
            return {x_off + 1, y_off + 1}; // (1,1)
        if (d == base + 1)
            return {x_off + 2, y_off + 2}; // (2,2)
        if (d == base + 2)
            return {x_off + 2, y_off + 1}; // (2,1)
        if (d == base + 3)
            return {x_off + 1, y_off + 2}; // (1,2)
    }

    ll add = 1LL << (2 * n - 2); //Elements in each sub-grid
    ll size = 1LL << (n - 1); //Half size

    if (d < base + add) return get_position(n - 1, d, base, x_off, y_off); //Top-left
    else if (d < base + 2 * add) return get_position(n - 1, d, base + add, x_off + size, y_off + size); //Bottom-right
    else if (d < base + 3 * add) return get_position(n - 1, d, base + 2 * add, x_off + size, y_off); //Bottom-left
    else return get_position(n - 1, d, base + 3 * add, x_off, y_off + size); //Top-right
}

void solve()
{
    int n, q;
    cin >> n >> q;

    while (q--)
    {
        string type;
        cin >> type;

        if (type == "->")
        {
            ll x, y;
            cin >> x >> y;
            cout << get_number(n, x, y, 1) << '\n';
        }
        else if (type == "<-")
        {
            ll d;
            cin >> d;
            auto [x, y] = get_position(n, d, 1, 0, 0);
            cout << x << ' ' << y << '\n';
        }
    }

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
