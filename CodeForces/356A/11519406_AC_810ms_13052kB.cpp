#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+11;
struct ST{
	#define lc o<<1
	#define rc o<<1|1
	int val[maxn<<2],lazy[maxn<<2];
	void init(){
		memset(lazy,0,sizeof lazy);
		memset(val,0,sizeof val);
	}
	void pu(int o){
		if(val[lc]) val[o]=val[lc];
		else val[o]=val[rc];
	}
	void pd(int o){
		if(lazy[o]){
			val[lc]=val[rc]=lazy[lc]=lazy[rc]=lazy[o];
			lazy[o]=0;
		}
	}
	void update(int o,int l,int r,int L,int R,int v){
		if(L<=l&&r<=R){
			val[o]=lazy[o]=v;
			return;
		}
		pd(o);
		int m=l+r>>1;
		if(L<=m)update(lc,l,m,L,R,v);
		if(R>m)update(rc,m+1,r,L,R,v);
		pu(o);
	}
	int query(int o,int l,int r,int k){
		if(l==r)return val[o];
		pd(o);
		int m=l+r>>1;
		if(k<=m)return query(lc,l,m,k);
		return query(rc,m+1,r,k);
	}
}st;
int li[maxn],ri[maxn],xi[maxn],n,m;
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>m){
		st.init();
		for(int i = 0; i < m; i++){
			cin>>li[i]>>ri[i]>>xi[i];
		}
		for(int i = m-1; i >= 0; i--){
			if(li[i]==xi[i]){
				st.update(1,1,n,li[i]+1,ri[i],xi[i]);
			}
			else if(ri[i]==xi[i]){
				st.update(1,1,n,li[i],ri[i]-1,xi[i]);
			}
			else{
				st.update(1,1,n,li[i],xi[i]-1,xi[i]);
				st.update(1,1,n,xi[i]+1,ri[i],xi[i]);
			}
		}
		for(int i = 1; i <= n; i++){
			if(i==n) cout<<st.query(1,1,n,i)<<endl;
			else cout<<st.query(1,1,n,i)<<" ";
		}
	}
	return 0;
}