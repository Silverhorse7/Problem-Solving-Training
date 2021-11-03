#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 1; 
    int op =0;
    while(ans<b){
    	ans--;
    	ans+=a;
    	op++;
    }cout<<op;
}