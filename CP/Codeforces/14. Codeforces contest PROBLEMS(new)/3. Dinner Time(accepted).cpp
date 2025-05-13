// A. Dinner Time

// time limit per test1 second
// memory limit per test256 megabytes

// Given four integers n, m, p, and q, determine whether there exists an integer array a1,a2,…,an (elements may be negative) satisfying the following conditions: The sum of all elements in the array is equal to m: a1+a2+…+an=mThe sum of every p consecutive elements is equal to q: ai+ai+1+…+ai+p−1=q, for all 1≤i≤n−p+1

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows. The first and only line of each test case contains four integers n, m, p, and q (1≤p≤n≤100, 1≤q,m≤100) — the length of the array, the sum of elements, the length of a segment, and the sum of a segment, respectively.

// Output
// For each test case, output "YES" (without quotes) if there exists an array satisfying the above conditions, and "NO" (without quotes) otherwise. You can output "YES" and "NO" in any case (for example, strings "yES", "yes", and "Yes" will all be recognized as valid responses).

// Example
// InputCopy
// 5
// 3 2 2 1
// 1 1 1 1
// 5 4 2 3
// 10 7 5 2
// 4 4 1 3
// OutputCopy
// YES
// YES
// YES
// NO
// NO

// Note
// In the first test case, an example of an array satisfying the condition is [1,0,1]. This is because:
// a1+a2+a3=1+0+1=2=m
// a1+a2=1+0=1=q
// a2+a3=0+1=1=q

// In the second test case, the only array satisfying the condition is [1].
// In the third test case, an example of an array satisfying the condition is [−2,5,−2,5,−2].
// In the fourth test case, it can be proven that there is no array satisfying the condition.

#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    // if(n % p == 0 && m == q * (n / p))
    // if(n%p!=0 && q*(n-p+1) == m*p)
    // if(m == q*(n-p+1))
    // if (n % p == m % q)
    if (n % p == 0)
    {
        if(m==(n/p)*q) cout << "YES\n";
        else cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    // vector<int> a(n, 0);
    // if (n > 2 * p)
    // {
    //     for (int j = 0; j < p; j++) a[j] = j + 1;
    //     for (int j = n - 1; j >= n - p; j--) a[j] = j + 1;
    //     for(int i=0; i<n; i++)
    //     {
    //         if(a[i]==0) a[i] = p;
    //     }
    // }
    // else
    // {
    //     for(int i=0; i<p; i++) a[i] = i+1;
    //     for(int i=p; i<n; i++) a[i] = p;
    //     for(int i=n-1; i>=0; i--) a[i] = min(a[i],n-i);
    // }

    // ll int sum = 0;
    // for(int i=0; i<n; i++) sum += a[i];

    // if(m==sum) cout << "YES" << endl;
    // else cout << "NO" << endl;

    return;
}

int32_t main()
{
    ios::sync_with_stdio(false);

    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }

    return 0;
}
