#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    if(x<=a){
        cout<<1<<endl;
    }
    else if(x>b)
        cout<<0<<endl;
    else{
        cout<<static_cast<double>(c)/(b-a)<<endl;
    }
}