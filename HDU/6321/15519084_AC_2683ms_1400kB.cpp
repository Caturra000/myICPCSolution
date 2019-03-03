#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 1e6+11;
const int MOD = 1e9+7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp[2][1<<10|1];
ll ans[222];
int cnt[1<<10|1];
int main(){
    int T=read();
    rep(i,0,1<<10) cnt[i]=__builtin_popcount(i);
    while(T--){
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        int n=read(); int S=1<<n;
        int m=read();
        char op[55];
        int cur=0;
        while(m--){
            cur++;
            scanf("%s",op);
            int u=read()-1;
            int v=read()-1;
            int s=1<<u; s|=1<<v;
            rep(i,0,S-1) dp[cur&1][i]=dp[cur-1&1][i];
            if(op[0]=='+') rep(i,0,S-1){
                if(i&s) continue;
                dp[cur&1][i^s]=(dp[cur&1][i^s]+dp[cur-1&1][i])%MOD;
            }else rep(i,0,S-1){
                if(i&s) continue;
                dp[cur&1][i^s]=(dp[cur&1][i^s]+MOD-dp[cur-1&1][i])%MOD;
            }
            rep(i,0,100) ans[i]=0;
            rep(i,0,S-1) ans[cnt[i]]=(ans[cnt[i]]+dp[cur&1][i])%MOD;
            rep(i,1,n) if((i&1)==0){
                if(i==n) println(ans[i]);
                else printbk(ans[i]);
            }
        }
    }
    return 0;
}