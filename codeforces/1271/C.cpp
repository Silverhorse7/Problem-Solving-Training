#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second

bool valid(int x, int y) {
    return x >= 0 and y >= 0 and x <= 1e9 and y <= 1e9;
}

pair<int, int> d[] = {{0,  -1},
                      {0,  1},
                      {-1, 0},
                      {1,  0}};

int dist(int x, int y, int or1, int or2) {
    return abs(x - or1) + abs(y - or2);
}

signed main() {
    int n, sx, sy;
    cin >> n >> sx >> sy;
    vector<pair<int, int>> v(n);
    for (auto &i: v)
        cin >> i.first >> i.second;
    vector<pair<int, int>> points;
    for (auto i: d)
        if (valid(i.first + sx, i.second + sy))
            points.push_back({i.first + sx, i.second + sy});
    map<pair<int, int>, int> mp;
    for (auto i: v) {
        int mn = 2e9 + 4;
        for (auto j: points)
            if (dist(i.first, i.second, j.first, j.second) <= mn)
                mn = dist(i.first, i.second, j.first, j.second);
        for (auto j: points)
            if (dist(i.first, i.second, j.first, j.second) == mn)
                mp[j]++;
    }
    vector<tuple<int, int, int>> ans;
    for (auto i: mp)
        ans.push_back({i.second, i.first.first, i.first.second});
    sort(ans.begin(), ans.end());
    auto[a, b, c]=ans.back();
    cout << a << endl << b << ' ' << c << endl;
}