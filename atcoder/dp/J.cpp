#include<bits/stdc++.h>

using namespace std;
const int N = 305;
int n, a[N];
double dp[N][N][N];

double dfs(int x, int y, int z) {
    if (x < 0 or y < 0 or z < 0)return 0;
    if (x == 0 and y == 0 and z == 0)return 0;
    if(dp[x][y][z]>0)return dp[x][y][z];
    return dp[x][y][z]=static_cast<double>(n+x*dfs(x-1,y,z)+y*dfs(x+1,y-1,z)+z*dfs(x,y+1,z-1))/(x+y+z);
}

signed main() {
    scanf("%d", &n);
    map<int,int>mp;
    for(int i =0 ; i <n;i++){
        int x;
        scanf("%d",&x);
        mp[x]++;
    }
    printf("%.9f",dfs(mp[1],mp[2],mp[3]));
}