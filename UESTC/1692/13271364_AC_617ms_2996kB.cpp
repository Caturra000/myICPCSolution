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
ll dp[503][504],a[503],n,m,b,mod;
int main(){
    while(cin>>n>>m>>b>>mod){
        rep(i,1,n) a[i]=read();
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        // rep(i,1,m){
        //     rep(j,0,b){
        //         dp[i][j]=dp[i-1][j]%mod;
        //         rep(k,1,n){
        //             if(j-a[k]>=0){
        //                 dp[i][j]+=dp[i-1][j-a[k]];
        //                 dp[i][j]%=mod;
        //             }
        //         }
        //     }
        // }
        rep(i,1,n){
            rep(k,1,m){
                rep(j,a[i],b){
                    dp[k][j]+=dp[k-1][j-a[i]];
                    dp[k][j]%=mod;
                }
            }
        }
        ll ans=0;
        rep(i,0,b){
            ans+=dp[m][i]%mod;
            ans%=mod;
        }
        println(ans);
    }
    return 0;
}