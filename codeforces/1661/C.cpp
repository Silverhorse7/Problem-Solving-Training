#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int mx = 0;
        vector<int> v(n);
        for (auto &i: v)cin >> i;
        mx = *max_element(v.begin(), v.end());
        int res = 1e16;
        for (int height = mx; height <= mx + 100; ++height) {
            int two = 0, one = 0;
            for (auto &x: v) {
                two += (height - x) / 2;
                one += (height - x) % 2;
            }
            res = min(res, max({one * 2 - 1, (one + two * 2) / 3 * 2 + (one + two * 2) % 3}));
        }
        cout << res << endl;
    }
}