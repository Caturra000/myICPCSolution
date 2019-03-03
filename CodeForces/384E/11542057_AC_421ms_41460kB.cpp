#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+11;
typedef long long ll;
int a[maxn];
struct ST{
	#define lc o<<1
	#define rc o<<1|1
	ll val[maxn<<2],lazy[maxn<<2];
	void pu(int o){
		val[o]=val[lc]+val[rc];
	}
	void pd(int o,int l,int r){
		if(lazy[o]){
			int m = l+r>>1;
			val[lc]+=lazy[o]*(m-l+1);
			val[rc]+=lazy[o]*(r-m);
			lazy[lc]+=lazy[o];
			lazy[rc]+=lazy[o];
			lazy[o]=0;	
		}
	}
	void build(int o,int l,int r){
		lazy[o]=val[o]=0;
		if(l==r){
//			val[o]=a[l];
			return;
		}
		int m = l+r>>1;
		build(lc,l,m);
		build(rc,m+1,r);
	}
	void update(int o,int l,int r,int L,int R,int v){
		if(L<=l&&r<=R){
			lazy[o]+=v;
			val[o]+=(r-l+1)*v;
			return;
		}
		pd(o,l,r);
		int m = l+r>>1;
		if(L<=m)update(lc,l,m,L,R,v);
		if(R>m)update(rc,m+1,r,L,R,v);
		pu(o);
	}
	ll query(int o,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return val[o];
		}
		pd(o,l,r);
		int m = l+r>>1;
		ll ans=0;
		if(L<=m) ans+=query(lc,l,m,L,R);
		if(R>m) ans+=query(rc,m+1,r,L,R);
		return ans;
	}
}st[2];
int head[maxn],to[maxn<<1],nxt[maxn<<1],tot,tick;
int in[maxn],out[maxn],dep[maxn];
void init(){
	tot=tick=0;
	memset(head,-1,sizeof head);
}
void add(int u,int v){
	to[tot]=v;
	nxt[tot]=head[u];
	head[u]=tot++;
}
void dfs(int u,int p,int d){
	in[u]=++tick;dep[u]=d;
	for(int i = head[u]; ~i; i=nxt[i]){
		int v = to[i];
		if(v==p)continue;
		dfs(v,u,d^1);
	}
	out[u]=tick;
}
int n,m,u,v,x,op;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		st[0].build(1,1,n);st[1].build(1,1,n);
		for(int i = 1; i <  n; i++){
			scanf("%d%d",&u,&v);
			add(u,v);add(v,u);
		}
		dfs(1,-1,0);
		for(int i = 1; i <= m; i++){
			scanf("%d",&op);
			if(op==1){
				scanf("%d%d",&x,&v);
				st[dep[x]].update(1,1,n,in[x],out[x],v);
			}
			else{
				scanf("%d",&x);
				printf("%I64d\n",1ll*a[x]+st[dep[x]].query(1,1,n,in[x],in[x])-st[1-dep[x]].query(1,1,n,in[x],in[x]));
			}
		}
	}
	return 0; 
}