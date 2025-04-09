// B. Expensive Number

// time limit per test1 second
// memory limit per test256 megabytes

// The cost of a positive integer n is defined as the result of dividing the number n by the sum of its digits. For example, the cost of the number 104 is 1041+0+4=20.8, and the cost of the number 111 is 1111+1+1=37. You are given a positive integer n that does not contain leading zeros. You can remove any number of digits from the number n (including none) so that the remaining number contains at least one digit and is strictly greater than zero. The remaining digits cannot be rearranged. As a result, you may end up with a number that has leading zeros. For example, you are given the number 103554. If you decide to remove the digits 1, 4, and one digit 5, you will end up with the number 035, whose cost is 0350+3+5=4.375. What is the minimum number of digits you need to remove from the number so that its cost becomes the minimum possible?

// Input
// The first line contains an integer t (1≤t≤1000) — the number of test cases. The only line of each test case contains a positive integer n (1≤n<10100) without leading zeros.

// Output
// For each test case, output one integer on a new line — the number of digits that need to be removed from the number so that its cost becomes minimal.

// Example
// InputCopy
// 4
// 666
// 13700
// 102030
// 7
// OutputCopy
// 2
// 4
// 3
// 0

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     string s;
//     cin >> s;

//     int n = s.size();
//     int x = 0;
//     int X = 1;
//     for(int i=n-1; i>=0; i--)
//     {
//         if(s[i]!='0')
//         {
//             x++;
//             i--;
//             while(s[i]=='0' && i>=0)
//             {
//                 x++;
//                 X = max(X,x);
//                 i--;
//             }
//             x = 0;
//         }
//     }

//     cout << n-X << endl;
//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    int x = 1;
    //int X = 1;
    for(int i=n-1; i>=0; i--)
    {
        if(s[i]!='0')
        {
            x = 1;
            for(int j=i-1; j>=0; j--)
            {
                if(s[j]=='0' && j>=0 && i>=0)
                {
                    x++;
                }
            }

            break;
        }
    }

    cout << n-x << endl;
    return;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
