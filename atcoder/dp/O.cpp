#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 22;
const int M = 1e9 + 7;
bool can[N][N];
int dp[1 << N];
int two[32];

void init() {
    two[0] = 1;
    for (int i = 1; i < 32; i++)two[i] = two[i - 1] * 2;
}

int ones(int x) {
    int one = 0;
    while (x) {
        one += (x % 2);
        x /= 2;
    }
    return one;
}

signed main() {
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> can[i][j];
    dp[0] = 1;
    for (int mask = 0; mask < two[n]; mask++) {//iterate over 2^n subsets
        int man = ones(mask);//number of elements in that subset
        for (int woman = 0; woman < n; woman++) {
            if (can[man][woman] and !(mask & two[woman]))//not available in that subset and supposed to be in 
            {
                dp[mask ^ two[woman]] += dp[mask];
                dp[mask ^ two[woman]] %= M;
            }
        }
    }
    cout << dp[two[n]-1];
}