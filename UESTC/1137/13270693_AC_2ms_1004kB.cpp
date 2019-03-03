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
const int maxn = 5e4+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
// int n,c;
// ll a[maxn];
// ll dp[2][107];
// int main(){
//     while(~scanf("%d%d",&n,&c)){
//         ll h=0;
//         rep(i,1,n) a[i]=read();
//         rep(i,1,n) h=max(h,a[i]);
//         memset(dp,0x3f,sizeof dp);
//         rep(i,0,106) dp[1][i]=i*i;
//         rep(i,2,n){
//             rep(j,0,h){
//                 dp[i&1][j]=dp[i-1&1][0]+j*j+c*abs(a[i]-a[i-1]+j-0);
//                 rep(k,1,h){
//                     dp[i&1][j]=min(dp[i&1][j],dp[i-1&1][k]+j*j+c*abs(a[i]-a[i-1]+j-k));
//                 }
//             }
//         }
//         ll mn=1ll<<60;
//         rep(i,0,h) mn=min(mn,dp[n&1][i]);
//         println(mn);
//     }
//     return 0;
// }
ll dp[233][2],a[233];
ll dfs(int cur,int limit,int _6){
    if(cur==0) return 1;
    if(~dp[cur][_6]&&!limit) return dp[cur][_6];
    int up=limit?a[cur]:9;
    ll ans=0;
    rep(i,0,up){
        if(i==2&&_6)continue;
        if(i==4)continue;
        ans+=dfs(cur-1,limit&&a[cur]==i,i==6);
    }
    return limit?ans:dp[cur][_6]=ans;
}
ll solve(int x){
    int cur=0;
    while(x){
        a[++cur]=x%10;
        x/=10;
    }
    return dfs(cur,1,0);
}
int main(){
    int l,r;
    memset(dp,-1,sizeof dp);
    while(~scanf("%d%d",&l,&r)){
        if(l==r&&r==0)break;
        println(solve(r)-solve(l-1));
    }
    return 0;
}