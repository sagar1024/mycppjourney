#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<long long> x(n);
        vector<long long> r(n);

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
        }

        map<long long, vector<pair<long long, long long>>> y_ranges_by_x;
        for (int i = 0; i < n; i++)
        {
            long long center_x = x[i];
            long long radius = r[i];

            for (long long dx = -radius; dx <= radius; dx++)
            {
                long long current_x = center_x + dx;
                long long max_y_squared = radius * radius - dx * dx;

                if (max_y_squared < 0)
                    continue;

                long long max_y = floor(sqrt(max_y_squared));
                y_ranges_by_x[current_x].push_back({-max_y, max_y});
            }
        }

        long long total_points = 0;
        for (auto &[current_x, y_ranges] : y_ranges_by_x)
        {
            sort(y_ranges.begin(), y_ranges.end());
            vector<pair<long long, long long>> merged;

            for (auto &range : y_ranges)
            {
                if (merged.empty() || merged.back().second < range.first - 1)
                {
                    merged.push_back(range);
                }
                else
                {
                    merged.back().second = max(merged.back().second, range.second);
                }
            }

            for (auto &range : merged)
            {
                total_points += (range.second - range.first + 1);
            }
        }

        cout << total_points << endl;
    }

    return 0;
}
