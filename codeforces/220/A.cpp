#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int>cpy=v;
    sort(cpy.begin(), cpy.end());
    int cnt=  0 ;
    for(int i = 0 ; i <n;i++){
        if(cpy[i]!=v[i])cnt++;
    }
    if(cnt>2)return cout<<"NO",0;
    cout<<"YES";
}