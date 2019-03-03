#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
int a[maxn];
struct ST{
	#define lc o<<1
	#define rc o<<1|1
	ll val[maxn<<2],lazy[maxn<<2];
	void pu(int o){
		val[o]=max(val[lc],val[rc]);
	}
	void pd(int o){
		if(~lazy[o]){
			lazy[lc]=max(lazy[lc],lazy[o]);
			lazy[rc]=max(lazy[rc],lazy[o]);
			val[lc]=max(val[lc],lazy[o]);
			val[rc]=max(val[rc],lazy[o]);
			lazy[o]=-1;
		}
	}
	void build(int o,int l,int r){
		lazy[o]=-1;
		if(l==r){
			val[o]=a[l];
			return;
		}
		int m = l+r>>1;
		build(lc,l,m);
		build(rc,m+1,r);
		pu(o);
	}
	void update(int o,int l,int r,int L,int R,ll v){
		if(L<=l&&r<=R){
			lazy[o]=max(lazy[o],v);
			val[o]=max(val[o],v);
			return;
		}
		pd(o);
		int m = l+r>>1;
		if(L<=m)update(lc,l,m,L,R,v);
		if(R>m)update(rc,m+1,r,L,R,v);
		pu(o);
	}
	ll query(int o,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return val[o];
		}
		pd(o);
		int m = l+r>>1;
		ll ans=-1;
		if(L<=m) ans=max(ans,query(lc,l,m,L,R));
		if(R>m) ans=max(ans,query(rc,m+1,r,L,R));
		return ans;
	} 
}st;
int n,m,wi,hi;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
		}
		st.build(1,1,n);
		scanf("%d",&m);
		for(int i = 1; i <= m; i++){
			scanf("%d%d",&wi,&hi);
			ll t=st.query(1,1,n,1,wi);
			st.update(1,1,n,1,wi,1ll*t+hi);
			printf("%lld\n",t);
		}
	}
	return 0;
} 