#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        auto solve = []() {

            int n;
            cin >> n;
            vector<int> v(n);
            for (auto &i: v)
                cin >> i;
            if (n == 1) {
                cout << -1 << endl;
                return;
            }
            set<int> st;
            st.insert(v.begin(), v.end());
            if (st.size() == n) {
                cout << -1 << endl;
                return;
            }
            for (int i = 0; i < n - 1; i++)
                if (v[i] == v[i + 1]) {
                    cout << 2 << endl;
                    return;
                }
            for (int i = 0; i < n - 2; i++)
                if (v[i] == v[i + 2]) {
                    cout << 3 << endl;
                    return;
                }
            vector<int> ans;
            map<int, vector<int>> mp;
            for (int i = 0; i < n; i++)
                mp[v[i]].push_back(i);
            for (auto i: mp) {
                for (int j = 0; j < i.second.size() - 1; j++)
                    ans.push_back(i.second[j + 1] - i.second[j] + 1);
            }
            sort(ans.begin(), ans.end());
            cout << ans.front() << endl;
        };
        solve();
    }

}