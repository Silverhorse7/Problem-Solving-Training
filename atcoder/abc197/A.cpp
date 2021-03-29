#include <bits/stdc++.h>
#define ll long long
const ll mod = 1e9 + 72321;
using namespace std;
#define Speedo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
 void solve()
{
string c;
cin>>c;
for(int i = 1 ; i <c.size();i++)
{
  swap(c[i-1],c[i]);
}
cout<<c;
}

int main()
{
    Speedo;
    solve();
}