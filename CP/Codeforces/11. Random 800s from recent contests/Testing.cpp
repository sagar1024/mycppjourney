#include <iostream>
using namespace std;

void solver() {
    int n, k;
    cin >> n >> k;

    int a = n, b = n - 1;
    int ans = 0;

    // Distribute the chips across diagonals until all k chips are placed
    while (k > 0) {
        k -= a;  // Place as many chips as possible in the current diagonal
        ans++;   // Increment the number of occupied diagonals

        // Update the values of a and b for the next iteration
        a = b;
        b = (a != b) ? b : b - 1;  // Adjust for the next diagonal
    }

    cout << ans << endl;  // Output the number of occupied diagonals
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solver();
    }

    return 0;
}
