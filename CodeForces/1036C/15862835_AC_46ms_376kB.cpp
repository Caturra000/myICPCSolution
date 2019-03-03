#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 1e4+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll xx = 0x3f3f3f3f;
const int MOD = 1000000007;
ll read(){
   ll x=0,f=1;register char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
ll dp[133][133];
ll a[133];
ll DP(int cur,int limit,int x){
    if(cur==0) return x<=3;
    if(dp[cur][x]!=-1&&!limit) return dp[cur][x];
    int up=limit?a[cur]:9;
    ll ans=0;
    rep(i,0,up){
        ans+=DP(cur-1,limit&&a[cur]==i,x+(i!=0));
    }
    return limit?ans:dp[cur][x]=ans;
}
ll solve(ll x){
    if(x==-1) return 0;
    int cur=0;
    while(x){
        a[++cur]=x%10;
        x/=10;
    }
    return DP(cur,1,0);
}
int main(){
    int T=read();
    memset(dp,-1,sizeof dp);
    while(T--){
        ll l=read();
        ll r=read();
        println(solve(r)-solve(l-1));
    }
    return 0;
} 