// F. Sakurako's Box

// time limit per test2 seconds
// memory limit per test256 megabytes

// Sakurako has a box with n balls. Each ball has it's value. She wants to bet with her friend that if the friend randomly picks two balls from the box (it could be two distinct balls, but they may have the same value), the product of their values will be the same as the number that Sakurako guessed. Since Sakurako has a PhD in probability, she knows that the best number to pick is the expected value, but she forgot how to calculate it. Help Sakurako and find the expected value of the product of two elements from the array. It can be shown that the expected value has the form PQ, where P and Q are non-negative integers, and Q≠0. Report the value of P⋅Q−1(mod109+7).

// Input
// The first line contains a single integer t (1≤t≤104)  — the number of test cases. The first line of each test case contains a single integer n (2≤n≤2⋅105)  — the number of elements in the array. The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109)  — the elements of the array. It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output the value of P⋅Q−1(mod109+7).

// Example
// InputCopy
// 3
// 3
// 3 2 3
// 4
// 2 2 2 4
// 5
// 1 2 3 4 5
// OutputCopy
// 7
// 6
// 500000012

// Note
// For the first test, Sakurako's friend can pick these pairs of balls: (a1,a2), (a1,a3), (a2,a3). Their products equal to 3⋅2=6 , 3⋅3=9 , 3⋅2=6 respectively, so the expected value is 6+9+63=7.
// For the second test, Sakurako's friend can pick these pairs of balls: (a1,a2), (a1,a3), (a1,a4), (a2,a3), (a2,a4), (a3,a4). Their products equal to 2⋅2=4 , 2⋅2=4 , 2⋅4=8, 2⋅2=4, 2⋅4=8, 2⋅4=8 respectively, so the expected value is 4+4+8+4+8+86=366=6.

// My original soln -

// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <cassert>
// #include <bits/stdc++.h>

// const int MOD = 1000000007;

// //Function to compute modular inverse using Fermat's Little Theorem
// long long mod_inverse(long long a, long long mod)
// {
//     long long result = 1;
//     long long power = mod - 2;
//     while (power > 0)
//     {
//         if (power % 2 == 1)
//         {
//             result = (result * a) % mod;
//         }
//         a = (a * a) % mod;
//         power /= 2;
//     }

//     return result;
// }

// void solve()
// {
//     int t;
//     std::cin >> t;

//     while (t--)
//     {
//         int n;
//         std::cin >> n;

//         std::vector<long long> a(n);
//         long long sum_a = 0, sum_a2 = 0;
//         for (int i = 0; i < n; ++i)
//         {
//             std::cin >> a[i];
//             sum_a = (sum_a + a[i]) % MOD;
//             sum_a2 = (sum_a2 + a[i] * a[i]) % MOD;
//         }

//         long long total_pairs = (n * (n - 1) / 2) % MOD;
//         long long sum_of_products = (sum_a * sum_a - sum_a2 + MOD) % MOD;
//         sum_of_products = (sum_of_products * mod_inverse(2, MOD)) % MOD;
//         long long result = (sum_of_products * mod_inverse(total_pairs, MOD)) % MOD;

//         std::cout << result << std::endl;
//     }

//     return;
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     solve();
//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

const int MOD = 1000000007;

// Function to compute modular inverse using Fermat's Little Theorem
long long mod_inverse(long long a, long long mod)
{
    long long result = 1;
    long long power = mod - 2;
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        power /= 2;
    }
    return result;
}

void solve()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);

        long long sum_a = 0, sum_a2 = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
            sum_a = (sum_a + a[i]) % MOD;
            sum_a2 = (sum_a2 + a[i] * a[i]) % MOD;
        }

        long long total_pairs = (n * (n - 1) / 2) % MOD;
        long long sum_of_products = (sum_a * sum_a - sum_a2 + MOD) % MOD;
        sum_of_products = (sum_of_products * mod_inverse(2, MOD)) % MOD;

        long long total_pairs_inverse = mod_inverse(total_pairs, MOD);
        long long result = (sum_of_products * total_pairs_inverse) % MOD;

        std::cout << result << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
