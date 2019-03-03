#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 555;
typedef long long ll;
const ll INF=1ll<<31;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll w[MAXN][MAXN],d[MAXN][MAXN],n,x[MAXN],ans[MAXN];
int main(){
    while(cin>>n){
        rep(i,1,n)rep(j,1,n) w[i][j]=read(),d[i][j]=INF;
        rep(i,1,n) d[i][i]=w[i][i]=0,x[n-i+1]=read();
        rep(k,1,n){
            rep(i,1,k){
                d[x[k]][x[i]]=min(d[x[k]][x[i]],w[x[k]][x[i]]);
                d[x[i]][x[k]]=min(d[x[i]][x[k]],w[x[i]][x[k]]);
            }
            rep(i,1,k){
                rep(j,1,k){
                    d[x[k]][x[i]]=min(d[x[k]][x[i]],d[x[k]][x[j]]+d[x[j]][x[i]]);
                    d[x[i]][x[k]]=min(d[x[i]][x[k]],d[x[i]][x[j]]+d[x[j]][x[k]]);
                }
            }
            rep(i,1,k){
                rep(j,1,k){
                    d[x[i]][x[j]]=min(d[x[i]][x[j]],d[x[i]][x[k]]+d[x[k]][x[j]]);
                }
            }
            ans[k]=0;
            rep(i,1,k){
                rep(j,1,k){
                    ans[k]+=d[x[i]][x[j]];
                }
            }
        }
        for(int i=n;i>=1;i--){
            if(i==1) println(ans[i]);
            else printf("%lld ",ans[i]);
        } 
    }
    return 0;
}