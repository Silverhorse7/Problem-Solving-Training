#include "bits/stdc++.h"

using namespace std;
#define int long long
signed main() {
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (auto &i: a)cin >> i;
    vector<int> cum(n+1);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cum[l]++;
        cum[r]--;
    }
    for (int i = 1; i < n; i++)
        cum[i] += cum[i - 1];
    sort(cum.rbegin(), cum.rend());
    long long ans = 0;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++)
        ans += cum[i] * a[i];
    cout << ans << endl;
}