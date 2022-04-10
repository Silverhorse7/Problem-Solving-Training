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
        int64_t res = 1e16;
        for (int height = mx; height <= mx +100; ++height) {
            int64_t due = 0, uno = 0;
            for (auto &x: v) {
                due += (height - x) / 2;
                uno += (height - x) % 2;
            }
            int64_t all = uno + due * 2;
            int64_t days = all / 3 * 2;
            if (all % 3 != 1) {} else ++days;
            if (all % 3 != 2) {} else days += 2;
            int64_t cnt_days = uno * 2;
            res = min(res, max(cnt_days - 1, days));
        }
        cout << res << endl;
    }
}