#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 1e3+11;
const int MOD = 10007;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int dp[MAXN][MAXN];
char str[MAXN];
int DP(int l,int r){
    if(~dp[l][r]) return dp[l][r];
    if(l>r) return 0;
    if(l==r) return dp[l][r]=1;
    if(l+1==r){
        if(str[l]!=str[r]) return dp[l][r]=2;
        return dp[l][r]=3;
    }
    int ans=(DP(l+1,r)%MOD+DP(l,r-1)%MOD+MOD-DP(l+1,r-1)%MOD)%MOD;
    if(str[l]==str[r]) ans=(ans+DP(l+1,r-1)+1)%MOD;
    return dp[l][r]=ans;
}
int main(){
    int T=read(),kase=0;
    while(T--){
        memset(dp,-1,sizeof dp);
        scanf("%s",str+1);
        int len=strlen(str+1);
        DP(1,len);
        printf("Case %d: %d\n",++kase,dp[1][len]);
    }
    return 0;
}