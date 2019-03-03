#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 5e2+11;
const int MOD = 1e9+7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN];
int dp[MAXN][MAXN],n;
int main(){
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        memset(dp,0x3f,sizeof dp);
        rep(i,1,n) dp[i][i]=1;
        rep(len,2,n){
            rep(i,1,n-len+1){
                int j=i+len-1;
                rep(k,i,j-1){
                    dp[i][j]=min(dp[i][j],dp[i][k] + dp[k+1][j]);
                }
                if(a[i]==a[j]&&len==2) dp[i][j]=1;
                else if(a[i]==a[j]) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);//
            }
        }
        println(dp[1][n]);
    }
    return 0;
}