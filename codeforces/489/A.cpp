#include<bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++)b.push_back({v[i], i});
    sort(b.begin(), b.end());
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (b[i].second == i)continue;
        else {
            ans.push_back({min(b[i].second, i), max(b[i].second, i)});
            swap(v[min(b[i].second, i)], v[max(b[i].second, i)]);
            for (int j = 0; j < n; j++) {
                if (b[j].second == i) {
                    b[j].second = b[i].second;
                    break;
                }
            }
            b[i].second = i;
        }
    }
    cout << ans.size() << endl;
    for (auto i: ans)
        cout << i.first << ' ' << i.second << endl;
    // for (auto i: v)cout << i << ' ';
}