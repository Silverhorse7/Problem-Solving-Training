#include<bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define yes {cout<<"YES"<<endl;return;}
#define no {cout<<"NO"<<endl;return;}
using namespace std;
const int N = 10000005;
int arr[N], cnt[N], carry[N];
bool lol[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]), carry[arr[i]]++;
    for (int i = 2; i < N; i++) {
        if (!lol[i]) {
            for (int j = i; j < N; j += i) {
                lol[j] = 1;
                cnt[i] += carry[j];
            }
        }
        cnt[i] += cnt[i - 1];
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        l = min(l, N - 1);
        r = min(r, N - 1);
        cout << cnt[r] - cnt[l - 1] << endl;
    }
}