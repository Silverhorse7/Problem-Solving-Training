#include <bits/stdc++.h>

using namespace std;
#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
const int N = 1e3 + 33;
int n;
int a[N],an[N],f[N];
long long __gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return __gcd(b, a % b);
}

signed main() {
    T {
        for(int i = 0 ; i <=N;i++)an[i]=a[i]=f[i]=0;
        cin >> n;
        int col = 0 ;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            for (int j=2; j<=1000; j++) if (a[i]%j==0)
                {
                    an[i]=j;
                    break;
                }
            if (!f[an[i]]) f[an[i]]=++col;
        }
        cout<<col<<endl;
        for(int i =1 ; i <=n;i++)cout<<f[an[i]]<<' ';cout<<endl;
    }
}