#include<bits/stdc++.h>
using namespace std;
int flag(int xa , int ya , int xb ,int yb ,int xf, int yf){
    if(ya==yb){
        if(yf==ya){
            if(xf>=xa and xf<=xb)return 2;
        }
        else
            return 0;
    }
    else if(xa==xb){
        if(xf==xa){
            if(yf>=ya and yf<=yb){
                return 2;
            }
            else
                return 0;
        }
    }
    return 0;
}
signed main() {
    cout.tie();
    int t;
    cin>>t;
    while(t--) {
        int xa,ya,xb,yb,xf,yf;
        cin>>xa>>ya>>xb>>yb>>xf>>yf;
        int ans = 0 ;
        ans=max(flag(xa,ya,xb,yb,xf,yf),flag(xb,yb,xa,ya,xf,yf));
       cout<<ans+abs(xa-xb)+abs(ya-yb)<<endl;

    }
}