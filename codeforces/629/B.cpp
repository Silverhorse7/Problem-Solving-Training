#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n;
    cin >> n;
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        char x;
        int s, e;
        cin >> x >> s >> e;
        for (int j = s; j <= e; j++)
            if (x == 'M')mp[j].first++;
            else
                mp[j].second++;
    }
    int ans = 0;
    for (auto i: mp)
        ans = max(ans, min(i.second.first, i.second.second)*2);
    cout << ans << endl;
}