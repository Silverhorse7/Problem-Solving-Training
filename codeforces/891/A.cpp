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
    //Idea : 
       // the idea is to get first 1 
       /*how to achieve that ?  if we found 2 numbers that gcd =1
       or if gcd != 1 , then compare current gcd with previous element before pair
       and next element after the pair
       if the gcd((next or previous) , gcd(a,b)) ==1 , then it's done and gg to you <3
       */
       //implementation : 
    ll n;
    cin >> n;
    vector<ll>v(n);
    int zz = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        if (v[i] == 1) {
            zz++;
        }
}
    if (zz > 0) {
        cout << n - zz << endl; return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (__gcd(v[i], v[i + 1]) == 1) {
            cout << n << endl; return;
        }
    }
    long long mn = 1e9;
    for (int i = 0; i < n; i++) {
        long long counter = 0, g = 0;
        for (int j = i; j < n; j++) {
            g = __gcd(g, v[j]);
            if (g == 1) {
                mn = min(counter, mn);
                break;
            }
            counter++;
        }
    }
    if (mn == 1e9) { cout << -1; return; }
    cout << mn + n - 1;
}
int main()
{
    Speedo;
    int t = 1;
  //  cin >> t;
    while (t--)
    {
        solve();
    }
}