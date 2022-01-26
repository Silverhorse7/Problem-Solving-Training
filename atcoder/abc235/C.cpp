#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N];

signed main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
        mp[a[i]].push_back(i);
    while (q--) {
        int x, k;
        scanf("%d%d", &x, &k);
        if(k>mp[x].size())printf("%d",-1);
        else
            printf("%d",mp[x][k-1]);
        printf("\n");
    }
}