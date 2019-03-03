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
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[maxn<<1],nxt[maxn<<1],cost[maxn<<1],head[maxn],tot;
int prexor[maxn<<1];
void add(int u,int v,int w){
	to[tot]=v;cost[tot]=w;nxt[tot]=head[u];head[u]=tot++;
	swap(u,v);
	to[tot]=v;cost[tot]=w;nxt[tot]=head[u];head[u]=tot++;
}
void init(){
	memset(head,-1,sizeof head);
	prexor[0]=0;
	tot=0;
}
struct Trie{
	int son[maxn<<4][2],b[67],tot;
	void init(){
		memset(son,0,sizeof son);
		tot=0;
	}
	void insert(ll x){
		int now=0;
		rep(i,0,31){
			b[i]=x&1;x>>=1;
		}
		rrep(i,31,0){
			if(!son[now][b[i]]) son[now][b[i]]=++tot;
			now=son[now][b[i]];
		}
	}
	ll find(ll x){
		int now=0;
		ll ans=0;
		rep(i,0,31){
			b[i]=x&1;x>>=1;
		}
		rrep(i,31,0){
			if(son[now][b[i]^1]){
				now=son[now][b[i]^1];
				ans+=(1ll<<i);
			}else{
				now=son[now][b[i]];
			}
		}
		return ans;
	}
}trie;
void dfs(int u,int fa,int lastXor){
	erep(i,u){
		int v=to[i],w=cost[i];
		if(v==fa)continue;
		prexor[v]=lastXor^w;
		dfs(v,u,prexor[v]);
	}
}
int main(){
	int n,u,v,w;
	while(~iin(n)){
		init();
		rep(i,1,n-1){
			u=read();u++;
			v=read();v++;
			w=read();
			add(u,v,w);
		}
		dfs(1,0,0ll);
		trie.init();
		rep(i,1,n) trie.insert(prexor[i]);
		ll ans=0;
		rep(i,1,n) ans=max(ans,trie.find(prexor[i]));
		println(ans);
	}
	return 0;
} 