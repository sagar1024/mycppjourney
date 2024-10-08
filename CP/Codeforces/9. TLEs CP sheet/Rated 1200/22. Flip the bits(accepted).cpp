// B. Flip the Bits

// time limit per test1 second
// memory limit per test256 megabytes

// There is a binary string a of length n. In one operation, you can select any prefix of a with an equal number of 0 and 1 symbols. Then all symbols in the prefix are inverted: each 0 becomes 1 and each 1 becomes 0. For example, suppose a=0111010000. In the first operation, we can select the prefix of length 8 since it has four 0's and four 1's: [01110100]00→[10001011]00. In the second operation, we can select the prefix of length 2 since it has one 0 and one 1: [10]00101100→[01]00101100. It is illegal to select the prefix of length 4 for the third operation, because it has three 0's and one 1. Can you transform the string a into the string b using some finite number of operations (possibly, none)?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of test cases. The first line of each test case contains a single integer n (1≤n≤3⋅105) — the length of the strings a and b. The following two lines contain strings a and b of length n, consisting of symbols 0 and 1. The sum of n across all test cases does not exceed 3⋅105.

// Output
// For each test case, output "YES" if it is possible to transform a into b, or "NO" if it is impossible. You can print each letter in any case (upper or lower).

// Example
// InputCopy
// 5
// 10
// 0111010000
// 0100101100
// 4
// 0000
// 0000
// 3
// 001
// 000
// 12
// 010101010101
// 100110011010
// 6
// 000111
// 110100
// OutputCopy
// YES
// YES
// NO
// YES
// NO

// Note

// The first test case is shown in the statement.
// In the second test case, we transform a into b by using zero operations.
// In the third test case, there is no legal operation, so it is impossible to transform a into b.

// In the fourth test case, here is one such transformation:
// Select the length 2 prefix to get 100101010101.
// Select the length 12 prefix to get 011010101010.
// Select the length 8 prefix to get 100101011010.
// Select the length 4 prefix to get 011001011010.
// Select the length 6 prefix to get 100110011010.

// In the fifth test case, the only legal operation is to transform a into 111000. From there, the only legal operation is to return to the string we started with, so we cannot transform a into b.

//My original soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    a.push_back('0');
    b.push_back('0');

    int count = 0;
    for(int i=0; i<n; i++)
    {
        count += (a[i]=='1') - (a[i]=='0');
        if((a[i]==b[i])!=(a[i+1]==b[i+1]) && count!=0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
