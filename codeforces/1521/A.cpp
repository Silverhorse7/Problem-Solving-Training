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
ll comb(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
 
    else
        p = 1;
    return p;
}
int main()
{
    Speedo;
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll a, b; cin >> a >> b;
        if (b == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << a << ' ' << a *b << ' ' << a *(b + 1) << endl;
        }
    }
}