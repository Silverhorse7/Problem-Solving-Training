#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define ll long long
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
#define vi vector<int>
#define in(v, n) {for(int i =1 ;  i <=n;i++)cin>>v[i];}
#define oo 12345678912345678

int main() {
    ll R,X,Y;
    cin>>R>>X>>Y;
    double D = sqrt(X*X+Y*Y);
    cout << (D == R ? 1 : D <= R + R ? 2 : ceil(D / R));
}