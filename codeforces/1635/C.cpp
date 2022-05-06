#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+10,INF=1e9;
ll a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int f = 0;
        vector<pair<pii, int> > ans;
        for (int i = 1; i <= n;i++)
        {
            cin >> a[i];
        }
        
        if(a[n-1]>a[n])
        {
            cout << "-1\n";
        }
        else
        {
            if(a[n]<0)
            {
                if(is_sorted(a+1,a+1+n))
                {
                    cout << "0\n";
                }
                else
                    cout << "-1\n";
            }
            else
            {
                cout << n - 2 << '\n';
                for (int i = 1; i <= n - 2;i++)
                {
                    cout << i << ' ' << n - 1 << ' ' << n << '\n';
                }
            }
        }
    }

    return 0;
}
