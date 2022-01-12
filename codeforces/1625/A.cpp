#include <bits/stdc++.h>

using namespace std;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        vector<int> v(n);
        for (auto &i: v)
            cin >> i;
        vector<int> alpha(1000);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if (v[i] & (1 << j))
                    alpha[j] += 1;
            }
        }
        long long ans = 0;
        for (int i = 0; i < l; i++) {
            if (alpha[i] > n/2)
                ans += (pow(2, i));
        }
        cout << ans << endl;
    }
}