
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> res;
        vector<vector<char>>a(n+1,vector<char>(m+1));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                cin >> a[i][j];
            }
        }
        if (a[1][1] != '1') {
            for (int i = 1; i <= n; i++) {
                for (int j = m; j > 1; j--) {
                    if (a[i][j] != '1') continue;
                    res.push_back({i, j - 1, i, j});
                }
            }
            for (int i = n; i > 1; i--) {
                if (a[i][1] != '1') continue;
                res.push_back({i - 1, 1, i, 1});
            }
        } else {
            cout << "-1" << endl;
            continue;
        }
        cout << (res).size() << endl;
        for(const auto& i:res){
            for (auto j: i)cout << j << " ";
            cout << endl;
        }
    }
}