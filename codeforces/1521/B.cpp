#include<bits/stdc++.h>

using namespace std;
int po[2] = {1000000007, 1000000009};

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i: v)cin >> i;
        int xo = 0;
        vector<tuple<int, int, int, int>> ans;
        for (int i = 0; i < n - 1; i++,xo%=2) {
            if (v[i] <= v[i + 1]) ans.emplace_back(i + 1, i + 2, v[i], v[i + 1] = po[xo++]);
            else
                ans.emplace_back(i + 1, i + 2, v[i] = po[xo++], v[i + 1]);
        }
        cout << ans.size() << endl;
        for (auto [a, b, c, d]: ans)
            cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    }
}