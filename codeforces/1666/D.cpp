#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        map<char, int> mp;
        for (auto i: t)
            mp[i]++;
        bool flag = 1;
        int to = t.size() - 1;
        for (int i = s.size() - 1; i >= 0 && to >= 0; i--) {
            if (s[i] == t[to]) {
                mp[t[to]]--;
                to--;
                if (to == -1) {
                    break;
                }
            } else {
                if (mp[s[i]] > 0)break;
            }
        }
        cout << (to == -1 ? "YES" : "NO") << endl;
    }
}