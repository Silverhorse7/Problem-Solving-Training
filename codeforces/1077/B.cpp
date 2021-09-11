#include<bits/stdc++.h>
using namespace std;
int dp[300000][3];
signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &ele: v)cin >> ele;
    int cnt = 0;
    for(int i =1;  i <n-1;i++){
        if(v[i]==0 and v[i-1]==1 and v[i+1]==1){
            cnt++;
            v[i]=2;
            v[i-1]=2;
            v[i+1]=2;
        }
    }
    cout<<cnt<<endl;
}
