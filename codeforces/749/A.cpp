#import<cstdio>
int n,p;main(){
    scanf("%d",&n);
    for(printf("%d\n",n/2);n;n-=p)
    printf("%d ",p=n^3?2:3);
}