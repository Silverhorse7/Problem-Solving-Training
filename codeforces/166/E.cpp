#include "bits/stdc++.h"

using namespace std;
const int N = 1e7+4, mod = 1e9 + 7;
int dp[N][4];//0 A 1 B 2 C 3 D
int n;

int add(int a, int b) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
signed main() {
    cin >> n;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++)
                if (k != j)
                    dp[i + 1][j] = add(dp[i + 1][j], dp[i][k]);
        }
    }
    cout << dp[n][0] << endl;
}