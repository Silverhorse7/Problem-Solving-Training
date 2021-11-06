#include<bits/stdc++.h>

using namespace std;
#define ll long long
template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template<typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
    }
};
template<typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
    }
};
const int N = 3009;
double coins[N];
Vec<2,double>dp(N,N,-1);

//what i care about ? index for sure ,
double solve(int i, int cnt1, int cnt2) {
    if (i <= 0) {
        if (cnt1 > cnt2) {
            return 1;
        }
        return 0;
    }
    double &res = dp[i][cnt1];
    if (res > -1)return res;
    return res = solve(i - 1, cnt1 + 1, cnt2)*coins[i] + solve(i - 1, cnt1, cnt2 + 1)*(1-coins[i]);

}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> coins[i];
    cout << fixed << setprecision(10) << solve(n,0,0);
}