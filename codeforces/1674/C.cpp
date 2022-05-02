#include "bits/stdc++.h"

using namespace std;
#define int long long
signed main() {
    long long T = 1;
    cin >> T;
    auto solve = []() {
        string t, s;
        cin >> t >> s;
        int a = 0;
        int b = 1;
        if (s == "a") { cout << 1 << endl; }
        else {
            for (char i: s) {
                if (i == 'a')
                    a++;
            }
            if (a <= 0) {
                for (int i = 0; i < t.length(); i++) {
                    b = b * 2;
                }
                cout << b << endl;
            } else cout << -1 << endl;
        }
        return;
    };
    while (T--) {
        solve();
    }
}