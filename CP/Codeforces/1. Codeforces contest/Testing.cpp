#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    // Special case: Only one row
    if (n == 1)
    {
        // When only one row, distribute k desks with minimum bench length
        cout << ceil((double)k / (m - k + 1)) << endl;
        return;
    }

    // Special case: Only one spot per row
    if (m == 1)
    {
        // When only one spot per row, distribute k rows with minimum bench length
        cout << ceil((double)k / (n - k + 1)) << endl;
        return;
    }

    // Average number of seats per row
    ll seats_per_row = ceil((double)k / n);

    // If seats per row exceed row capacity
    if (seats_per_row >= m)
    {
        cout << min(m, seats_per_row) << endl;
        return;
    }

    // Calculate minimum bench length
    ll res = ceil((double)seats_per_row / (m - seats_per_row + 1));

    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
