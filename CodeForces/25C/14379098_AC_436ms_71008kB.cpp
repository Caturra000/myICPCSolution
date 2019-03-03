#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 3e3+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int a[MAXN],pos[MAXN];
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,d[MAXN][MAXN];
int main(){
    while(cin>>n){
        rep(i,1,n)rep(j,1,n) d[i][j]=read();
        rep(i,1,n) d[i][i]=0;
        rep(k,1,n)rep(i,1,n)rep(j,1,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        int k=read();
        while(k--){
            int u=read();
            int v=read();
            ll w=read();
            if(d[u][v]>w){
                d[u][v]=d[v][u]=w;
                rep(i,1,n)rep(j,1,n) d[i][j]=min(d[i][j],d[i][u]+d[u][j]);
                rep(i,1,n)rep(j,1,n) d[i][j]=min(d[i][j],d[i][v]+d[v][j]);
            }
            ll sum=0;
            rep(i,1,n)rep(j,1,n) sum+=d[i][j];
            if(k==0) println(sum/2);
            else printf("%lld ",sum/2);
        }
    }
    return 0;
}