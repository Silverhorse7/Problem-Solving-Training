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
#define getlost {cout<<"NO"<<endl;return ;}
#define getgud {cout<<"YES"<<endl;return ;}
#define tests(x) for(int i =  1 ; i<=x;i++)
#define inp(v,n) for(int i = 0 ;  i<n;i++)cin>>v[i];
#define outp(v) for(auto ele : v){        cout << ele.first << " " << ele.second << " ";}cout<<endl
const ll mod = 1e9 + 7;
#define summ(v,sum) for(auto ele : v)sum+=ele;
#define inti int i
#define sz(x) ((int) (x).size())
#define dups(divs)     divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define fo(i,a,b) for(int i = a ; i<=b;i++)
#define outq(q)     queue<int>qq = q;while (qq.size()) { cout << qq.front() << " "; qq.pop();};
#define sttk(x) static_cast<ll>(x)
#define re register
#define intj int j
#define debug cout<<"Output is  :  ";
#define debug2 cout<<"End of the output______________________"<<endl;
int ways = 0;
int alpha = 1;
int n, m;
bool valid(int x, int y) {
    return (x >= 0 and y >= 0 and x < n and y < n);
}
    ll dp[1003][1003];
void solve() {
    cin >> n >> m;
    vector<vector<bool>>v(n+33, vector<bool>(m+33, 0));
            char x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> x;
            if (x == '#')v[i][j] = 1;
            else
                v[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == 1)continue;
            if (i == 1 and j == 1)dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j]+dp[i][j-1]) % mod;
            }
        }
    }
    cout << dp[n][m] % mod;
}
int main() {
    Silver_is_better_than_Gold;
    // For getting input from input.txt file
    //freopen("mosalah.in", "r", stdin);
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }

    //-
}