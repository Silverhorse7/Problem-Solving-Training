#include<bits/stdc++.h>

using namespace std;
#define ll long long
    int arr[400000];
    int ans[400000];
int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    if(c%2==0){
    	a=abs(a);
    	b=abs(b);
    	    	if(a<b)cout<<'<';
    	else if(a>b)cout<<'>';
    	else
    	cout<<'=';
    }
    else{
    	if(a<b)cout<<'<';
    	else if(a>b)cout<<'>';
    	else
    	cout<<'=';
    }
}