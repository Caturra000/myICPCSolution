#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;
typedef long long ll;
const int maxn  = 100;
int l[maxn],r[maxn],tl[maxn],tr[maxn];
int n;
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(l,0,sizeof l);memset(r,0,sizeof r);
        int cnt=2; rep(i,1,n/2) l[i]=i,r[i]=n-i+1;
        rep(i,1,n/2) printf("%d %d%s",l[i],r[i],i==n/2?"\n":" ");
        while(cnt<=n-1){
            cnt++;
            int tmp=l[2];
            memcpy(tl,l,sizeof l);
            memcpy(tr,r,sizeof r);
            rep(i,2,n/2-1) l[i]=tl[i+1]; l[n/2]=tr[n/2];
            rep(i,2,n/2) r[i]=tr[i-1]; r[1]=tl[2];
            rep(i,1,n/2) printf("%d %d%s",l[i],r[i],i==n/2?"\n":" ");
        }
    }
    return 0;
}