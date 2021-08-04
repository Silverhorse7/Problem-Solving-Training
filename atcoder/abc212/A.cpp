
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Silver_is_better_than_Gold  cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl       "\n"
#define allout(v) {for(auto ele : v)cout<<ele<<" ";cout<<endl;}

int main() {
    Silver_is_better_than_Gold;
    int a,b;
    cin>>a>>b;
    if(a==0 and b>0)cout<<"Silver";
    else{
        b==0 ? cout<<"Gold":cout<<"Alloy";
    }
}
