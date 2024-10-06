// B. Robin Hood and the Major Oak

// time limit per test1 second
// memory limit per test256 megabytes

// In Sherwood, the trees are our shelter, and we are all children of the forest. The Major Oak in Sherwood is known for its majestic foliage, which provided shelter to Robin Hood and his band of merry men and women. The Major Oak grows ii new leaves in the i-th year. It starts with 1 leaf in year 1. Leaves last for k years on the tree. In other words, leaves grown in year i last between years i and i+k−1 inclusive. Robin considers even numbers lucky. Help Robin determine whether the Major Oak will have an even number of leaves in year n.

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. Each test case consists of two integers n, k (1≤n≤109, 1≤k≤n) — the requested year and the number of years during which the leaves remain.

// Output
// For each test case, output one line, "YES" if in year n the Major Oak will have an even number of leaves and "NO" otherwise. You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// InputCopy
// 5
// 1 1
// 2 1
// 2 2
// 3 2
// 4 4
// OutputCopy
// NO
// YES
// NO
// NO
// YES

// Note
// In the first test case, there is only 1 leaf.
// In the second test case, k=1, so in the 2-nd year there will be 22=4 leaves.
// In the third test case, k=2, so in the 2-nd year there will be 1+22=5 leaves.
// In the fourth test case, k=2, so in the 3-rd year there will be 22+33=4+27=31 leaves.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// void solve()
// {
//     long long n, k;
//     cin >> n >> k;

//     // If k is 1, then we just check if n^2 is even or odd
//     if (k == 1)
//     {
//         if (n % 2 == 0) cout << "YES" << endl;
//         else cout << "NO" << endl;
//         return;
//     }

//     // When k > 1, we check the sum of squares parity from (n-k+1)^2 to n^2
//     // Essentially, the number of odd squares decides the parity
//     long long even_count = 0;
//     long long odd_count = 0;

//     // We just check the parity of numbers between n and (n-k+1)
//     for (long long i = n; i >= n - k + 1; i--)
//     {
//         if (i % 2 == 0) even_count++;
//         else odd_count++;
//     }

//     // If the number of odd numbers is even, the sum is even
//     if (odd_count % 2 == 0) cout << "YES" << endl;
//     else cout << "NO" << endl;

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
#include <bits/stdc++.h>

using namespace std;
#define ll long long

//Function to count the number of odd numbers in the range [1, x]
ll count_odds_up_to(ll x)
{
    return (x + 1) / 2;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    //If k == 1, simply check if n is even or odd
    if (k == 1)
    {
        cout << (n % 2 == 0 ? "YES" : "NO") << endl;
        return;
    }

    //Find the number of odd numbers in the range [n-k+1, n]
    ll total_odds = count_odds_up_to(n) - count_odds_up_to(n - k);

    //If the number of odd numbers is even, the sum of squares is even
    cout << (total_odds % 2 == 0 ? "YES" : "NO") << endl;

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
