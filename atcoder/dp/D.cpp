#include <bits/stdc++.h>

using namespace std;
#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define inp(v) for(auto &i : v)cin>>i;
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
#define pow(x, y) ll(pow(x,y))
#define all(v) v.begin(),v.end()
ll dp[109][100009];
pair<ll, ll> v[109];

signed main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
    for (int i = 0; i <= w; i++) {
        dp[0][i] = (i >= v[0].first ? v[0].second : 0);
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= w; j++)
            dp[i][j] = max(dp[i - 1][j], (j - v[i].first >= 0 ? dp[i - 1][j - v[i].first] + v[i].second : 0));

    cout << dp[n - 1][w];
}