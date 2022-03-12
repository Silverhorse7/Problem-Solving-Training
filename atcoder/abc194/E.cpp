#include <bits/stdc++.h>

using namespace std;

signed main() {
    set<int> st;
    for (int i = 0; i < (int) (2e6 + 5); i++)
        st.insert(i);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i;
    map<int, int> frq;
    for (int i = 0; i < m; i++) {
        frq[v[i]]++;
        if (frq[v[i]] == 1) {
            st.erase(v[i]);
        }
    }
    long long num = *st.begin();
    long long ans=num;
    for (int i = 0; i < n - m; i++) {
        frq[v[i]]--;
        if (frq[v[i]] == 0)
            st.insert(v[i]);

        frq[v[i + m]]++;
        if (frq[v[i + m]] == 1) {
            st.erase(v[i + m]);
        }
        long long num = *st.begin();
        ans = min(ans, num);
    }
    cout << ans << endl;
}