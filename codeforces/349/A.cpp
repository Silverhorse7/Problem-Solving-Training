# include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ; i <n;i++)
    {
    	cin>>v[i];
    }
    int back75=0;
    int back25=0;
    int back50=0;
     for(int i = 0 ; i <n;i++){
     	if(v[i]==25){
     		back25+=1;
     	}
     	if(v[i]==50){
     		if(back25>0){
     			back25-=1;
     			back50+=1;
     		}
     		else{
     			cout<<"NO"<<endl;return 0;
     		}
     	}
     	if(v[i]==100){
     		if(back50>0 and back25>0){
     			back50-=1;
     			back25-=1;
     		}
     		else if(back25>=3){
     			back25-=3;
     		}
     		else{
     			cout<<"NO"<<endl;return 0;
     		}
     	}    	
    }
    cout<<"YES"<<endl;
}