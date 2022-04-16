#include "bits/stdc++.h"

using namespace std;
const int N = 5005;
vector<int> dp(N, -1);
int arr[5][N];
int n, k;

int solve(int ele) {
    if (~dp[ele])return dp[ele];
    dp[ele] = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = 0;
        for (int j = 0; j < k; j++) {
            if (arr[j][i] <= arr[j][ele])//i exists before ele
                flag = 1;
        }
        if (!flag)
            dp[ele] = max(dp[ele], solve(i) + 1);
    }
    return dp[ele];
}

signed main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            arr[i][x] = j + 1;
        }
    cout << solve(0);
}