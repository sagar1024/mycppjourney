// C. XOR-distance

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given integers a, b, r. Find the smallest value of |(a⊕x)−(b⊕x)| among all 0≤x≤r. ⊕ is the operation of bitwise XOR, and |y| is absolute value of y.

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. Each test case contains integers a, b, r (0≤a,b,r≤1018).

// Output
// For each test case, output a single number — the smallest possible value.

// Example
// InputCopy
// 10
// 4 6 0
// 0 3 2
// 9 6 10
// 92 256 23
// 165 839 201
// 1 14 5
// 2 7 2
// 96549 34359 13851
// 853686404475946 283666553522252166 127929199446003072
// 735268590557942972 916721749674600979 895150420120690183
// OutputCopy
// 2
// 1
// 1
// 164
// 542
// 5
// 3
// 37102
// 27934920819538516
// 104449824168870225

// Note
// In the first test, when r=0, then x is definitely equal to 0, so the answer is |4⊕0−6⊕0|=|4−6|=2.

// In the second test:
// When x=0, |0⊕0−3⊕0|=|0−3|=3.
// When x=1, |0⊕1−3⊕1|=|1−2|=1.
// When x=2, |0⊕2−3⊕2|=|2−1|=1.
// Therefore, the answer is 1.

// In the third test, the minimum is achieved when x=1.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     ll int a, b, r;
//     cin >> a >> b >> r;

//     ll int ans = 0;
//     for(int i=0; i<r; i++)
//     {
//         //God knows what next
//     }
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
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_BITS = 60;

bool get_bit(ll a, int i)
{
    return a & (1LL << i);
}

void solve()
{
    ll a, b, r;
    cin >> a >> b >> r;

    ll x = 0;
    bool first_bit = true;

    if (a > b)
        swap(a, b);

    for (int i = MAX_BITS - 1; i >= 0; i--)
    {
        bool bit_a = get_bit(a, i);
        bool bit_b = get_bit(b, i);

        if (bit_a != bit_b)
        {
            if (first_bit)
            {
                first_bit = false; //Skip the most significant differing bit
            }
            else
            {
                if (!bit_a && x + (1LL << i) <= r)
                {
                    x += (1LL << i);
                    a ^= (1LL << i);
                    b ^= (1LL << i);
                }
            }
        }
    }

    cout << b - a << endl;
    return;
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
