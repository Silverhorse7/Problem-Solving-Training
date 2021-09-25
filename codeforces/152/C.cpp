#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;

int main() {
    long long cnt = 1;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto &a : v)
        for (auto &e : a)
            cin >> e;
    for (int i = 0; i < m; i++) {
        set<char> st;
        for (int j = 0; j < n; j++) {
            st.insert(v[j][i]);
        }
        cnt=(cnt%mod * st.size()%mod)%mod;
    }
    cout<<cnt<<endl;
}