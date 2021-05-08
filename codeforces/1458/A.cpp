#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
#define Speedo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl       '\n'
#define return0 return 0
#define Endl endl
#define ull unsigned long long
#define elif else if 
#define test   cout<<" We Fucked up Here Boss_________________"<<endl
#define allout(first) for(auto ele : first) {cout<<ele<<" ";}cout<<endl;
void move1step(ll& a, ll& b, ll q) {
    ll next = a - q * b;
    a = b;
    b = next;
}ll egcd(ll a, ll b, ll& x0, ll& y0) {
    ll r0 = a, r1 = b;
    ll x1, y1;
    x1 = y0 = 0;
    x0 = y1 = 1;
    while (r1 != 0) {
        ll q = r0 / r1;
        move1step(x0, x1, q);
        move1step(y0, y1, q);
        move1step(r0, r1, q);
    }
    return r0;
} 
ll mod = 1000000007;
ll Pascal[2005][2005] = { {} };
void initalizedPascal() {
        Pascal[0][0] = 1;
        for (int i = 1; i < 2005; i++) {
            Pascal[i][0] = 1;
            for (int j = 1; j < i + 1; j++) {
                Pascal[i][j] = (Pascal[i - 1][j - 1] + Pascal[i - 1][j])%mod;
            }
        }
}
void solve()
{
    int n;
    cin >> n;
    ll q; cin >> q;
    vector<ll>v(n);
    for (auto& e : v)cin >> e;
    while (q--) {
        int x;
        cin >> x;
        if (binary_search(all(v), x)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    Speedo;
    int t = 1;
  //  cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll>v(n);
        vector<ll>b(m);
        for (int i = 0; i < n; i++)cin >> v[i];
        for (int i = 0; i < m; i++)cin >> b[i];
        long long g = 0;
        for (int i = 1; i < n; i++) {
            g = __gcd(g, abs(v[i] - v[0]));
        }
        for (int i = 0; i < m; i++) {
            cout << __gcd(g, v[0] + b[i]) << ' ';
        }
    }
}