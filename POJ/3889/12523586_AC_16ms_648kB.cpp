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
const int maxn = 1e5+11;
const double eps = 1e-7;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

typedef pair<ll,ll> P;
inline double sqr(ll x){return (double)x*x;}
P cal(ll x,ll n){
    if(n==1){
        if(x==1) return P(1,1);
        if(x==2) return P(1,2);
        if(x==3) return P(2,2);
        if(x==4) return P(2,1);
    }
    ll t=1ll<<(n-1);
    ll a=(x-1)/(t*t)+1;//1 based
    ll b=(x-1)%(t*t)+1;
    if(a==1){
        P p=cal((t*t)-b+1,n-1);
        return P(p.second,t-p.first+1);
    }
    if(a==2){
        P p=cal(b,n-1);
        return P(p.first,t+p.second);
    }
    if(a==3){
        P p=cal(b,n-1);
        return P(t+p.first,t+p.second);
    }
    if(a==4){
        P p=cal((t*t)-b+1,n-1);
        return P(2*t-p.second+1,p.first);
    }
}
int main(){
    int T=read();
    while(T--){
        ll n=read();
        ll s=read();
        ll t=read();
        P a=cal(s,n);
        P b=cal(t,n);
        println((double)(sqrt(sqr(a.first-b.first)+sqr(a.second-b.second))*10+0.5));
    }
    return 0;
}