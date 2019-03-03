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
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,p[MAXN];
int find(int x){
	if(x==-1) return x;
	if(p[x]==x) return p[x]=x-1;
	return p[x]=find(p[x]);
}
struct P{
	ll ed,cost;
}a[MAXN];
bool cmp(P a,P b){
	return a.cost>b.cost;
}
int main(){
	while(cin>>n){
		rep(i,1,n) p[i]=i;
		rep(i,1,n){
			a[i].ed=min((ll)n,read());
			a[i].cost=read();
		}
		sort(a+1,a+1+n,cmp);
		ll ans=0;
		rep(i,1,n) if(~find(a[i].ed)){
			ans+=a[i].cost;
		}
		println(ans);
	}
	return 0;
}