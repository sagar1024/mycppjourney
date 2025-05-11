// A. LRC and VIP

// time limit per test1 second
// memory limit per test256 megabytes

// You have an array a of size n — a1,a2,…an. You need to divide the n elements into 2 sequences B and C, satisfying the following conditions: Each element belongs to exactly one sequence. Both sequences B and C contain at least one element. Here, gcd (B1,B2,…,B|B|)≠gcd(C1,C2,…,C|C|) gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows. The first line of each test case contains an integer n (2≤n≤100). The second line of each test case contains n integers a1,a2,…,an (1≤ai≤104).

// Output
// For each test case, first output Yes if a solution exists or No if no solution exists. You may print each character in either case, for example YES and yEs will also be accepted. Only when there is a solution, output n integers on the second line. The i-th number should be either 1 or 2. 1 represents that the element belongs to sequence B and 2 represents that the element belongs to sequence C. You should guarantee that 1 and 2 both appear at least once.

// Example
// InputCopy
// 3
// 4
// 1 20 51 9
// 4
// 5 5 5 5
// 3
// 1 2 2
// OutputCopy
// Yes
// 2 2 1 1
// No
// Yes
// 1 2 2

// Note
// In the first test case, B=[51,9] and C=[1,20]. You can verify gcd(B1,B2)=3≠1=gcd(C1,C2).
// In the second test case, it is impossible to find a solution. For example, suppose you distributed the first 3 elements to array B and then the last element to array C. You have B=[5,5,5] and C=[5], but gcd(B1,B2,B3)=5=gcd(C1). Hence it is invalid.

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll> a(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     for (int mask = 1; mask < (1 << n) - 1; mask++)
//     {
//         vector<ll> B, C;
//         for (int i = 0; i < n; i++)
//         {
//             if ((mask >> i) & 1)
//                 B.push_back(a[i]);
//             else
//                 C.push_back(a[i]);
//         }

//         int g1 = B[0];
//         for (int i = 1; i < B.size(); i++)
//             g1 = __gcd(g1, (int)B[i]);

//         int g2 = C[0];
//         for (int i = 1; i < C.size(); i++)
//             g2 = __gcd(g2, (int)C[i]);

//         if (g1 != g2)
//         {
//             cout << "Yes\n";
//             for (int i = 0; i < n; i++)
//             {
//                 if ((mask >> i) & 1)
//                     cout << "1 ";
//                 else
//                     cout << "2 ";
//             }
//             cout << "\n";
//             return;
//         }
//     }

//     cout << "No\n";
//     return;
// }

// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternating soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bool all_same = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
        {
            all_same = false;
            break;
        }
    }

    if (all_same)
    {
        cout << "No" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int gcd_b = a[i];
        int gcd_c = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (gcd_c == 0)
                {
                    gcd_c = a[j];
                }
                else
                {
                    gcd_c = __gcd(gcd_c, a[j]);
                }
            }
        }

        if (gcd_b != gcd_c)
        {
            cout << "Yes" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << (j == i ? 1 : 2);
                if (j < n - 1)
                    cout << " ";
            }
            cout << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int gcd_b = __gcd(a[i], a[j]);
            int gcd_c = 0;
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    if (gcd_c == 0)
                    {
                        gcd_c = a[k];
                    }
                    else
                    {
                        gcd_c = __gcd(gcd_c, a[k]);
                    }
                }
            }

            if (gcd_c == 0)
                continue;

            if (gcd_b != gcd_c)
            {
                cout << "Yes" << endl;
                for (int k = 0; k < n; k++)
                {
                    cout << ((k == i || k == j) ? 1 : 2);
                    if (k < n - 1)
                        cout << " ";
                }
                cout << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
