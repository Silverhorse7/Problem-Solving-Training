#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;
vector<ll> a;
vector<ll> cur_pow;
ll n, r, k;

bool check(ll x, vector<ll> &cur_pow) {
    ll moves = 0;
    ll sum = 0;
    vector<ll> diff(n);
    for (int i = 0; i < n; i++) {
        if (x > sum + cur_pow[i]) {
            ll add = x - (sum + cur_pow[i]);
            if(add>0) {
                moves += add;
                sum += add;
                int toAddTheValue = min(i + r * 2, n - 1);
                diff[toAddTheValue] -= add;
            }
        }
        sum += diff[i];
        if (moves > k) return false;
    }
    if (moves <= k) return true;
    else return false;
}
int main() {
    cin >> n >> r >> k;
    cur_pow.resize(n);
    a.resize(n);
    for (auto &e: a)
        cin >> e;
    vector<long long int> prefix(n);

    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    for (int i = 0; i < n; i++)
        cur_pow[i] = (prefix[min(i + r, n - 1)] - a[i]) - (i - r - 1 >= 0 ? prefix[i - r - 1] : 0) + a[i];

    long long int start = 0;
    long long int end = 2 * 1e18;
    long long int answer = 0;
    while (start <= end) {
        long long mid = (start + end) / 2;

        if (check(mid, cur_pow)) {
            answer = mid;
            start = mid + 1;
        } else
            end = mid - 1;
    }
    cout << answer << endl;
}