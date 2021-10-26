#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define q(v, n) for(ll i = 0 ;  i <n;i++)cin>>v[i];
#define out(v) {for(auto &a : v)cout<<a<<' ';cout<<endl;}
#define re resize
#define all(v) v.begin(),v.end()
#define no {printf("%s\n","NO");return 0;};
#define yes {printf("%s\n","YES");return 0;};
#define minus {printf("%s\n","-1");return 0;};
#define IM INT_MAX
#define Cin cin
#define inti ll i
#define intj ll j
#define OR or
const ll N = 4e4 + 5, INF = 1e9 + 5, mod = 1e9 + 7;

int n, m, k, a[N], b[N];
ll ans;

set<int> getDivisors(){
    set<int> ret;

    for(int i = 1; i * i <= k; i++)
        if(k % i == 0)
            ret.insert(i);

    return ret;
}

int cnt(bool arr, int y){
    int ret = 0;

    if(arr)
        for(int i = y; i <= n; i++)
            ret += (a[i] - a[i - y] == y);
    else
        for(int i = y; i <= m; i++)
            ret += (b[i] - b[i - y] == y);

    return ret;
}

void doWork(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];

    for(int j = 1; j <= m; j++)
        cin >> b[j], b[j] += b[j - 1];

    set<int> divisors = getDivisors();

    for(auto& d : divisors){
        int complement = k / d;

        ans += 1LL * cnt(1, d) * cnt(0, complement);
        if(d != complement)
            ans += 1LL * (cnt(1, complement) * cnt(0, d));
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int test=1;
    //cin >> test;
    while(test--)
        doWork();
}