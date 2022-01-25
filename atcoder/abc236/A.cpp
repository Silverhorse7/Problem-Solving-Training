#include<bits/stdc++.h>

using namespace std;

long long AnswerC() {

}

int main() {
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    swap(s[x-1],s[y-1]);
    cout<<s;
}