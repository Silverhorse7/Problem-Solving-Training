
#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(k + 33);
    for (auto &i: a)cin >> i;
    for (auto i: a)cnt[i % k]++;
    int ans = 0;
    ans = cnt[0] / 2;
    if (k % 2 == 0) ans += cnt[k / 2] / 2;
    for (int i = 1; i < (k + 1) / 2; ++i) {
        int j = k - i;
        ans += min(cnt[i], cnt[j]);
    }
    cout << ans*2 << endl;
}