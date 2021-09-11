#include "bits/stdc++.h"
using namespace std;
int n,k;
priority_queue<long long,vector<long long>,greater<>>pq1,pq2,pq12;
signed main() {
    cin>>n>>k;
    for(int i = 0 ;  i <n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(y==0 and z==1)pq2.push(x);
        if(y==1 and z==0)pq1.push(x);
        if(y==1 and z==1)pq12.push(x);
    }
    pq1.push(1e11+1);
    pq12.push(1e11+1);
    pq2.push(1e11+1);
    long long int p1=0,p2=0,ans=0;
    while(p1<k or p2<k){
        if(ans>(long long)1e10 or ans<0){
            cout<<-1<<endl;return 0;
        }
        long long int x=pq1.top();
        long long int y = pq2.top();
        long long int z = pq12.top();
        if(p1<k)
        {
            if(p2<k)
            {
                if(x+y<z)
                {
                    p1++;
                    p2++;
                    ans+=x+y;
                    pq1.pop();
                    pq2.pop();
                }
                else
                {
                    p1++;
                    p2++;
                    ans+=z;
                    pq12.pop();
                }
            }
            else
            {
                if(x<z)
                {
                    p1++;
                    p2++;
                    ans+=x;
                    pq1.pop();
                }
                else
                {
                    p1++;
                    p2++;
                    ans+=z;
                    pq12.pop();
                }
            }
        }
        else if(p2<k)
        {
            if(y<z)
            {
                p1++;
                p2++;
                ans+=y;
                pq1.pop();
            }
            else
            {
                p1++;
                p2++;
                ans+=z;
                pq12.pop();
            }
        }
    }
    if(ans>(long long)1e10 or ans<0){
        cout<<-1<<endl;return 0;
    }
    cout<<ans<<endl;
}