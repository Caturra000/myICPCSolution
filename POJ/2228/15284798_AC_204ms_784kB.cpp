#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iter(i,j) for(int i=0;i<(j).size();i++)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 4e3+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,b;
int dp[2][MAXN][2],a[MAXN];

int main(){
    while(cin>>n>>b){
        rep(i,1,n) a[i]=read();
        memset(dp,0x80,sizeof dp);
        dp[1][0][0]=dp[1][1][1]=0;
        //1 1 0 invalid 1 0 1 invalid
        int ans=0;
        rep(i,2,n){
            rep(j,0,i){
                if(j>b) break;
                dp[i&1][j][0]=max(dp[i-1&1][j][0],dp[i-1&1][j][1]);
                if(j) dp[i&1][j][1]=max(dp[i-1&1][j-1][0],dp[i-1&1][j-1][1]+a[i]);
            }
        }
        ans=max(dp[n&1][b][0],dp[n&1][b][1]);
        memset(dp,0x80,sizeof dp);
        dp[1][1][1]=a[1];//[n,1]sleep
        rep(i,2,n){
            rep(j,0,i){
                if(j>b) break;
                dp[i&1][j][0]=max(dp[i-1&1][j][0],dp[i-1&1][j][1]);
                if(j) dp[i&1][j][1]=max(dp[i-1&1][j-1][0],dp[i-1&1][j-1][1]+a[i]);
            }
        }
        ans=max(ans,dp[n&1][b][1]);
        println(ans);
    }
    return 0;
}