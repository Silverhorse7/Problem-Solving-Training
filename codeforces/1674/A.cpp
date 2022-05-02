#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        auto solve = []() {
            int n, m;
            cin >> n >> m;
            for (int i = 1; i <= 100; i++) {
                for (int j = 1; j <= 100; j++) {
                    if (pow(j, i) > 200)break;
                    if (n * pow(j, i) == m) {
                        cout << i << ' ' << j << endl;
                        return;
                    }
                }
            }
            cout << 0 << ' ' << 0 << endl;
            return;
        };
        solve();
    }
}