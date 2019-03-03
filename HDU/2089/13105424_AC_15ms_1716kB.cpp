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
ll dp[maxn][2],a[maxn],l,r;
ll DP(int cur,int pre,bool _6,bool limit){
    if(cur==0) return 1;
    if(dp[cur][_6]!=-1&&!limit)return dp[cur][_6];
    int up=(limit?a[cur]:9);
    ll ans=0;
    rep(i,0,up){
        if(i==4)continue;
        if(i==2&&_6)continue;
        ans+=DP(cur-1,i,i==6,limit&&a[cur]==i);
    }
    return limit?ans:(dp[cur][_6]=ans);
}
ll solve(ll num){
    memset(a,0,sizeof a);
    memset(dp,-1,sizeof dp);
    int cur=0;
    while(num){
        a[++cur]=num%10;
        num/=10;
    }
    return DP(cur,-1,0,1);
}
int main(){
    while(cin>>l>>r){
        if(l==0&&r==0)break;
        println(solve(r)-solve(l-1));
    }
    return 0;
}