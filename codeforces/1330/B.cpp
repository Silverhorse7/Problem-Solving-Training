#include "bits/stdc++.h"

using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &I: a)cin >> I;
        vector<int> l(n+1), r(n+1);
        set<int> mex;
        for (int i = 1; i <= n; i++)mex.insert(i);
        for (int i = 0; i < n; i++)mex.erase(a[i]), l[i] = *mex.begin();
        mex.clear();
        for (int i = 1; i <= n; i++)mex.insert(i);
        for (int i = n - 1; i >= 0; i--)mex.erase(a[i]), r[i] = *mex.begin();
        //for (int i = 0; i < n; i++)cout << l[i] << ' ';cout << endl;for (int i = 0; i < n; i++)cout << r[i] << ' ';
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++)
            if (l[i] + r[i + 1] == n + 2)
                ans.push_back({i + 1, n - i - 1});
        cout << ans.size() << endl;
        for(auto i: ans)
            cout<<i.first<<' '<<i.second<<endl;

    }
}