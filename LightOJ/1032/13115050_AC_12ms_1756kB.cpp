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
#include<bitset>
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
const int maxn = 66;
const int MOD = 2520;
const double eps = 1e-10;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[maxn];
ll dp[maxn][2][maxn];
ll DP(int cur,int pre,ll p,int limit){
    if(cur==0) return p;
    if(!limit&&dp[cur][pre][p]!=-1) return dp[cur][pre][p];
    int up=limit?a[cur]:1;
    ll ans=0;
    rep(i,0,up){
        if(pre==1&&i==1) ans+=DP(cur-1,i,p+1,limit&&a[cur]==i);
        else ans+=DP(cur-1,i,p,limit&&a[cur]==i);
    }
    return (limit)?ans:dp[cur][pre][p]=ans;
}
ll solve(ll num){
    if(num==-1)return 0;
    if(num==0) return 0;
    int cur=0;
    while(num){
        a[++cur]=num%2;
        num/=2;
    }
    return DP(cur,0,0,1);
}
int main(){
    memset(dp,-1,sizeof dp);
    int T=read(),kase=0;
    while(T--){
        ll r=read();
        printf("Case %d: ",++kase);
        println(solve(r));
    }
    return 0;
}
