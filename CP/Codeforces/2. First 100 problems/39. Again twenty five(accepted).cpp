// A. Again Twenty Five!

// time limit per test0.5 seconds
// memory limit per test64 megabytes
// inputstandard input
// outputstandard output

// The HR manager was disappointed again. The last applicant failed the interview the same way as 24 previous ones. "Do I give such a hard task?" — the HR manager thought. "Just raise number 5 to the power of n and get last two digits of the number. Yes, of course, n can be rather big, and one cannot find the power using a calculator, but we need people who are able to think, not just follow the instructions."

// Could you pass the interview in the machine vision company in IT City?

// Input
// The only line of the input contains a single integer n (2 ≤ n ≤ 2·1018) — the power in which you need to raise number 5.

// Output
// Output the last two digits of 5n without spaces between them.

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    //Taking input just for the sake of it
    long int n;
    cin >> n;

    // long int result = 5;
    // result = pow(result, n);

    // string s = to_string(result);
    // cout << s[n-2] << s[n-1] << endl;

    //Use of common sense, not logic
    cout << 25 << endl;

    return 0;
}

