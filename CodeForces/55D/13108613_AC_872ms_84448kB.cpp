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
const int maxn = 30;
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
ll dp[maxn][2655][50];
ll a[maxn],cnt;
ll LCM[2522][2522];
ll save[5678];

inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll DP(int cur,int mod,int lastLcm,bool limit){
    if(cur==0&&(mod%lastLcm==0)) return 1;
    else if(cur==0) return 0;
    if(dp[cur][mod][save[lastLcm]]!=-1&&!limit) return dp[cur][mod][save[lastLcm]];
    int up=limit?a[cur]:9;
    ll ans=0;
    rep(i,0,up){
        int le=lastLcm,ri=max(1,i);
        if(le>ri)swap(le,ri);
        ll nowLcm=LCM[le][ri];
        ans+=DP(cur-1,(mod*10+i)%MOD,nowLcm,limit&&a[cur]==i);
    }
    if(!limit) dp[cur][mod][save[lastLcm]]=ans;
    return ans;
}
ll solve(ll num){
    memset(a,0,sizeof a);
    int cur=0;
    while(num){
        a[++cur]=num%10;
        num/=10;
    }
    return DP(cur,0,1,1);
}
int main(){
    rep(i,1,2520)rep(j,i,2520){
        LCM[i][j]=lcm(i,j);
    }
    rep(i,1,2520){
        if(MOD%i==0)save[i]=++cnt;
    }
    int T=read();
    memset(dp,-1,sizeof dp);//!!!!
    while(T--){
        ll l=read();
        ll r=read();
        printf("%lld\n",solve(r)-solve(l-1));
    }
    return 0;
}