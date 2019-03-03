#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 1e2+11;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
unsigned int SEED = 19260817;
const ll INF = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int G[MAXN][MAXN],dp[MAXN][MAXN];
int main(){
    int T=read();
    while(T--){
        int n=read();
        rep(i,1,n){
            rep(j,1,i){
                G[i][j]=read();
            }
        }
        memset(dp,0,sizeof dp);
        rep(i,1,n){
            rep(j,1,i){
                if(j==1) dp[i][j]=dp[i-1][j]+G[i][j];
                else if(j==i) dp[i][j]=dp[i-1][j-1]+G[i][j];
                else dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+G[i][j];
            }
        }
        int ans=-1;
        rep(i,1,n) ans=max(ans,dp[n][i]);
        println(ans);
////
    }
    return 0;
}