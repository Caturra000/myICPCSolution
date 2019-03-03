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
const int MAXN = 5e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7;
ll read() {
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int k;
char str[MAXN];
int a[MAXN],f[MAXN];
ll dp[1007][1007][11];
int F(int x){ // x(10)->1(2)
    if(x<=1) return 0;
    if(~f[x]) return f[x];
    int cnt=0;
    while(x){
        cnt+=(x&1);
        x>>=1;
    }
    return f[x]=1+F(cnt);
}
ll DP(int cur,int _1,int k,bool limit){
    if(cur==0) return F(_1)==k-1;
    if(!limit&&dp[cur][_1][k]!=-1) return dp[cur][_1][k];
    int up=limit?a[cur]:1;
    ll ans=0;
    rep(i,0,up){
        ans+=DP(cur-1,_1+i,k,limit&&a[cur]==i)%MOD;
        ans%=MOD;
    }
    return limit?ans:dp[cur][_1][k]=ans;
}
ll solve(){
    int len=strlen(str+1);
    rep(i,1,len) a[i]=str[len-i+1]-'0';
    return DP(len,0,k,1);
}
int main(){
    memset(f,-1,sizeof f);
    memset(dp,-1,sizeof dp);
    while(~scanf("%s",str+1)){
        k=read();
        if(k>10){
            println(0);
        }else if(k==1){
            ll tmp=solve();
            tmp=((tmp-2)%MOD+MOD)%MOD;
            println(tmp);
        }else if(k==0){
            println(1);
        }
        else{
            println(solve());
        }
    } 
    return 0;
}