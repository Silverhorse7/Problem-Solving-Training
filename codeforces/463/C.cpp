#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2020 * 2;
long long d1[N], d2[N];

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n));
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            d1[i + j] += v[i][j];
            d2[i - j + n] += v[i][j];
        }
    }
    tuple<ll, ll, ll> ans1, ans2, a = {0, 0, 0}, b = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0)
                ans1 = {d1[i + j] + d2[i - j + n] - v[i][j], i + 1, j + 1}, a = max(a, ans1);
            else
                ans2 = {d1[i + j] + d2[i - j + n] - v[i][j], i + 1, j + 1}, b = max(b, ans2);
        }
    }
    cout << get<0>(a) + get<0>(b) << endl << get<1>(a) << ' ' << get<2>(a) << ' ' << get<1>(b) << ' ' << get<2>(b);
}
