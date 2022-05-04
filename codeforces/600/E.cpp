#include "bits/stdc++.h"

using namespace std;
#define int long long
const int N = 2e5;
map<int, int> *mp[N];
vector<int> adj[N];
int mx[N], ans[N], col[N], n;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> col[i];
    for (int i = 0, x, y; i < n - 1; i++) {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    auto chk = [&](int &u, int &cur_max, int &sum) {
        if ((*mp[u])[col[u]] >= cur_max) {
            if ((*mp[u])[col[u]] != cur_max)
                sum = 0;
            cur_max = (*mp[u])[col[u]];
            sum += col[u];
        }
    };
    function<void(int, int)> dfs = [&](int u, int par) {
        int big = -1;
        for (auto i: adj[u]) {
            if (i == par)continue;
            dfs(i, u);
            if (big == -1 or mp[big]->size() <= mp[i]->size())
                big = i;
        }
        int Mx = 0, sum = 0;
        if (big == -1)
            mp[u] = new map<int, int>();
        else
            mp[u] = mp[big], sum = ans[big], Mx = mx[big];
        (*mp[u])[col[u]]++;
        chk(u, Mx, sum);
        for (auto i: adj[u]) {
            if (i == par or i == big)continue;
            for (auto j: *mp[i]) {
                (*mp[u])[j.first] += j.second;
                if ((*mp[u])[j.first] >= Mx) {
                    if ((*mp[u])[j.first] != Mx)
                        sum = 0;
                    sum += j.first;
                    Mx = (*mp[u])[j.first];
                }
            }
        }
        ans[u] = sum;
        mx[u] = Mx;
    };
    dfs(0, -1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}