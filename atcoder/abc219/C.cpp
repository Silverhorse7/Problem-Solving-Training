#include<bits/stdc++.h>

using namespace std;
#define ll long long
map<char,int>val;
bool cmp(string &a , string &b){
    for(int i = 0 ;i <min((int)a.size(),(int)b.size());i++){
        if(val[a[i]]<val[b[i]]){
            return 1;
        }
        if(val[a[i]]>val[b[i]]){
            return 0;
        }
    }
    return (a.size()<b.size());
}	
int main() {
	string x;
    cin>>x;
    for(int i =0 ; i <x.size();i++)val[x[i]]=i;
    int n;cin>>n;
    vector<string>v(n);
    for(auto &i : v)cin>>i;
    sort(v.begin(),  v.end(),cmp);
    for(auto i : v)cout<<i<<endl;
}