#include<bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define yes {cout<<"YES"<<endl;return;}
#define no {cout<<"NO"<<endl;return;}
using namespace std;
const int N = 1e5 + 69;
int a[N], n, Q;
set<ll> dpeak, upeak;


void init() {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) dpeak.insert(i);
        else if (a[i] > a[i - 1]) upeak.insert(i);
    }
}

void Query() {
    ll l, r;
    cin >> l >> r;
    r--;
    l--;
    bool flg = true;

    if (dpeak.upper_bound(l) != dpeak.end()) {
        ll xx = *dpeak.upper_bound(l);
        if (xx <= r) {
            if (upeak.upper_bound(xx) != upeak.end()) {
                if (*upeak.upper_bound(xx) <= r) {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    cin >> n >> Q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init();
    while (Q--)
        Query();
}