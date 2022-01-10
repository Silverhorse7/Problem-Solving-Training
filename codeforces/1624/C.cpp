#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i: v)
            cin >> i;
        bool flg = true;
        set<int> st;
        for (int i = 0; i < n; i++) {
            while (v[i] > n)
                v[i] /= 2;
            while (st.find(v[i]) != st.end() and v[i] > 0)
                v[i] /= 2;
            if (v[i] != 0)
                st.insert(v[i]);
            else
                flg = false;
        }
        sort(v.begin(), v.end());
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= i + 1) {
                while (v[i] != i + 1) {
                    v[i] /= 2;
                }
                if (v[i] == i + 1) continue;
                flg = false;
                break;

            } else {
                flag = false;
                break;
            }
        }
        cout << (flg == false ? "NO" : "YES");
        cout << endl;
    }
}

