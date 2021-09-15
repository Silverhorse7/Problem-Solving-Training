#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> table;
int n , m;
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio();
    cin >> n >> m;
    table.resize(n+12 , vector<int>(m+12));
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            cin >> table[i][j];
        }
    }
map<int,int>Ranges,renew;
    for(int i = 1;  i <=m;i++){
        for(int j =1; j <=n;j++){
            int first = j;
            while(j<=n and table[j][i]<=table[j+1][i]){
                j++;
            }
            Ranges[first]=max(Ranges[first],j);
        }
    }
    for(auto it = Ranges.begin();it!=Ranges.end();){
        int x=it->first;
        int y=it->second;
        if(it!=Ranges.end() and x<=it->first and y>=it->second) {
            while (it != Ranges.end() and x <= it->first and y >= it->second) {
                it++;
            }
        }
        else{
            it++;
        }
        renew[x]=y;
    }
    Ranges.clear();
    Ranges=renew;
    int Q;
    cin >> Q;
    for(int i = 0 ; i <Q;i++){
        int l , r;
        cin>>l>>r;
        if(l==r){
            cout<<"Yes"<<endl;
            continue;
        }
        auto it = Ranges.upper_bound(l);
        if(it!=Ranges.begin())
        it--;
        if(it->second>=r){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}