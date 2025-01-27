// A. Simple Design

// time limit per test1 second
// memory limit per test256 megabytes

// A positive integer is called k-beautiful, if the digit sum of the decimal representation of this number is divisible by k†. For example, 9272 is 5-beautiful, since the digit sum of 9272 is 9+2+7+2=20. You are given two integers x and k. Please find the smallest integer y≥x which is k-beautiful. An integer n is divisible by k if there exists an integer m such that n=k⋅m.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The only line of each test case contains two integers x and k (1≤x≤109, 1≤k≤10).

// Output
// For each test case, output the smallest integer y≥x which is k-beautiful.

// Example
// InputCopy
// 6
// 1 5
// 10 8
// 37 9
// 777 3
// 1235 10
// 1 10
// OutputCopy
// 5
// 17
// 45
// 777
// 1243
// 19

// Note
// In the first test case, numbers from 1 to 4 consist of a single digit, thus the digit sum is equal to the number itself. None of the integers from 1 to 4 are divisible by 5.
// In the fourth test case, the digit sum of 777 is 7+7+7=21 which is already divisible by 3.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// ll int calcSum(ll int x)
// {
//     ll int res = 0;
//     while(x>0)
//     {
//         res += x%10;
//         x = x/10;
//     }

//     return res;
// }

// void solve()
// {
//     ll int x, k;
//     cin >> x >> k;

//     ll int digitSum = calcSum(x);
//     if(x<10)
//     {
//         cout << k << endl;
//     }
//     else if(digitSum%k==0)
//     {
//         cout << digitSum << endl;
//     }
//     else
//     {
//         ll int rem = x%k;
//         ll int diff = k-rem;
//         cout << x+diff+1 << endl;
//     }

//     return;
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

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

//Function to calculate the digit sum of a number
int digitSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

void solve()
{
    ll int x, k;
    cin >> x >> k;
    while(1)
    {
        if(digitSum(x)%k==0)
        {
            cout << x << endl;
            break;
        }

        x++;
    }
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
