#include<bits/stdc++.h>

using namespace std;
#define int long long

int nextPowerOf2(int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

int po[2] = {1000000007, 1000000009};

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i: v)
            cin >> i;
        int xo = 0;
        vector<tuple<int, int, int, int>> ans;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] <= v[i + 1]) {
                ans.push_back({i + 1, i + 2, v[i], v[i] + 1});
                v[i + 1] = v[i] + 1;
            } else {
                ans.push_back({i + 1, i + 2, po[xo], v[i + 1]}), v[i] = po[xo++];
                if (xo == 2)
                    xo = 0;
            }
        }
       // for (auto i: v)cout << i << ' ';
        cout << ans.size() << endl;
        for (auto [a, b, c, d]: ans)
            cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    }
}