#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i;
    vector<int> Pre(n);
    for (int i = 0; i < n; i++)
        Pre[i] = v[i] + (i - 1 >= 0 ? Pre[i - 1] : 0);
    int Q;
    cin >> Q;
    while (Q--) {
        int x;
        cin >> x;
        x--;
        auto y = upper_bound(Pre.begin(), Pre.end(), x);
        cout << y - Pre.begin() + 1 << endl;
    }
}