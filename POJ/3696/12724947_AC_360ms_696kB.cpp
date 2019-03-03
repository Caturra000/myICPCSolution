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
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll euler(ll n){
    ll ans=n;
    for(ll i = 2; i*i <= n; i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}
ll fmp(ll a,ll b,ll m){
	ll ans=0;
	while(b){
		if(b&1) ans=(ans+a)%m;
		a=(a+a)%m;
		b>>=1;
	}
	return ans;
}
ll fpw(ll a,ll n,ll m){
	ll ans=1;
	while(n){
		if(n&1) ans=fmp(ans,a,m);
		a=fmp(a,a,m);
		n>>=1;
	}
	return ans;
}
int main(){
	ll L,kase=0;
	while(cin>>L){
		if(L==0) break;
		L=9ll*L/gcd(L,8);
		printf("Case %lld: ",++kase);
		if(gcd(10,L)!=1){
			println(0);
			continue;
		}
		ll p=euler(L);
		ll ans=p;
		for(ll i=1; i*i<=p; i++){
			if(p%i!=0)continue;
			if(fpw(10,i,L)==1){
				ans=min(ans,i);
			}
			if(i*i!=p&&fpw(10,p/i,L)==1){
				ans=min(ans,p/i);
			}
		}
		println(ans);
	}
	return 0;
}
