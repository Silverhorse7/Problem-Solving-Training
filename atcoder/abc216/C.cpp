#include<bits/stdc++.h>

using namespace std;
#define ll long long
    int arr[400000];
    int ans[400000];
int main() {
    ll n;
    cin>>n;
    string ans = "";
    ll res = 1;
    while(n!=0){
        if(n%2==0){
            ans+='B';
            n/=2;
        }
        else{
            ans+='A';
            n--;
        }
    }
    reverse(ans.begin(),  ans.end());
    cout<<ans;
}