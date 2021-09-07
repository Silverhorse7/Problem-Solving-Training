#include<bits/stdc++.h>
using namespace std;
signed main() {
    cout.tie();
    int t;
    cin>>t;
    while(t--){
        int n,m,x;
        cin>>n>>m>>x;
        vector<pair<int,int>>blocks(n);
        multiset<pair<int,int>>pq;
        for(int i =1 ; i <=m;i++){
            pq.insert({0,i});
        }
        for(int i = 0  ; i<n;i++){
            cin>>blocks[i].first;
            blocks[i].second=i;
        }
        sort(blocks.begin(), blocks.end());
        vector<int>ans(n);
        for(int i = n-1 ; i >=0;i--){
            auto ele =*pq.begin();
            pq.erase(*pq.begin());
            ele.first+=blocks[i].first;
            ans[blocks[i].second]=ele.second;
            pq.insert(ele);
        }
        auto ele = *pq.begin();
        auto eles = *pq.rbegin();
        if(abs(ele.first)-abs(eles.first)>x){
            cout<<"NO"<<endl;
        }
        else {
            cout << "YES" << endl;
            for (auto ele: ans)cout << ele << ' ';
            cout << endl;
        }
    }
}