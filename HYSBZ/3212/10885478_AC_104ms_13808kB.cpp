#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+11;
struct ST{
	int lc[maxn<<2],rc[maxn<<2],lx[maxn<<2],rx[maxn<<2];
	ll sum[maxn<<2],lazy[maxn<<2];
	int root,tot;
	int t;
	void init(){
		memset(lazy,0,sizeof lazy);
		tot=root=0;
	}
	int node(){
		lc[tot]=rc[tot]=sum[tot]=0;
		return tot++;
	}
	void pu(int now){
		sum[now]=sum[lc[now]]+sum[rc[now]];
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
	int build(int l,int r){
		int now=node();
		lx[now]=l;rx[now]=r;
		if(l==r){
			scanf("%d",&t);
			sum[now]=t;
			return now;
		} 
		int m=(l+r)>>1;
		lc[now]=build(l,m);
		rc[now]=build(m+1,r);
		pu(now);
		return now;
	}
	void update(int now,int L,int R,int v){
		if(L<=lx[now]&&rx[now]<=R){
			sum[now]+=len(now)*v;
			lazy[now]+=v;//NOTE
			return;
		}
		pd(now);
		int m=(lx[now]+rx[now])>>1;
		if(L<=m) update(lc[now],L,R,v);
		if(R>m) update(rc[now],L,R,v);
		pu(now);
	}
	ll query(int now,int L,int R){
		if(L<=lx[now]&&rx[now]<=R){
			return sum[now];
		}
		pd(now);
		int m=(lx[now]+rx[now])>>1;
		ll ans=0;
		if(L<=m) ans+=query(lc[now],L,R);
		if(R>m) ans+=query(rc[now],L,R);
		return ans;
	}
}st;
int n,q,l,r,v;
char str[11];
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		st.init();st.build(1,n);
		for(int i = 1; i <= q; i++){
			scanf("%s",str);
			if(str[0]=='C'){
				scanf("%d%d%d",&l,&r,&v);
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