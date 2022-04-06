#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(auto &i : v)
        cin>>i;
    set<int>st;
    vector<int>answer(n+1);
    for(int i = n-1 ; i >=0 ; i--){
        st.insert(v[i]);
        answer[i+1]=st.size();
    }
    while(m--){
        int l;
        cin>>l;
        cout<<answer[l]<<endl;
    }
}