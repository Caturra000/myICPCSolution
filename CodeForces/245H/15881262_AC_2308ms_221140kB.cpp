#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 5e3+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char str[MAXN],can[MAXN][MAXN];
ll dp[MAXN][MAXN];
int main(){
    while(~scanf("%s",str+1)){
        memset(dp,0,sizeof dp);
        memset(can,0,sizeof can);
        int n=strlen(str+1);
        rep(i,1,n) dp[i][i]=1,can[i][i]=1;
        rep(i,1,n-1){
            if(str[i]==str[i+1]) can[i][i+1]=1,dp[i][i+1]=3;
            else dp[i][i+1]=2;
        }
        rep(len,3,n){
            rep(l,1,n-len+1){
                int r=l+len-1;
                dp[l][r]=dp[l][r-1]+dp[l+1][r]-dp[l+1][r-1];
                can[l][r]=can[l+1][r-1]&&(str[l]==str[r]);
                if(can[l][r]) dp[l][r]++;
            }
        }
        int q=read();
        while(q--){
            int l=read();
            println(dp[l][read()]);
        }
    }
    return 0;
}