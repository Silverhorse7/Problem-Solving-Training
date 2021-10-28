#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+55;
vector<int> G[N];
vector<bool> Color_of_node(N);
vector<bool> visited(N);
vector<int> White, Black;

void dfs(int i, bool color) {
    visited[i] = 1;
    Color_of_node[i] = color;
    if(color==1)White.push_back(i);
    else
        Black.push_back(i);
    for (auto &a: G[i]) {
        if (!visited[a])
            dfs(a, !color);
    }
}
void prnt(vector<int>&a,vector<int>&b){
    vector<int>ans;
    if(a.size()<b.size())ans=a;
    else
        ans=b;
    cout<<ans.size()<<endl;
    for(int i = 0 ; i <ans.size();i++)cout<<ans[i]<<' ';
    cout<<endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++)G[i].clear(), visited[i] = 0, Color_of_node[i] = 0;
        White.clear();
        Black.clear();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        dfs(1, 1);
        prnt(White,Black);
    }
}
