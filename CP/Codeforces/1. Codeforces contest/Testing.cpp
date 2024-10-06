#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> wealth(n);
        long long totalWealth = 0, maxWealth = 0;

        for (int i = 0; i < n; ++i) {
            cin >> wealth[i];
            totalWealth += wealth[i];
            maxWealth = max(maxWealth, wealth[i]);
        }

        // Calculate the number of unhappy people with current total wealth
        int unhappyCount = 0;
        double currentAverage = (double)totalWealth / n;
        double halfCurrentAverage = currentAverage / 2.0;

        for (int i = 0; i < n; ++i) {
            if (wealth[i] < halfCurrentAverage) {
                unhappyCount++;
            }
        }

        // If more than half are already unhappy
        if (unhappyCount > n / 2) {
            cout << 0 << "\n";
            continue;
        }

        // Calculate the minimum x needed
        // We want to make unhappyCount > n / 2
        // That means we need at least (n / 2 + 1) unhappy people
        int neededUnhappy = (n / 2 + 1) - unhappyCount;

        // We need to find the minimum x such that
        // a_i < 1/2 * (totalWealth + x) / n for at least `neededUnhappy` people
        long long requiredX = 0;
        while (neededUnhappy > 0) {
            requiredX = (neededUnhappy * (2 * maxWealth - 1)) - (2 * totalWealth);
            if (requiredX < 0) requiredX = 0;  // At least 0 gold is needed
            neededUnhappy--;
        }

        // Output the minimum x
        cout << requiredX << "\n";
    }

    return 0;
}
