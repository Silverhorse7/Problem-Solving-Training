#include "bits/stdc++.h"

using namespace std;
[[maybe_unused]] mt19937 mt(time(nullptr));

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &i: a)
            cin >> i;
        sort(a.begin(), a.end());
        int ans = 0;
        int cnt = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] * cnt >= x) {
                ans++;
                cnt = 1;
            } else
                cnt++;
        }
        cout<<ans<<endl;
    }
}