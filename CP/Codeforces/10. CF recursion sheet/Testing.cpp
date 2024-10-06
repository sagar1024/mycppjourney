#include <iostream>
#include <vector>

using namespace std;
#define ll long long

// Recursive function to check if we can achieve sum 'x' by placing '+' or '-' between elements
bool solve(int n, ll int x, vector<int> &a, ll int sum)
{
    if (n == 0)
    {
        return sum == x;
    }

    // Try including the current element with '+' and with '-'
    return solve(n - 1, x, a, sum + a[n - 1]) || solve(n - 1, x, a, sum - a[n - 1]);
}

int32_t main()
{
    int n;
    ll int x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Start recursion with the initial sum of 0
    bool ans = solve(n, x, a, 0);

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
