#include <bits/stdc++.h>

using namespace std;
const int INF = INT_MAX / 2, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (auto &i : a) cin >> i;

    vector<vector<int>> cost(H, vector<int>(W, INF));
    vector<vector<pair<int, int>>> tele(128, vector<pair<int, int>>{});
    int sx, sy, gx, gy;
    for (int x = 0; x < H; x++)
        for (int y = 0; y < W; y++) {
            const char c = a[x][y];
            if (islower(c)) tele[c].emplace_back(x, y);
            else if (c == 'S') sx = x, sy = y;
            else if (c == 'G') gx = x, gy = y;
        }
    cost[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});

    while (q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        const int c2 = cost[x][y] + 1;
        for (int d = 0; d < 4; d++) {
            const int x2 = x + dx[d], y2 = y + dy[d];
            if (x2 < 0 || x2 >= H || y2 < 0 || y2 >= W || a[x2][y2] == '#') continue;
            if (cost[x2][y2] > c2) {
                cost[x2][y2] = c2;
                q.push({x2, y2});
            }
        }
        if (islower(a[x][y])) {
            auto &t = tele[a[x][y]];
            for (auto ssd : t) {
                auto x2 = ssd.first;
                auto y2 = ssd.second;
                if (cost[x2][y2] > c2) {
                    cost[x2][y2] = c2;
                    q.push({x2, y2});
                }

                t.clear();
            }
        }
    }
    int ans = cost[gx][gy];
    if (ans == INF) ans = -1;
    cout << ans << endl;
}
