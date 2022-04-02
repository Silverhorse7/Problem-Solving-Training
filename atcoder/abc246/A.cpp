#include<bits/stdc++.h>

using namespace std;

signed main() {
    vector<pair<int, int>> v(3);
    for (auto &i: v)
        cin >> i.first >> i.second;
    map<int, int> x, y;
    for (auto i: v)
        x[i.first]++, y[i.second]++;

    for (auto i: x)
        if (i.second == 1)cout << i.first << ' ';
    for (auto i: y)
        if (i.second == 1)cout << i.first << ' ';
}