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
//kkz
ll printNcR(int n, int r)
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
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll>v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<ll, ll>mp;
        for (int i = 0; i < n; i++)
        {
            mp[v[i] -i]++;
        }
        ll cnt = 0;
        for (auto ele : mp)
        {
            if(ele.second>1)
            {
            	cnt+=printNcR(ele.second,2);
            }
        }
        cout << cnt << Endl;
     //   cout << cnt << endl;
    }
}//re