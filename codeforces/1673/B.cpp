#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        auto solve = []() {
            string s;
            cin >> s;
            map<char, int> mp;
            int turn = 0;
            bool flag = 0;
            for (int i = 0; i < s.size(); i++) {
                if (mp[s[i]]) {
                    break;
                }
                mp[s[i]]++;
                turn++;
            }
            for (int i = turn; i < s.size(); i++)
                if (s[i] != s[i % turn]) {
                    cout << "No" << endl;
                    return;
                }
            cout << "YEs" << endl;

        };
        solve();
    }

}