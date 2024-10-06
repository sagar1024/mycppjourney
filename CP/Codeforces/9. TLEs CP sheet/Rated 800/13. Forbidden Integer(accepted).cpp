// A. Forbidden Integer

// time limit per test2 seconds
// memory limit per test256 megabytes

// You are given an integer n, which you want to obtain. You have an unlimited supply of every integer from 1 to k, except integer x (there are no integer x at all). You are allowed to take an arbitrary amount of each of these integers (possibly, zero). Can you make the sum of taken integers equal to n? If there are multiple answers, print any of them.

// Input
// The first line contains a single integer t (1≤t≤100) — the number of testcases. The only line of each testcase contains three integers n,k and x (1≤x≤k≤n≤100).

// Output
// For each test case, in the first line, print "YES" or "NO" — whether you can take an arbitrary amount of each integer from 1 to k, except integer x, so that their sum is equal to n. If you can, the second line should contain a single integer m — the total amount of taken integers. The third line should contain m integers — each of them from 1 to k, not equal to x, and their sum is n. If there are multiple answers, print any of them.

// Example
// InputCopy
// 5
// 10 3 2
// 5 2 1
// 4 2 1
// 7 7 3
// 6 1 1
// OutputCopy
// YES
// 6
// 3 1 1 1 1 3
// NO
// YES
// 2
// 2 2
// YES
// 1
// 7
// NO

// Note
// Another possible answer for the first testcase is [3,3,3,1]. Note that you don't have to minimize the amount of taken integers. There also exist other answers.
// In the second testcase, you only have an unlimited supply of integer 2. There is no way to get sum 5 using only them.
// In the fifth testcase, there are no integers available at all, so you can't get any positive sum.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     int n, k, x;
//     cin >> n >> k >> x;

//     if (k == 1)
//     {
//         //Special case when k = 1, it's impossible to make any sum greater than 1 unless n == 1 and x != 1.
//         if (n == 1 && x != 1)
//         {
//             cout << "YES\n1\n1\n";
//         }
//         else
//         {
//             cout << "NO\n";
//         }
//         return;
//     }

//     //Collect all numbers from 1 to k excluding x
//     vector<int> valid_numbers;
//     for (int i = 1; i <= k; ++i)
//     {
//         if (i != x)
//             valid_numbers.push_back(i);
//     }

//     //Now check if we can form sum n with these valid numbers
//     int sum_of_valid = 0;
//     for (int num : valid_numbers)
//     {
//         sum_of_valid += num;
//     }

//     if (sum_of_valid >= n)
//     {
//         cout << "YES\n";
//         vector<int> result;

//         //Try to add the largest valid numbers first
//         int sum = 0;
//         for (int num : valid_numbers)
//         {
//             while (sum + num <= n)
//             {
//                 result.push_back(num);
//                 sum += num;
//             }
//         }

//         cout << result.size() << "\n";
//         for (int r : result)
//         {
//             cout << r << " ";
//         }

//         cout << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

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

using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1)
        {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 0; i < n; ++i)
            {
                cout << 1 << " ";
            }

            cout << endl;
        }
        else if (k == 1 || (k == 2 && n % 2 == 1))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            cout << (n % 2 == 1 ? 3 : 2) << " "; // Print 3 if n is odd, else print 2
            for (int i = 1; i < n / 2; ++i)
            {
                cout << 2 << " "; // Print remaining 2's
            }

            cout << endl;
        }
    }

    return 0;
}
