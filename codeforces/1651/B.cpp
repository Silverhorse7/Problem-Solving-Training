#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    scanf("%d", &T);
    auto solve = []() {
        int n;
        cin >> n;
        if (n > 19) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES\n" << endl;
        vector<long long> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i]=(long long)(1LL*(long long)pow(3ll,i));
        }
        for (int i = 0; i < n; i++)
            cout <<ans[i]<<' ';
        cout << endl;
        return 0;
    };
    while (T--) {
        solve();
    }
}