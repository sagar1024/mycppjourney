#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    unordered_map<int, int> colorFreq;

    // Read input and count color frequencies
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            colorFreq[grid[i][j]]++;
        }
    }

    int maxFreq = 0;
    for (auto &[color, freq] : colorFreq) {
        maxFreq = max(maxFreq, freq);
    }

    // Minimum steps = Total cells - Max frequency color (since we can recolor all others)
    cout << (n * m - maxFreq) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
