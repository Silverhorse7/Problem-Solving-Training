#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define si set<int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define add push_back
#define REP(i,a) for (int i = 0; i < (a); i++)
using namespace std;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1005000000;
const ll MOD = 1000000007LL;
//const ll MOD = 998244353LL;

int ni() {
    int x; cin >> x;
    return x;
}

ll nl() {
    ll x; cin >> x;
    return x;
}

double nd() {
    double x; cin >> x;
    return x;
}

string next() {
    string x; cin >> x;
    return x;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = ni();
    vl nums(N);
    map<ll,long double> m;
    REP(i,N) {
        nums[i] = nl();
        m[nums[i]]++;
    }

    long double ans = 0;
    long double tot = accumulate(all(nums),0LL);
    REP(i,N) {
        //code
        long double curSum = tot-(nums[i]-1)*m[nums[i]-1]-(nums[i])*m[nums[i]]-(nums[i]+1)*m[nums[i]+1];
        long double curCnt = (N-i)-m[nums[i]-1]-m[nums[i]]-m[nums[i]+1];

        ans += (curSum-curCnt*nums[i]);

        m[nums[i]]--;
        tot -= nums[i];
    }
    cout <<fixed<<setprecision(0)<< ans;
}