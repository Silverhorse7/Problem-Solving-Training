#include<bits/stdc++.h>
using namespace std;
int main(){
    int N; cin >> N;
    vector<double> l(N),r(N);
    for(int i=0; i<N; i++){
        int t; cin >> t >> l[i] >> r[i];
        t--;
        if(t&1) r[i] -= 0.5;
        if(t&2) l[i] += 0.5;
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            ans += (max(l[i],l[j]) <= min(r[i],r[j]));
        }
    }
    cout << ans << endl;
}