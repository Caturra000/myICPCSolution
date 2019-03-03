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
const int maxn = 1e6+11;
const double eps = 1e-10;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
// char str[maxn],strr[maxn];
// int dp[maxn][maxn];
// string ans[maxn][maxn];
// int main(){
//     while(~s1(str)){
//         int n=read();
//         rep(i,1,n) strr[n-i+1]=str[i];
//         memset(dp,0,sizeof dp);
//         rep(i,0,n)rep(j,0,n) ans[i][j]=" ";
//         int len=0;
//         rep(i,1,n) rep(j,1,n){
//             if(str[i]==strr[j]){
//                 dp[i][j]=dp[i-1][j-1]+1;
//                 ans[i][j]=ans[i-1][j-1]+str[i];
//             }else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 if(dp[i-1][j]>dp[i][j-1]) ans[i][j]=ans[i-1][j];
//                 else if(dp[i][j-1]>dp[i-1][j]) ans[i][j]=ans[i][j-1];
//                 else if(ans[i][j-1]<ans[i-1][j]) ans[i][j]=ans[i][j-1];
//                 else ans[i][j]=ans[i-1][j];
                
//             }
//         }
//         if(dp[n][n]&1){
//             rep(i,1,(dp[n][n]+1)/2) printf("%c",ans[n][n][i]);
//             rep(i,1,dp[n][n]/2) printf("%c",ans[n][n][dp[n][n]/2-i+1]);
//             cout<<endl;
//         }else{
//             rep(i,1,dp[n][n]/2) printf("%c",ans[n][n][i]);
//             rep(i,1,dp[n][n]/2) printf("%c",ans[n][n][dp[n][n]/2-i+1]);
//             cout<<endl;
//         }
//     }
//     return 0;
// }
// bool G[maxn][maxn];
ll S[maxn],dp[maxn],U[maxn],st;
char str[maxn];
int main(){
    int T=read(),kase=0;
    while(T--){
        memset(S,0,sizeof S);st=0;
        memset(U,0,sizeof U);
        memset(dp,0,sizeof dp);
        dp[0]=1;
        int n=read();
        s0(str);rep(i,0,n-1)if(str[i]=='1')st|=(1<<i);
        rep(i,0,n-1){
            s0(str);
            rep(j,0,n-1) if(str[j]=='1') S[i]|=(1<<j);
        }
        rep(i,0,((1<<n)-1)){
            U[i]=st;
            rep(j,0,n-1){
                if((i>>j)&1) U[i]|=S[j];//dangqian wuqi jihe neng shasi de diren
            }
        }
        rep(i,1,(1<<n)-1){
            dp[i]=0;
            rep(j,0,n-1){
                if((U[i^(1<<j)]&i)&(1<<j)){
                    dp[i]+=dp[i^(1<<j)];
                }
            }
        }
        printf("Case %d: ",++kase);
        println(dp[(1<<n)-1]);
    }
    return 0;
}