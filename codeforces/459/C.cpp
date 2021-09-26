#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2020 * 2 + 1000;
int n, k, d;

/*
 * print the student busses in days [1,d]
 * for(int i = 0 ; i <d;i++){
 *  for(int j =0 ; j <n;j++)
 *     cout<<ans[i][j]<<' ';
 *     cout<<endl;
 *  }
 */
vector<vector<int>> ans;

void solve(int i, vector<int> v) {
    if (ans.size() == n) {
        return;
    }
    if (i == d) {
        ans.push_back(v);
        return;
    }
    for (int j = 1; j <= k; j++) {
        if (ans.size() == n)return;
        v.push_back(j);
        solve(i + 1, v);
        v.pop_back();
    }

}

int main() {
    ios_base::sync_with_stdio();
    cout.tie();
    cin.tie();
    cin >> n >> k >> d;
    solve(0, {});
    if (ans.size() == n) {
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < n; j++)
                cout << ans[j][i] << ' ';
            cout << endl;
        }
    } else
        cout << -1;
}
