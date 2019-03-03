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
const int maxn = 1e3+11;
const double eps = 1e-10;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
// ll dp[maxn][2];
// int to[maxn<<1],nxt[maxn<<1],head[maxn],tot;
// void init(){
//     memset(head,-1,sizeof head);
//     tot=0;
// }
// void add(int u,int v){
//     to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
//     swap(u,v);
//     to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
// }
// ll M;
// bool isleaf(int u,int fa){
//     int cnt=0;
//     erep(i,u){
//         int v=to[i];
//         if(v==fa)continue;
//         cnt++;
//         if(cnt==1)return 0;
//     }
//     return 1;
// }
// int deg[maxn];
// ll DP(int u,int fa,int flag){
//     if(~dp[u][flag]) return dp[u][flag];
//     if(isleaf(u,fa)) return dp[u][flag]=flag*M;
//     ll ans=flag*M;
//     if(flag==1) erep(i,u){
//         int v=to[i];
//         if(v==fa)continue;
//         ans+=min(DP(v,u,0)+1,DP(v,u,1));
//     }else erep(i,u){
//         int v=to[i];
//         if(v==fa)continue;
//         ans+=DP(v,u,1)+1;
//     }
//     return dp[u][flag]=ans;
// }
// bool vis[maxn][2];
// ll DP(int u,int fa,int flag){//fujiedianfangdengwei true
//     if(vis[u][flag])return dp[u][flag];
//     vis[u][flag]=1;
    
//     //ru guo u shi gen na ye ke yi bu fang deng jiagen wei 0 gen yewei 0
//     if(flag==0){
//         dp[u][0]=M+bool(fa!=0);//virtual root
//         erep(i,u){
//             int v=to[i];
//             if(v==fa)continue;
//             dp[u][0]+=DP(v,u,1);
//         }
//         ll tmp=1ll<<60;
//         if(fa==0){
//             tmp=0;
//             erep(i,u){
//                 int v=to[i];
//                 if(v==fa)continue;
//                 tmp+=DP(v,u,0);
//             }
//         }
//         return dp[u][0]=min(dp[u][0],tmp);//ok
//     }else{
//         // dp[u][1]+=min(DP(v,u,1),DP(v,u,0));//cannot dfs
//         ll tmp1=M;//u fangdeng
//         erep(i,u){
//             int v=to[i];
//             if(v==fa)continue;
//             tmp1+=DP(v,u,1);
//         }
//         ll tmp2=1;//bufangdeng
//         erep(i,u){
//             int v=to[i];
//             if(v==fa)continue;
//             tmp2+=DP(v,u,0);
//         }
//         return dp[u][1]=min(tmp1,tmp2);
//     }
// }
// int main(){
//     int T=read();
//     while(T--){
//         init();
//         memset(dp,-1,sizeof dp);
//         memset(vis,0,sizeof vis);
//         int n=read();
//         int m=read();
//         rep(i,1,m){
//             int u=read();u++;
//             int v=read();v++;
//             add(u,v);
//         }
//         M=2333;
//         ll ans=0;
//         rep(i,1,n){
//             if(!vis[i][0]){
//                 ans+=DP(i,0,0);
//             }
//         }
//         printf("%lld %lld %lld\n",ans/M,m-(ans%M),ans%M);
//     }
//     return 0;
// }
char str[maxn],strr[maxn];
int dp[maxn][maxn];
string ans[maxn][maxn];
int main(){
    while(~s1(str)){
        int n=strlen(str+1);
        rep(i,1,n) strr[n-i+1]=str[i];
        memset(dp,0,sizeof dp);
        rep(i,0,n)rep(j,0,n) ans[i][j]=" ";
        int len=0;
        rep(i,1,n) rep(j,1,n){
            if(str[i]==strr[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                ans[i][j]=ans[i-1][j-1]+str[i];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(dp[i-1][j]>dp[i][j-1]) ans[i][j]=ans[i-1][j];
                else if(dp[i][j-1]>dp[i-1][j]) ans[i][j]=ans[i][j-1];
                else if(ans[i][j-1]<ans[i-1][j]) ans[i][j]=ans[i][j-1];
                else ans[i][j]=ans[i-1][j];
                
            }
        }
        if(dp[n][n]&1){
            rep(i,1,(dp[n][n]+1)/2) cout<<ans[n][n][i];
            rep(i,1,dp[n][n]/2) cout<<ans[n][n][dp[n][n]/2-i+1];
            cout<<endl;
        }else{
            rep(i,1,dp[n][n]/2) cout<<ans[n][n][i];
            rep(i,1,dp[n][n]/2) cout<<ans[n][n][dp[n][n]/2-i+1];
            cout<<endl;
        }
        // cout<<ans[n][n]<<endl;
    }
    return 0;
}