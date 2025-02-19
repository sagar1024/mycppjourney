// A. Adjacent Digit Sums

// time limit per test1 second
// memory limit per test256 megabytes

// Given two numbers x,y. You need to determine if there exists an integer n such that S(n)=x, S(n+1)=y. Here, S(a) denotes the sum of the digits of the number a in the decimal numeral system.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows. The first line of each test case contains two integers x,y (1≤x≤1000,1≤y≤1000).

// Output
// For each test case, print "NO" if a suitable n does not exist. Otherwise, output "YES". You can output each letter in any case (for example, "YES", "Yes", "yes", "yEs", "yEs" will be recognized as a positive answer).

// Example
// InputCopy
// 7
// 1 2
// 77 77
// 997 999
// 999 1
// 1000 1
// 1 11
// 18 1
// OutputCopy
// Yes
// No
// No
// Yes
// No
// No
// Yes

// Note
// In the first test case, for example, n=100 works. S(100)=1, S(101)=2.
// In the second test case, it can be shown that S(n)≠S(n+1) for all n; therefore, the answer is No.
// In the fourth test case, n=10111−1 works, which is a number consisting of 111 digits of 9.

//Original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// int digitSum(int n)
// {
//     int sum = 0;
//     while (n > 0)
//     {
//         sum += (n % 10);
//         n /= 10;
//     }
//     return sum;
// }

// void solve()
// {
//     int x, y;
//     cin >> x >> y;

//     //Does not work because the contraints is more than 111 digits
//     for (int n = 1; n <= 1e6; n++)
//     {
//         if (digitSum(n) == x && digitSum(n + 1) == y)
//         {
//             cout << "YES" << endl;
//             return;
//         }
//     }

//     cout << "NO" << endl;

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

//Alternate soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// int digitSum(int n)
// {
//     int sum = 0;
//     while (n > 0)
//     {
//         sum += (n % 10);
//         n /= 10;
//     }
//     return sum;
// }

// bool allNineAndOneExists(int x, int y)
// {
//     string s1 = to_string(x);
//     string s2 = to_string(y);
    
//     if ((s1 == "1" && s2.find_first_not_of('9') == string::npos) || (s2 == "1" && s1.find_first_not_of('9') == string::npos))
//     {
//         return true;
//     }

//     return false;
// }

// void solve()
// {
//     int x, y;
//     cin >> x >> y;

//     bool yes = allNineAndOneExists(x,y);
//     if(yes)
//     {
//         cout << "YES" << endl;
//         return;
//     }

//     //Does not work because the contraints is more than 111 digits
//     for (int n = 1; n <= 1e5; n++)
//     {
//         if (digitSum(n) == x && digitSum(n + 1) == y)
//         {
//             cout << "YES" << endl;
//             return;
//         }
//     }

//     cout << "NO" << endl;

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

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}

void solve()
{
    int x, y;
    cin >> x >> y;

    // if((abs(x-y)==1 && x<y) || (digitSum(x)%9==0 && y==1) || (abs(x-y)==8 && x>y))
    if(x+1>=y && (x+1-y)%9==0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
