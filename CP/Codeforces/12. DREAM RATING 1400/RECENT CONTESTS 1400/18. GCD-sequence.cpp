// D. GCD-sequence

// time limit per test2 seconds
// memory limit per test256 megabytes

// GCD (Greatest Common Divisor) of two integers x and y is the maximum integer z by which both x and y are divisible. For example, GCD(36,48)=12, GCD(5,10)=5, and GCD(7,11)=1. Kristina has an array a consisting of exactly n positive integers. She wants to count the GCD of each neighbouring pair of numbers to get a new array b, called GCD-sequence. So, the elements of the GCD-sequence b will be calculated using the formula bi=GCD(ai,ai+1) for 1≤i≤n−1. Determine whether it is possible to remove exactly one number from the array a so that the GCD sequence b is non-decreasing (i.e., bi≤bi+1 is always true). For example, let Khristina had an array a = [20,6,12,3,48,36]. If she removes a4=3 from it and counts the GCD-sequence of b, she gets:
// b1=GCD(20,6)=2
// b2=GCD(6,12)=6
// b3=GCD(12,48)=12
// b4=GCD(48,36)=12

// The resulting GCD sequence b = [2,6,12,12] is non-decreasing because b1≤b2≤b3≤b4.

// Input
// The first line of input data contains a single number t (1≤t≤104) — he number of test cases in the test. This is followed by the descriptions of the test cases. The first line of each test case contains a single integer n (3≤n≤2⋅105) — the number of elements in the array a. The second line of each test case contains exactly n integers ai (1≤ai≤109) — the elements of array a. It is guaranteed that the sum of n over all test case does not exceed 2⋅105.

// Output
// For each test case, output a single line:

// "YES" if you can remove exactly one number from the array a so that the GCD-sequence of b is non-decreasing;
// "NO" otherwise.

// You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will all be recognized as a positive answer).

// Example
// InputCopy
// 12
// 6
// 20 6 12 3 48 36
// 4
// 12 6 3 4
// 3
// 10 12 3
// 5
// 32 16 8 4 2
// 5
// 100 50 2 10 20
// 4
// 2 4 8 1
// 10
// 7 4 6 2 4 5 1 4 2 8
// 7
// 5 9 6 8 5 9 2
// 6
// 11 14 8 12 9 3
// 9
// 5 7 3 10 6 3 12 6 3
// 3
// 4 2 4
// 8
// 1 6 11 12 6 12 3 6
// OutputCopy
// YES
// NO
// YES
// NO
// YES
// YES
// NO
// YES
// YES
// YES
// YES
// YES

// Note
// The first test case is explained in the problem statement.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// #define ll long long
// using namespace std;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<ll int> a(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> a[i];
//     }

//     vector<int> gcd(n-1);
//     for(int i=0; i<n-1; i++)
//     {
//         gcd[i] = __gcd(a[i],a[i+1]);
//     }

//     int count = 0;
//     for(int i=1; i<n-1; i++)
//     {
//         if(gcd[i-1]>gcd[i])
//         {
//             count++;
//         }
//     }

//     if(count<2) cout << "YES" << endl;
//     else cout << "NO" << endl;

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

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

bool good(vector<int> a, int idx)
{
    if (idx < 0 || idx >= a.size()) return false;

    vector<int> x;
    for(int i=1; i<a.size(); i++)
    {
        if(i==idx) continue;

        int x2 = __gcd(a[i-1],a[i]);
        x.push_back(x2);
    }

    for(int i=1; i<x.size(); i++)
    {
        if(x[i-1]>x[i]) return false;
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<int> b(n-1);
    for(int i=0; i<n-1; i++)
    {
        b[i] = __gcd(a[i],a[i+1]);
    }

    int idx = -1;
    for(int i=1; i<n-1; i++)
    {
        if(i>0 && b[i-1]>b[i] && idx==-1)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "YES\n";  //Already sorted
        return;
    }

    //Check removing three possible elements (with bounds check)
    bool res = (idx-1 >= 0 && good(a, idx - 1)) || good(a, idx) || (idx + 1 < n && good(a, idx + 1));

    if(res) cout << "YES" << endl;
    else cout << "NO" << endl;

    return;
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
