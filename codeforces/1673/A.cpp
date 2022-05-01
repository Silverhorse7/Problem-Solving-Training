#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        auto solve = []() {
            string s;
            cin >> s;
            if (s.size() == 1) {
                cout << "Bob " << (s[0] - '`') << endl;
                return;
            }
            cout << "Alice ";
            int total_score = 0;
            for (char i: s)
                total_score += ((i - '`'));
            if (s.size() % 2)
                cout << max(total_score - 2*(s[0] - '`'), total_score - 2*(s.back() - '`')) << endl;
            else
                cout << total_score << endl;
            return;
        };
        solve();
    }

}