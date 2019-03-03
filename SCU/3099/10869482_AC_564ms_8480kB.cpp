#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+11;
int a[maxn],l,r,n,q;ll v;
char str[10];
struct ST{
	int lc[maxn<<2],rc[maxn<<2],lx[maxn<<2],rx[maxn<<2];
	ll lazy[maxn<<2],sum[maxn<<2];
	ll root,tot;
	inline void init(){
		root=tot=0;
		memset(lazy,0,sizeof lazy);
	}
	inline ll node(){
		lc[tot]=rc[tot]=lx[tot]=rx[tot]=sum[tot]=lazy[tot]=0;
		return tot++;
	}
	inline void pu(int now){
		sum[now]=sum[lc[now]]+sum[rc[now]];
	}
	inline ll len(int now){
		return rx[now]-lx[now]+1;
	}
	inline void pd(int now){
		if(lazy[now]){
//			sum[now]+=(rx[now]-lx[now]+1)*lazy[now];
			lazy[lc[now]]+=lazy[now];
			lazy[rc[now]]+=lazy[now];
			sum[lc[now]]+=lazy[now]*len(lc[now]);
			sum[rc[now]]+=lazy[now]*len(rc[now]);
			lazy[now]=0;
		} 
	}
	inline ll build(int l,int r){
		int now=node();
		lx[now]=l;rx[now]=r;
		if(l==r){
			sum[now]=a[l];
			return now; 
		}
		int m=(l+r)>>1;
		lc[now]=build(l,m);//1 l
		rc[now]=build(m+1,r);
		pu(now);
		return now;
	}
	inline void update(int now,int L,int R,ll v){
//		if(lx[now]==rx[now]){
		if(L<=lx[now]&&rx[now]<=R){
			sum[now]+=len(now)*v; //向上显示正确 
			lazy[now]+=v;///////////
//			pd(now);//WA if added 
			return;
		}
		int m=(lx[now]+rx[now])>>1;
		pd(now);//////////////
		if(L<=m) update(lc[now],L,R,v);
//		else update(rc[now],k,v);
		if(R>m) update(rc[now],L,R,v);
		pu(now);
	}
	inline ll query(int now,int L,int R){
		if(L<=lx[now]&&rx[now]<=R){
			return sum[now];
		}
		//wawawa
		pd(now);
		//wawawa
		int m=(lx[now]+rx[now])>>1;
		ll ans=0;
		if(L<=m) ans+=query(lc[now],L,R);
		if(r>m) ans+=query(rc[now],L,R);
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