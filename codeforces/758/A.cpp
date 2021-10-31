#include<iostream>
using namespace std;
long long arr[100000+66];
long long ans = 0 ;
long long mx = 0 ;
int main(){
    int n;cin>>n;for(int i = 0 ; i <n;i++){cin>>arr[i];mx=max(mx,arr[i]);}
    for(int i = 0 ; i <n;i++)ans=ans+(mx-arr[i]);
    cout<<ans;
}