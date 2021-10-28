#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double

signed main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> cope(n, vector<int>(m));
    vector<pair<int, int>> zeros;
    for (auto &b : a)for (auto &c : b)cin >> c;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)if (a[i][j] == 0)zeros.push_back({i, j});
    set<pair<int, int>> st[51][51];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            st[i][j].insert({i + 1, j});
            st[i][j].insert({i, j + 1});
            st[i][j].insert({i + 1, j + 1});
            st[i][j].insert({i,j});
        }
    }
    vector<pair<int,int>>op;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(st[i][j].empty())continue;
            bool flag = 0;
            for (auto &b : st[i][j]) {
                for (auto &c : zeros) {
                    if (b == c)flag = 1;
                }
            }
            if (!flag) {
                op.push_back({i+1,j+1});
                for (auto &b : st[i][j]) {
                    cope[b.first][b.second] = 1;
                }
            }
        }
    }
  //  for (auto &b : cope){for(auto &c : b)cout<<c<<' ';cout<<endl;}
    if(cope==a){
        cout<<op.size()<<endl;
        for(auto &dd : op)cout<<dd.first<<' '<<dd.second<<endl;
        cout<<endl;
    }
    else
        cout<<-1;
}