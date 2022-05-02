#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        pair<int, int> a[n];
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
            cnt[a[i].first] += 1;
            if (cnt[a[i].first] > n / 2) {
                ok = false;
            }
        }
        sort(a, a + n);
        int mx = 0;
        for (auto i: cnt) mx = max(mx, i.second);
        deque<int> dq(n);
        for (int i = 0; i < n; i++)
            dq[i] = a[i].first;
        for (int i = 0; i < mx; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        for (int i = 0; i < n; i++) {
            a[a[i].second].first = dq[i];
        }
        for (int i = 0; i < n; i++)
            cout << a[i].first << ' ';
        cout << '\n';
    }
}