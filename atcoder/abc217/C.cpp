#include<bits/stdc++.h>

using namespace std;
#define ll long long
    int arr[400000];
    int ans[400000];
int main() {
    int n;cin>>n;
    for(int i= 1; i <=n;i++){
        cin>>arr[i];
        ans[arr[i]]=i;
    }
    for(int i =1 ; i <=n;i++)cout<<ans[i]<<' ';
}