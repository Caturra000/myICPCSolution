#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
int a[maxn],l,r,n,q;ll v;
char str[10];
struct ST{
	int lc[maxn<<2],rc[maxn<<2],lx[maxn<<2],rx[maxn<<2];;
	ll lazy[maxn<<2],sum[maxn<<2];
	int root,tot;
	void init(){
		root=tot=0;
		memset(lazy,0,sizeof lazy);
	}
	int node(){
		lc[tot]=rc[tot]=lx[tot]=rx[tot]=0;
		lazy[tot]=sum[tot]=0;
		return tot++;
	}
	void pu(int now){
		sum[now]=sum[lc[now]]+sum[rc[now]];
	}
	int build(int l,int r){
		int now=node();
		lx[now]=l;rx[now]=r;
		if(l==r){
			sum[now]=a[l];
			return now;
		}
		int m=(l+r)>>1;
		lc[now]=build(l,m);
		rc[now]=build(m+1,r);
		pu(now);
		return now; 
	}
	int len(int now){
		return rx[now]-lx[now]+1;
	}
	void pd(int now){
		if(lazy[now]){
			sum[lc[now]]+=len(lc[now])*lazy[now];
			sum[rc[now]]+=len(rc[now])*lazy[now];
			lazy[lc[now]]+=lazy[now];
			lazy[rc[now]]+=lazy[now];
			lazy[now]=0; 
		}
	}
	void update(int now,int L,int R,ll v){
		if(L<=lx[now]&&rx[now]<=R){
			sum[now]+=len(now)*v;
			lazy[now]+=v;
			return;
		}
		int m=(lx[now]+rx[now])>>1;
		pd(now);
		if(L<=m) update(lc[now],L,R,v);
		if(R>m) update(rc[now],L,R,v);
		pu(now); 
	}
	ll query(int now,int L,int R){
		if(L<=lx[now]&&rx[now]<=R){
			return sum[now];
		}
		int m=(lx[now]+rx[now])>>1;
		pd(now);
		ll ans=0;
		if(L<=m) ans+=query(lc[now],L,R);
		if(R>m) ans+=query(rc[now],L,R);
		return ans;
	}
}st;
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		st.init();st.build(1,n);
		for(int i = 1; i <= q; i++){
			scanf("%s",str);
			if(str[0]=='C'){
				scanf("%d%d%lld",&l,&r,&v);
				st.update(st.root,l,r,v);
			} 
			else{
				scanf("%d%d",&l,&r);
				printf("%lld\n",st.query(st.root,l,r));
			}
		}
	}
	return 0;
} 