// B. Sequence Game

// time limit per test2 seconds
// memory limit per test256 megabytes

// Tema and Vika are playing the following game. First, Vika comes up with a sequence of positive integers a of length m and writes it down on a piece of paper. Then she takes a new piece of paper and writes down the sequence b according to the following rule: First, she writes down a1. Then, she writes down only those ai (2≤i≤m) such that ai−1≤ai. Let the length of this sequence be denoted as n. For example, from the sequence a=[4,3,2,6,3,3], Vika will obtain the sequence b=[4,6,3]. She then gives the piece of paper with the sequence b to Tema. He, in turn, tries to guess the sequence a. Tema considers winning in such a game highly unlikely, but still wants to find at least one sequence a that could have been originally chosen by Vika. Help him and output any such sequence. Note that the length of the sequence you output should not exceed the input sequence length by more than two times.

// Input
// Each test consists of multiple test cases. The first line of input data contains a single integer t (1≤t≤104) — the number of test cases. This is followed by a description of the test cases. The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of the sequence b. The second line of each test case contains n integers b1,b2,b3,…,bn (1≤bi≤109) — the elements of the sequence. The sum of the values of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output two lines. In the first line, output a single integer m — the length of the sequence (n≤m≤2⋅n). In the second line, output m integers a1,a2,a3,…,am (1≤ai≤109) — the assumed sequence that Vika could have written on the first piece of paper. If there are multiple suitable sequences, you can output any of them.

// Example
// InputCopy
// 6
// 3
// 4 6 3
// 3
// 1 2 3
// 5
// 1 7 9 5 7
// 1
// 144
// 2
// 1 1
// 5
// 1 2 2 1 1
// OutputCopy
// 6
// 4 3 2 6 3 3
// 3
// 1 2 3
// 6
// 1 7 9 3 5 7
// 1
// 144
// 2
// 1 1
// 6
// 1 2 2 1 1 1

// Note
// The first sample is explained in the problem statement.
// In the second sample, Vika could have chosen the original sequence.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> b(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> b[i];
//     }

//     reverse(b.begin(), b.end());
//     stack<ll int> st;
//     st.push(b[0]);
//     for (int i = 0; i < n - 1; i++)
//     {
//         st.push(b[i]);
//         if (b[i] < b[i + 1])
//         {
//             st.push(b[i] - 1);
//         }
//     }

//     cout << st.size() << endl;
//     while (!st.empty())
//     {
//         ll int topp = st.top();
//         st.pop();
//         cout << topp << " ";
//     }

//     cout << endl;
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

// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> b(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> b[i];
//     }

//     vector<ll int> a; // Sequence a to be constructed

//     a.push_back(b[0]); // Start with the first element of b

//     for (int i = 1; i < n; ++i)
//     {
//         if(b[i-1]>b[i])
//         {
//             a.push_back(b[i]-1); // Insert the previous element if it drops
//         }
//         a.push_back(b[i]); // Always insert the current element
//     }

//     cout << a.size() << endl;
//     for(int i=0; i<a.size(); i++)
//     {
//         if(i==0)
//         {
//             cout << a[i];
//         }
//         else
//         {
//             cout << " " << a[i];
//         }
//     }

//     cout << endl;
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

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;

            //If it's not the first element
            //AND the current element x is smaller than the last element in a
            //We insert an extra "1"
            if (i > 0 && a.back() > x)
            {
                a.push_back(1);
            }

            //Adding the current element x to sequence a
            a.push_back(x);
        }

        cout << a.size() << "\n";
        for (int x : a)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}
