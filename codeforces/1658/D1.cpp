//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define Silver_is_better_than_Gold ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl       '\n'
#define return0 return 0
#define Endl endl
#define ull unsigned long long
#define elif else if
#define test   cout<<" We Droped up Here Boss _________________ "<<endl
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define txt freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ld long double
#define vb vector<bool>
#define no {cout<<"NO"<<endl;return ;}
#define yes {cout<<"YES"<<endl;return ;}
#define tests(x) for(int i =  1 ; i<=x;i++)
#define inp(v, n) for(int i = 0 ;  i<n;i++)cin>>v[i];
#define outp(v) for(auto ele : v){        cout << ele.first << " " << ele.second << " ";}cout<<endl
const ll mod = 1e9 + 7;
#define inti int i
#define sz(x) ((int) (x).size())
#define dups(divs)     divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define fo(i, v, b) for(int i = v ; i<=b;i++)
#define outq(q)     queue<int>qq = q;while (qq.size()) { cout << qq.front() << " "; qq.pop();};
#define sttk(x) static_cast<ll>(x)
#define re register
#define intj int j
#define debug cout<<"Output is  :  ";
#define debug2 cout<<"End of the output______________________"<<endl;
#define sum(v) accumulate(v.begin(),v.end(),0ll)
#define range(i, n) for(int i = 0 ; i <n;i++)
#define point pair<int,int>
#define T int t;cin>>t;while(t--)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

ll fastpow(ll base, ll power, ll M) {
    if (power == 1) return base;
    ll val = fastpow(base, power / 2, M);
    return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}

//----------------------Code Starts Here-----------------------------//
const long long M = 30;
signed main() {
    T{
            vector<long long> O2(M), O1(M), Z1(M), Z2(M);
            auto W1 = [&](long long x) -> void {
                ll pos = 0;
                for (long long i = 0; i <= 18; i++) {
                    (x % 2 ? O1 : Z1)[i]++;
                    x /= 2;
                }
            };
            auto W2 = [&](long long x) -> void {
                ll pos = 0;
                for (long long i = 0; i <= 18; i++) {
                    (x % 2 ? O2 : Z2)[i]++;
                    x /= 2;
                }
            };
            long long l, r;
            long long ans = 0;
            cin >> l >> r;
            for (long long i = l; i <= r; i++) W1(i);
            for (long long i = l; i <= r; i++) {
                ll x;
                cin >> x;
                W2(x);
            }
            ans = 0;
            ll y = 1;
            for (long long i = 0; i <= 20; i++) {
                if (O1[i] == O2[i] && Z1[i] == Z2[i]) {} else ans += y;
                y *= 2;
            }
            cout << ans << endl;
    }
}