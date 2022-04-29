
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include <random>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
#define ll long long
#define Silver_is_better_than_Gold ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pb push_back
#define endl '\n'
#define test   cout<<" We Droped up Here Boss _________________ "<<endl
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define no {cout<<"NO"<<endl;}
#define yes {cout<<"YES"<<endl;}
const int mod = 1e9 + 7;
#define sz(x) ((int) (x).size())
#define dups(divs)     divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define sum(v) accumulate(v.begin(),v.end(),0ll)
#define T int XXX;cin>>XXX;while(XXX--)
#define F first
#define SS second
#define ld long double
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int N = 2e4 + 5;

signed main() {
    Silver_is_better_than_Gold
    auto solve = []() {
        vector<pair<int, int>> teams;
        int a1, a2, k1, k2, k;
        cin >> a1 >> a2 >> k1 >> k2 >> k;
        teams.emplace_back(k1, a1);
        teams.emplace_back(k2, a2);
        auto mn = [&](int k) {
            sort(teams.begin(), teams.end(), greater<>());
            int M = 0;
            priority_queue<int> pq;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < teams[i].second; j++)
                    pq.push(teams[i].first);
            while (k > 0) {
                if (pq.top() == 1)
                    M++, k--, pq.pop();
                else {
                    auto x = pq.top();
                    pq.pop();
                    x--;
                    k--;
                    pq.push(x);
                }
            }
            return M;
        };
        cout << mn(k) << ' ';
        auto mx = [&](int k) {
            sort(all(teams));
            int M = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < teams[i].second; j++)
                    if (teams[i].first <= k) {
                        M++;
                        k -= teams[i].first;
                    }
            }
            return M;
        };
        cout << mx(k) << endl;
    };
    solve();
}