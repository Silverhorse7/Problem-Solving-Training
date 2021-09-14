#include <bits/stdc++.h>
using namespace std;
//Optimize later !!!(when free)
vector<vector<int>> table,prefix;
int n , m;
map<pair<int,int>,int>memo;
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    cin >> n >> m;
    table.resize(n+1 , vector<int>(m+1));
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            cin >> table[i][j];
        }
    }
    prefix.resize(m+1 , vector<int>(n+1));
    for(int i = 1  ; i <=m;i++){
        for(int j = 2 ; j <=n;j++){
            prefix[i][j]=prefix[i][j-1]+(table[j][i]<table[j-1][i]);
        }
    }
    int Q;
    cin >> Q;
    for(int i = 0 ; i <Q;i++){
        int l , r;
        cin>>l>>r;
        if(memo[{l,r}]==2){
            cout<<"No"<<endl;continue;
        }
        if(n==1 or memo[{l,r}]==1){
            cout<<"Yes"<<endl;continue;
        }
        bool temp=0;
        int start = 1 ;
        int end = m;
        for(int j = 1 ; j <=m;j++){
            if(prefix[j][r]-prefix[j][l]==0){
                temp=1;
                cout << "Yes\n";
                memo[{l,r}]=1;
                break;
            }
        }
        if(!temp){
            cout << "No\n";
            memo[{l,r}]=2;
        }
    }
    return 0;
}