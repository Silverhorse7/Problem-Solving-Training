#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int n;cin>>n;
    for(int i = 1 ; i <=50000;i++){
        if((int)(i*(1.08))==n){
            cout<<i;return 0;
        }
    }
    cout<<":(";
}