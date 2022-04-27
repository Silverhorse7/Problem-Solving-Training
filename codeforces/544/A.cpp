#include<bits/stdc++.h>

using namespace std;

signed main(){

    int n;
    cin>>n;
    string a;
    cin>>a;
    vector<string> rez;
    int ar[26]={};
    for(int ctr1=0;ctr1<a.size();ctr1++){
        if(ar[a[ctr1]-'a']==0 && rez.size()<n){
            ar[a[ctr1]-'a']=1;
            string t;
            t+=a[ctr1];
            rez.push_back(t);
        }
        else{
            rez[rez.size()-1]=rez[rez.size()-1]+a[ctr1];
        }
    }
    if(rez.size()!=n){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES\n";
    for(int ctr1=0;ctr1<n;ctr1++)
        cout<<rez[ctr1]<<endl;
    return 0;
}