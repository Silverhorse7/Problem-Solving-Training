    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    
    using namespace __gnu_pbds;
    using namespace std;
    
    #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define ll long long
    #define ld long double
    #define el "\n"
    
    #define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
    const int N = 1e5 + 10;
    const ll mod = 998244353;
    int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
    int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
    ll x, y, z, n, m, k;
    int last[N], arr[N], dp[N];
#define int long long
    void dowork() {
        int n, k;
        cin >> n >> k;
        vector<int> x(n);
        for (auto &i: x)
            cin >> i;
        int increase;
        cin >> increase;
        vector<int> Cost(n);
        for (auto &i: Cost)
            cin >> i;
        map<int, int> mp;
        int cur = k;
        long long final_cost = 0;
        for (int i = 0; i < n; i++) {
            mp[Cost[i]]++;
            if (cur < x[i]) {
                vector<int>to_delete;
                for (auto &j: mp) {
                    if(cur>x[i])break;
                    while (j.second>0 and cur<x[i]) {
                        cur += increase;
                        j.second--;
                        final_cost+=j.first;
                    }
                    if(j.second==0)
                        to_delete.push_back(j.first);
                }
                for(auto j   : to_delete)
                    mp.erase(j);
                if (cur < x[i]) {
                    cout << -1;
                    exit(0);
                }
            }
        }
        cout<<final_cost<<endl;
    }
    
    signed main() {
        fast
        //freopen("tour.in", "r", stdin);
        int t;
        t = 1;
        while (t--) {
            dowork();
        }
    }
