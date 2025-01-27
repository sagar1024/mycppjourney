#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_continue_indefinitely(vector<int> &a)
{
    int n = a.size();

    // Try starting from each clock
    for (int start = 0; start < n; start++)
    {
        vector<int> times = a;
        bool possible = true;

        // Simulate an arbitrarily long process (1000 iterations should suffice)
        for (int iter = 0; iter < 1000; iter++)
        {
            // Decrease all times
            for (int i = 0; i < n; i++)
            {
                times[i]--;
            }

            // Check if any clock hits 0
            if (*min_element(times.begin(), times.end()) < 0)
            {
                possible = false;
                break;
            }

            // Find a clock to reset
            int reset_idx = -1;
            for (int i = 0; i < n; i++)
            {
                // Check neighboring clocks (or current clock)
                if (abs(i - start) <= 1)
                {
                    if (reset_idx == -1 || times[i] < times[reset_idx])
                    {
                        reset_idx = i;
                    }
                }
            }

            // Reset the most critical clock
            times[reset_idx] = a[reset_idx];
            start = reset_idx;
        }

        // If we can complete 1000 iterations, it's possible
        if (possible)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << (can_continue_indefinitely(a) ? "YES" : "NO") << "\n";
    }

    return 0;
}
