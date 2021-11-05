#include <bits/stdc++.h>

using namespace std;
#define ll long long
string s, t;
int dp[3009][3009];
pair<int, int> link[3009][3009];

/*
 *    a b c d e
 * a  1 1 1 1 1
 * b  1 2 1 1 1
 * c  1 2 3 1 1
 *
 */
signed main() {
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size();
    s = 'Z' + s;
    t = 'Z' + t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                link[i][j] = {i - 1, j - 1};
            } else {
                if (dp[i - 1][j] > dp[i][j])dp[i][j] = dp[i - 1][j], link[i][j] = {i - 1, j};
                if (dp[i][j - 1] > dp[i][j])dp[i][j] = dp[i][j - 1], link[i][j] = {i, j - 1};
            }
        }
    }
    string an = "";
    int i = n;
    int j = m;
    while (i and j) {
        if (dp[i][j] == dp[i - 1][j - 1] + 1 and s[i] == t[j]) {
            an += s[i];
            i--, j--;
        } else if (dp[i][j] == dp[i][j - 1])j--;
        else
            i--;
    }
    reverse(an.begin(), an.end());
    cout << an;
}