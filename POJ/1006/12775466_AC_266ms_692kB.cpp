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
ll a[66],mod[66];
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;
		return a;
	}else{
		ll gcd=exgcd(b,a%b,x,y);
		ll tmp=x;
		x=y;y=tmp-a/b*x;
		return gcd; 
	}
}
ll inv(ll n,ll m){
	ll x,y;
	exgcd(n,m,x,y);
	return (x%m+m)%m;
}
ll CRT(ll a[],ll mod[],ll n){
	ll ans=0,MOD=1;
	rep(i,1,n) MOD*=mod[i];
	rep(i,1,n){
		ll Mi=MOD/mod[i];
		ans=(ans+a[i]*Mi*inv(Mi,mod[i]))%MOD;
	}
	if(ans<0) ans+=MOD;
	return ans;
	
}
int main(){
	int kase=0;
	ll P,E,I,D;	
	while(cin>>P>>E>>I>>D){
		if(P==-1&&E==-1&&I==-1&&D==-1)break;
		mod[1]=23;mod[2]=28;mod[3]=33;
		a[1]=P;a[2]=E;a[3]=I;
		ll ans=CRT(a,mod,3);
		if(ans-D<=0) ans+=21252;
		printf("Case %d: the next triple peak occurs in %lld days.\n",++kase,ans-D);
	}
	return 0;
} 