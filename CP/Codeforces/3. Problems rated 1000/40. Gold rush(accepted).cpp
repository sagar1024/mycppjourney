// D. Gold Rush

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Initially you have a single pile with n gold nuggets. In an operation you can do the following: Take any pile and split it into two piles, so that one of the resulting piles has exactly twice as many gold nuggets as the other. (All piles should have an integer number of nuggets.) One possible move is to take a pile of size 6 and split it into piles of sizes 2 and 4, which is valid since 4 is twice as large as 2. Can you make a pile with exactly m gold nuggets using zero or more operations?

// Input
// The first line contains an integer t (1≤t≤1000) — the number of test cases. The only line of each test case contains two integers n and m (1≤n,m≤107) — the starting and target pile sizes, respectively.

// Output
// For each test case, output "YES" if you can make a pile of size exactly m, and "NO" otherwise. You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

// Example
// inputCopy
// 11
// 6 4
// 9 4
// 4 2
// 18 27
// 27 4
// 27 2
// 27 10
// 1 1
// 3 1
// 5 1
// 746001 2984004
// outputCopy
// YES
// YES
// NO
// NO
// YES
// YES
// NO
// YES
// YES
// NO
// NO

// Note
// The first test case is pictured in the statement. We can make a pile of size 4.
// In the second test case, we can perform the following operations: {9}→{6,3}→{4,2,3}. The pile that is split apart is colored red before each operation.
// In the third test case, we can't perform a single operation.
// In the fourth test case, we can't end up with a larger pile than we started with.(an Image)

//First dfs question -
//My original solution -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int n, m;
//         cin >> n >> m;

//         bool canMakePile = false;
//         if(n<m)
//         {
//             cout << "NO" << endl;
//             continue;
//         }
//         if(n==m)
//         {
//             cout << "YES" << endl;
//         }
//     }
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canMakePile(int n, int m)
{
    if(n==m)
    {
        return true;
    }
    else if(n%3!=0)
    {
        return false;
    }
    else
    {
        return (canMakePile(n/3, m) || canMakePile((2*n)/3, m));
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        if(canMakePile(n,m))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
