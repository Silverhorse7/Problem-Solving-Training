
#include <bits/stdc++.h>

using namespace std;
const int N = 45;
bool dp[N][N][N][N];//i j j%A black%B
pair<bool, int> recall[N][N][N][N];

void solve() {
    int n, A, B;
    cin >> n >> A >> B;
    string s;
    cin >> s;
    memset(dp, false, sizeof dp);
    dp[0][0][0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < A; k++) {
                for (int h = 0; h < B; h++) {
                    if (dp[i][j][k][h]) {
                        dp[i + 1][j + 1][(k * 10 + (s[i] - '0')) % A][h] = true;
                        recall[i + 1][j + 1][(k * 10 + (s[i] - '0')) % A][h] = {true, k};
                        dp[i + 1][j][k][(h * 10 + (s[i] - '0')) % B] = true;
                        recall[i + 1][j][k][(h * 10 + (s[i] - '0')) % B] = {false, h};
                    }
                }
            }
        }
    }
    int mx = 0;
    for (int i = 1; i < n; i++)
        if (dp[n][i][0][0] && abs(i - (n - i)) < abs(mx - (n - mx)))
            mx = i;
    if (mx == 0) {
        cout << "-1\n";
    } else {
        int i = n;
        int j = mx;
        int k = 0;
        int h = 0;
        string ans = "";
        while (i > 0) {
            auto way = recall[i][j][k][h];
            if (!way.first) {
                h = way.second;
                ans.push_back('B');
            } else {
                j--;
                k = way.second;
                ans.push_back('R');
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}

signed main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}
