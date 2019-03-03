#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 233+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp[MAXN][MAXN];
ll gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int a[MAXN];
int g[MAXN][MAXN],n;
int main(){
    while(cin>>n){
        if(n==0) break;
        rep(i,1,n) a[i]=read();
        rep(i,1,n) a[i+n]=a[i];
        rep(i,1,n<<1) rep(j,i+1,n<<1) g[i][j]=g[j][i]=gcd(a[i],a[j]);
        memset(dp,0x3f,sizeof dp);
        rep(i,1,n<<1) dp[i][i]=0;
        // rep(len,2,n+1){
        //     rep(l,1,2*n-len){//l+len-1<2*n => l<=2*n-len
        //         int r=l+len-1;
        //         rep(k,l,r-1){
        //             if(l+n==len+l){
        //                 dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+g[i][k+1]);
        //             }else{
        //                 dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+g[i][r+1]);
        //             }
        //         }
        //     }
        // }
        ll ans=1ll<<60;
        rep(len,2,n){
            rep(l,1,2*n-len+1){
                int r=l+len-1;
                if(len==2){
                    dp[l][r]=0;
                    continue;
                }
                rep(k,l+1,r-1){
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+g[l][r]);
                }
            }
        }
        rep(i,1,n-1) rep(j,i+1,n){
            ans=min(ans,dp[i][j]+dp[j][i+n]+g[i][j]);
        }
        println(ans);
    }
    return 0;
}