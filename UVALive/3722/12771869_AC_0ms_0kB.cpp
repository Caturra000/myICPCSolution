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
ll MOD = 1e9+7;
inline ll mod(ll a){return a%MOD;}
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll fpw(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=mod(ans*a);
		n>>=1;
		a=mod(a*a);
	}
	return ans;
}
int sum(int p,int n){
    if(n==0)return 1;
    if(n&1) return mod(mod(1+fpw(p,n+1>>1))*mod(sum(p,n-1>>1)));
    else return mod(mod(1+fpw(p,n>>1))*mod(sum(p,(n>>1)-1))+mod(fpw(p,n)));
}
int main(){
	ll x,a,n;
	while(cin>>x>>a>>n>>MOD){
		if(x==0&&a==0&&n==0&&MOD==0)break;
		cout<<mod(mod(mod(fpw(a,n)*(x-1))-sum(a,n-1)+MOD)+1+MOD)<<endl;
	}
	return 0;
}