#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
 
int len;
struct Opts{
	int l,r,id;
	inline void Reader(){
		scanf("%d%d",&l,&r);
	}
	inline bool operator<(const Opts&p){
		return l/len==p.l/len?r<p.r:l<p.l;
	}
};Opts Qry[1100000];
 
int Tot[110000],Arr[110000];
int ans;
inline void Add(int x){
	ans-=Tot[Arr[x]]/2;
	Tot[Arr[x]]++;
	ans+=Tot[Arr[x]]/2;
}
inline void Del(int x){
	ans-=Tot[Arr[x]]/2;
	Tot[Arr[x]]--;
	ans+=Tot[Arr[x]]/2;
}
int n,q,Ans[1100000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&Arr[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		Qry[i].Reader();
		Qry[i].id=i;
	}
	len=int(1.0*n/sqrt(q))+1;
	sort(Qry+1,Qry+q+1);
	int l=0,r=0;
	for(int i=1;i<=q;i++){
		while(l<Qry[i].l)Del(l++);
		while(l>Qry[i].l)Add(--l);
		while(r<Qry[i].r)Add(++r);
		while(r>Qry[i].r)Del(r--);
		Ans[Qry[i].id]=ans;
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",Ans[i]);
	}
	return 0;
}