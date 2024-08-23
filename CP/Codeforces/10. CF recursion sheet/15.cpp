// O. Fibonacci

// time limit per test1 second
// memory limit per test256 megabytes

// Given a number N. Print the value of the Nth Fibonacci number. Note: Solve this problem using recursion.

// Input
// Only one line containing a number N (1 ≤ N ≤ 30).

// Output
// Print the value of the Nth Fibonacci number.

// Example
// InputCopy
// 5

// OutputCopy
// 3

// Note
// For more information visit Fibonacci: https://www.mathsisfun.com/numbers/fibonacci-sequence.html.

#include <iostream>
#include <bits/stdc++.h>

int fib(int n)
{
    // if(n==0 || n==1)
    // {
    //     return n;
    // }
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    
    return fib(n-1)+fib(n-2);
}

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}
