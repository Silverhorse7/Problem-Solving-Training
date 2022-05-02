#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i;
    vector<int> powers = v;
    sort(powers.begin(), powers.end());
    int ans = (powers[0] + 1) / 2 + (powers[1] + 1) / 2;
    auto scenario1 = [&](int x, int z) {
        ans = min(ans, (x + z + 1) / 2);
    };
    auto scenario2 = [&](int x, int z) {
        ans = min(ans, max(max((x + 1) / 2, (z + 1) / 2), (x + z + 2) / 3));
    };
    for (int i = 1; i < n; i++) {
        if (i + 1 < n) {
            scenario1(v[i - 1], v[i + 1]);
        }
        scenario2(v[i - 1], v[i]);
    }
    cout << ans << endl;
}