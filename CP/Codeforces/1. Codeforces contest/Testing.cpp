// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;

// int maxScore(const vector<int>& a, const string& s) {
//     int len = s.size();
//     int score = 0;

//     // Iterate through the string and find all valid segments
//     for (int i = 0; i < len; ++i) {
//         if (s[i] == 'L') {
//             for (int j = i + 1; j < len; ++j) {
//                 if (s[j] == 'R') {
//                     // Sum the segment from 'L' to 'R'
//                     int segmentSum = 0;
//                     for (int k = i; k <= j; ++k) {
//                         segmentSum += a[k];
//                     }
//                     // Update the score if this segment gives a higher score
//                     score = max(score, score + segmentSum);
//                 }
//             }
//         }
//     }

//     return score;
// }

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<int> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }

//         string s;
//         cin >> s;

//         int result = maxScore(a, s);

//         cout << result << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calculateMaxScore(const vector<int>& a, const string& s, bool reverse) {
    int len = s.size();
    int score = 0;

    vector<bool> used(len, false); // to keep track of used indices

    if (reverse) {
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] == 'R' && !used[i]) {
                for (int j = i - 1; j >= 0; --j) {
                    if (s[j] == 'L' && !used[j]) {
                        // Sum the segment from 'L' to 'R'
                        int segmentSum = 0;
                        for (int k = j; k <= i; ++k) {
                            segmentSum += a[k];
                            used[k] = true; // mark these indices as used
                        }
                        score += segmentSum;
                        break; // move to the next 'R'
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'L' && !used[i]) {
                for (int j = i + 1; j < len; ++j) {
                    if (s[j] == 'R' && !used[j]) {
                        // Sum the segment from 'L' to 'R'
                        int segmentSum = 0;
                        for (int k = i; k <= j; ++k) {
                            segmentSum += a[k];
                            used[k] = true; // mark these indices as used
                        }
                        score += segmentSum;
                        break; // move to the next 'L'
                    }
                }
            }
        }
    }

    return score;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        string s;
        cin >> s;

        int leftToRightScore = calculateMaxScore(a, s, false);
        int rightToLeftScore = calculateMaxScore(a, s, true);

        cout << max(leftToRightScore, rightToLeftScore) << endl;
    }

    return 0;
}
