#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll abs_a0 = abs(a[0]);
    int less = 0, greater = 0;

    for(int i = 1; i < n; i++) {
        if(abs(a[i]) < abs_a0) less++;
        else if(abs(a[i]) > abs_a0) greater++;
    }

    int pos = (n - 1) / 2; // 0-based index of the median

    if(less <= pos && greater <= n - 1 - pos)
        cout << "YES\n";
    else
        cout << "NO\n";

    return;
}

int32_t main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
