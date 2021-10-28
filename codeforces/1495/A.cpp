#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double

ld dist(pair<ld,ld> a, pair<ld,ld> b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
bool cmp(pair<ld,ld>&a,pair<ld,ld>&b){
    if(a.first==0){
        return a.second<b.second;
    }
    else{
        return a.first<b.first;
    }
}
signed main() {
    fast;
    T {
        int n;
        cin >> n;
        vector<pair<ld, ld>> D, M;
        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0)M.emplace_back(x, abs(y));
            if (y == 0)D.emplace_back(abs(x), y);
        }
        sort(D.begin(), D.end(),cmp);
        sort(M.begin(), M.end(),cmp);
        ld ans = 0 ;
        for(int i = 0 ; i <n;i++){
            ans+=dist(D[i],M[i]);
        }
        cout<<fixed<<setprecision(9)<<ans<<endl;
    }
}