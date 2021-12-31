#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i: a)cin >> i;
    set<int> us;
    vector<bool> flag(m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <= a[i]; j++) {
            while (a[i] % j == 0) {
                us.insert(j);
                a[i] /= j;
            }
        }
        if(a[i]>1)us.insert(a[i]);
    }
    for (auto i: us) {
        if(flag[i]==1)continue;
        for (int j = i; j <= m; j += i) {
            flag[j] = 1;
        }
    }
    cout<<count(flag.begin()+1,  flag.end(),0)<<endl;
    for(int i =1 ; i <=m;i++){
        if(flag[i]==0){
            cout<<i<<endl;
        }
    }

}