#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    auto ispal = [&](string s) {
        for (int i = 0; i < s.size() / 2; i++)
            if (s[i] != s[s.size() - 1 - i])
                return false;
        return true;
    };
    vector<int> pal;
    for (int i = 1; i < 4e4 + 1; i++) {
        if (ispal(to_string(i))) {
            pal.push_back(i);
        }
    }
    vector<int> dp(4e4 + 1);
    const int mod = 1e9 + 7;
    dp[0] = 1;
    auto add = [](int x, int y) {
        x %= mod;
        y %= mod;
        return (x + y) % mod;
    };
    for (auto k: pal)
        for (int i = 0; i + k < dp.size(); i++)
            dp[i + k] = add(dp[i + k], dp[i]);
    while (T--) {
        auto solve = [&]() {
            int n;
            cin >> n;
            cout << dp[n] << endl;
        };
        solve();
    }

}