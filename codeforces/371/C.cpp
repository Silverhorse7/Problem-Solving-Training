#include<bits/stdc++.h>

#define ll long long
using namespace std;
vector<ll> tar, have, cost;
ll money;

bool proof(ll total,ll money) {
    ll Cost = 0;
    for (int i = 0; i < 3; i++) {
        if (have[i] >= tar[i] * total)continue;
        money-= ((tar[i] * total - have[i]) * cost[i]);
        if(money<0)return false;
    }
    return money>=0;
}

int main() {
    ios_base::sync_with_stdio();
    cout.tie();
    cin.tie();
    string s;
    cin >> s;
    tar.resize(3), have.resize(3), cost.resize(3);
    for (auto ele :s) {
        if (ele == 'B') {
            tar[0]++;
        }
        if (ele == 'S')
            tar[1]++;
        if (ele == 'C')tar[2]++;
    }
    cin >> have[0] >> have[1] >> have[2];
    cin >> cost[0] >> cost[1] >> cost[2];
    cin >> money;
    ll start = 0, end = 1e13, mid;
    ll ans = 0;
    while (start <= end) {
        mid = (start + end) / 2;
        if (proof(mid,money)) {
            ans = mid;
            start = mid + 1;
        } else
            end = mid - 1;
    }
    cout << ans;
}