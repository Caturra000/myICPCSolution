#include<stdio.h>
#include<string.h>
#define maxn 400011
#define ll long long
int a[100011],l,r,n,q,i;ll v;
char str[10];

	int lc[maxn],rc[maxn],lx[maxn],rx[maxn];
	ll lazy[maxn],sum[maxn];
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

int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		for(i = 1; i <= n; i++) scanf("%d",&a[i]);
		init();build(1,n);
		for(i = 1; i <= q; i++){
			scanf("%s",str);
			if(str[0]=='C'){
				scanf("%d%d%lld",&l,&r,&v);
				update(root,l,r,v);
			} 
			else{
				scanf("%d%d",&l,&r);
				printf("%lld\n",query(root,l,r));
			}
		}
	}
	return 0;
} 