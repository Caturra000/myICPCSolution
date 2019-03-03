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
ll n,m,x,k;
ll G[23][333];
ll sum[233],tmp[233];
#define lowbit(x) (x&-x)
ll count(int S){
	int cnt=0;
	while(S){
		S-=lowbit(S);
		cnt++;
	}
	return cnt;
}
bool test(int S,int i){
	return S&(1<<i);
}
ll greedy(int S,int cnt){
	memcpy(tmp,sum,sizeof sum);
	rep(i,0,30){
		if(S>>i&1) rep(j,1,m){
			tmp[j]-=G[i+1][j];
			tmp[j]+=x;
		}
	}
	sort(tmp+1,tmp+1+m);
	ll res=0,flag=0;
	if(cnt>=m) flag=1;
	if(flag) rep(j,1,m) res+=max(1ll*n*x,tmp[j]);
	if(flag) return res;
	if(cnt<=0) flag=1;
	if(flag) rep(j,1,m) res+=tmp[j];
	if(flag) return res;
	rep(j,1,cnt) res+=max(1ll*n*x,tmp[j]);
	rep(j,cnt+1,m) res+=tmp[j];
	return res;
}
int main(){
	while(cin>>n>>m>>x>>k){
		memset(sum,0,sizeof sum);
		memset(G,0,sizeof G);
		rep(i,1,n)rep(j,1,m) G[i][j]=read();
		rep(j,1,m)rep(i,1,n) sum[j]+=G[i][j];
		ll S=(1<<n)-1;
		ll ans=0;
		rep(j,1,m) ans+=sum[j];
		for(int i=0;i<=S;i++){ // <=
			ll cnt=count(i);
			if(cnt>k) continue;
			ans=max(ans,greedy(i,k-cnt));
		}
		println(ans);
	}
	return 0;
}