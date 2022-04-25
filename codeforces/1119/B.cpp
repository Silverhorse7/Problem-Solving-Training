#include "bits/stdc++.h"

using namespace std;
[[maybe_unused]] mt19937 mt(time(nullptr));
#define int long long
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (auto &i: a)
        cin >> i;
    int l = 0, r = n+1;
    auto chk = [&](int k) {
        vector<int> b;
        for (int i = 0; i < k; i++)b.push_back(a[i]);
        sort(b.rbegin(), b.rend());
        int f = 0;
        for (int i = 0; i < k; i+=2)f += b[i];
        return f <= h;
    };
    while (r - l > 1) {
        int m = (l + r)/2;
        if (chk(m))
            l = m;
        else
            r = m;
    }
    cout << l;
}