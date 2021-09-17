#include "bits/stdc++.h"
using namespace std;
#define ll long long
int main() {
    int n,m;
    cin>>n>>m;
    if(n>28)cout<<m<<endl;
    else
        cout<<(m%(int)(pow(2,n)))<<endl;
}