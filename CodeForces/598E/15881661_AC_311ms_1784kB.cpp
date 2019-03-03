#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 50+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp[MAXN][MAXN][MAXN];
ll DP(int n,int m,int k){
    if(~dp[n][m][k]) return dp[n][m][k];
    if(k==n*m||k<=0) return 0;
    if(k>n*m) return 1ll<<59;
    ll ans=1ll<<60;
    rep(i,1,n-1) rep(j,0,k) ans=min(ans,DP(i,m,j)+DP(n-i,m,k-j)+m*m);
    rep(i,1,m-1) rep(j,0,k) ans=min(ans,DP(n,i,j)+DP(n,m-i,k-j)+n*n);
    return dp[n][m][k]=ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    int T=read();
    while(T--){
        int n=read();
        int m=read();
        int k=read();
        println(DP(n,m,k));
    }
    return 0;
}
