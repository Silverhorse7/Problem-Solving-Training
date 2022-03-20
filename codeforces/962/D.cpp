#include "bits/stdc++.h"

using namespace std;

signed main() {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i: v)
        cin >> i;
    set<pair<long long,long long>>ans;
    map<long long, multiset<long long>> mp;
    for (long long i = 0; i < n; i++)
        mp[v[i]].insert(i);
    while (mp.size()) {
        auto x = *mp.begin();
        mp.erase(mp.begin());
        while (x.second.size() > 1) {
            x.second.erase(x.second.begin());
            mp[x.first * 2].insert(*x.second.begin());
            x.second.erase(x.second.begin());
        }
        if (x.second.size())
            ans.insert({*x.second.begin(), x.first});
    }
    cout << ans.size() << endl;
    for (auto i: ans)
        cout << i.second << ' ';
}
 