#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5+59321;
ll a[N];

int main() {
    ll n, x;
    cin >> n;
    ll sum = 0;
    for (auto i = 1; i <= n; i++)cin >> a[i];
    cin >> x;
    for(int i =1;  i <=n;i++){
        sum+=a[i];
        if(sum>x){
            cout<<i<<endl;return 0;
        }
    }
    //sum * numb <=x -> numb = x/sum
    ll numb = x/sum;
    ll Cursum =numb * sum;
    ll final = numb*n;  
    for (int i = 1; i <= n; i++) {
        Cursum += a[i];
        final++;
        if (Cursum >x) {
            cout << final;
            return 0;
        }
    }
}