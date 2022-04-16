#include<bits/stdc++.h>
//
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define ll long long
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
#define vi vector<int>
#define in(v, n) {for(int i =1 ;  i <=n;i++)cin>>v[i];}
#define in0(v, n) {for(int i =0 ;  i <n;i++)cin>>v[i];}
#define oo 12345678912345678
const int N = 2e5 + 3;
int n;
int a[N];
int dp[N][6];
vector<int> ans;

bool solve(int i, int F) {
    if (i >= n)return true;
    if (~dp[i][F])return dp[i][F];
    if (a[i] >= a[i - 1]) {
        if (a[i] <= a[i - 1]) {
            if (a[i] == a[i - 1]) {
                for (int j = 1; j <= 5; j++) {
                    if (j == F)continue;
                    if (solve(i + 1, j)) {
                        ans.push_back(j);
                        return dp[i][F] = true;
                    }
                }
            }
        } else {
            for (int j = F + 1; j <= 5; j++) {
                if (solve(i + 1, j)) {
                    ans.push_back(j);
                    return dp[i][F] = true;
                }
            }
        }
    } else {
        for (int j = F - 1; j >= 1; j--) {
            if (solve(i + 1, j)) {
                ans.push_back(j);
                return dp[i][F] = true;
            }
        }
    }
    return dp[i][F] = false;
}

bool do_stuff() {
    for (int i = 1; i <= 6; i++) {
        memset(dp, -1, sizeof dp);
        ans.clear();
        if (solve(1, i)) {
            cout << i << ' ';
            for (int j = (int) ans.size() - 1; j >= 0; j--) {
                cout << ans[j] << ' ';
            }
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    if(!do_stuff())
    cout << -1;
}