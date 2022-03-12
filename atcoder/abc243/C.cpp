#include<bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &i: v)
        cin >> i.first >> i.second;
    map<int, vector<pair<int, char>>> mp;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        mp[v[i].second].push_back({v[i].first, s[i]});
    }
    for (auto &i: mp)
        sort(i.second.begin(), i.second.end());
    for (auto i: mp) {
        vector<int> a, b;
        for (auto j: i.second) {
            if (j.second == 'R')a.push_back(j.first);
            else
                b.push_back(j.first);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a.size() and b.size() and a.front() <= b.back())
            return cout << "Yes", 0;
    }
    cout << "No";
}