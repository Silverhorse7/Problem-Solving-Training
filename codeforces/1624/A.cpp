#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &i : v)
            cin>>i;
        cout<<*max_element(v.begin(),  v.end())-*min_element(v.begin(),  v.end())<<endl;
    }
}