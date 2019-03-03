#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+11;
typedef long long ll;
struct ST{
	ll mx[maxn<<2],sum[maxn<<2];
	ll tmp;
	#define lc o<<1
	#define rc o<<1|1
	void pu(int o){
		mx[o]=max(mx[lc],mx[rc]);
		sum[o]=sum[lc]+sum[rc];
	}
	void build(int o,int l,int r){
		if(l==r){
			scanf("%lld",&tmp);
			mx[o]=sum[o]=tmp;
			return;
		}
		int m=l+r>>1;
		build(lc,l,m);
		build(rc,m+1,r);
		pu(o);
	} 
	void update(int o,int l,int r,int k,ll v){
		if(l==r){
			sum[o]=v;
			mx[o]=v;
			return;
		}
		int m=l+r>>1;
		if(k<=m) update(lc,l,m,k,v);
		else update(rc,m+1,r,k,v);
		pu(o);
	}
	ll query(int o,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return sum[o];
		}
		int m=l+r>>1;
		ll ans=0;
		if(L<=m) ans+=query(lc,l,m,L,R);
		if(R>m) ans+=query(rc,m+1,r,L,R);
		return ans;
	}
	void mod(int o,int l,int r,int L,int R,ll v){
//		cout<<o<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
		if(mx[o]<v) return;//即使不在L,R也提前剪枝 
		if(l==r){
			sum[o]=mx[o]=(mx[o]%v);
			return;
		} 
		int m=l+r>>1;
		if(L<=m) mod(lc,l,m,L,R,v);
		if(R>m) mod(rc,m+1,r,L,R,v);
		pu(o);
	}
}st;
int op,n,m,l,r,v,k;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		st.build(1,1,n);
		for(int i = 1; i <= m; i++){
			scanf("%d",&op);
			if(op==1){
				scanf("%d%d",&l,&r);
				printf("%lld\n",st.query(1,1,n,l,r));
			}
			else if(op==2){
				scanf("%d%d%d",&l,&r,&v);
				st.mod(1,1,n,l,r,v); 
			}
			else{
				scanf("%d%d",&k,&v);
				st.update(1,1,n,k,v);
			}
		}
	}
	return 0;
}