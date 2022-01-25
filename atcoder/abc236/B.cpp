#include<bits/stdc++.h>

using namespace std;

long long AnswerC() {

}

int main() {
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i = 0 ; i <4*n-1;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    for(auto i  :mp){
        if(i.second!=4){
            cout<<i.first<<endl;
        }
    }
}