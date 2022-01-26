#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int cnt = stoi(s);
string two ="";
two+=s[1];
two+=s[2];
two+=s[0];
cnt+=stoi(two);
string three="";
three+=s[2];
three+=s[0];
three+=s[1];
cnt+=stoi(three);
printf("%d",cnt);
}