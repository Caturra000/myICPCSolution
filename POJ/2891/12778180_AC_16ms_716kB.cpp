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
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;
        return a;
    }else{
        ll g=exgcd(b,a%b,x,y);
        ll tmp=x;
        x=y;y=tmp-a/b*x;
        return g; 
    }
}
ll inv(ll n,ll m){
	ll g=gcd(n,m);
	if(g!=1) return -1;
    ll x,y;
    exgcd(n,m,x,y);
    return (x%m+m)%m;
}
bool merge(ll a1,ll mod1,ll a2,ll mod2,ll &a3,ll &mod3){
	ll d=gcd(mod1,mod2);
	ll c=a2-a1;
	if(c%d!=0)return 0;
	mod1/=d; mod2/=d; c/=d;
	c*=inv(mod1,mod2);
	c%=mod2;
	c*=mod1*d;
	c+=a1;
	mod3=mod1*mod2*d;
	a3=(c%mod3+mod3)%mod3;
	return 1;
}
ll CRT(ll a[],ll mod[],ll n){
    ll a1=a[1];
    ll mod1=mod[1];
    rep(i,2,n){
    	ll a2=a[i];
    	ll mod2=mod[i];
    	ll mod3,a3;
    	if(!merge(a1,mod1,a2,mod2,a3,mod3))return -1;
    	a1=a3;
    	mod1=mod3;
	}
	return (a1%mod1+mod1)%mod1;
}
int n;
ll mod[maxn],a[maxn];
int main(){
	while(cin>>n){
		rep(i,1,n){
			mod[i]=read();
			a[i]=read();
		}
		ll ans=CRT(a,mod,n);
		println(ans);
	}
	return 0;
} 