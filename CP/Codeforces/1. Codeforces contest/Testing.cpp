#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    // First phase: Apply all 'and' operations (Bob's moves)
    bool resultAnd = s[0] - '0';  // Start with the first boolean value
    for (int i = 1; i < n; i += 2) { // Bob plays on even-indexed turns (1, 3, 5, ...)
        resultAnd = resultAnd && (s[i] - '0');
    }
    
    // Second phase: Apply all 'or' operations (Alice's moves)
    bool resultOr = resultAnd;  // Start with the result from Bob's turn
    for (int i = 1; i < n; i += 2) { // Alice plays on odd-indexed turns (2, 4, 6, ...)
        resultOr = resultOr || (s[i] - '0');
    }
    
    if (resultOr) {
        cout << "YES" << endl;  // Alice wins if the final result is true
    } else {
        cout << "NO" << endl;   // Bob wins if the final result is false
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}
