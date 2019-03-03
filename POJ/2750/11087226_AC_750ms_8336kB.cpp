#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define lc o<<1
#define rc o<<1|1
using namespace std;
const int maxn = 1e5+11;
int a[maxn];
struct ST{
	int sum[maxn<<2],mx[maxn<<2],mn[maxn<<2];
	int maxl[maxn<<2],maxr[maxn<<2],minl[maxn<<2],minr[maxn<<2];
	void pu(int o){
		sum[o]=sum[lc]+sum[rc];

		maxl[o]=max(maxl[lc],sum[lc]+maxl[rc]);
		maxr[o]=max(maxr[rc],sum[rc]+maxr[lc]);
		mx[o]=max(mx[lc],mx[rc]);
		mx[o]=max(mx[o],maxr[lc]+maxl[rc]);

		minl[o]=min(minl[lc],sum[lc]+minl[rc]);
		minr[o]=min(minr[rc],sum[rc]+minr[lc]);
		mn[o]=min(mn[lc],mn[rc]);
		mn[o]=min(mn[o],minr[lc]+minl[rc]);

	}
	void build(int o,int l,int r){
		if(l==r){
			sum[o]=mx[o]=mn[o]=maxl[o]=maxr[o]=minl[o]=minr[o]=a[l];
			return;
		}
		int m = l+r>>1;
		build(lc,l,m);
		build(rc,m+1,r);
		pu(o);
	}
	void update(int o,int l,int r,int k,int v){
		if(l==r){
			sum[o]=mx[o]=mn[o]=maxl[o]=maxr[o]=minl[o]=minr[o]=v;
			return;
		}
		int m = l+r>>1;
		if(k<=m) update(lc,l,m,k,v);
		else update(rc,m+1,r,k,v);
		pu(o);
	}
}st; 
int n,m,k,v;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++)scanf("%d",&a[i]);
		st.build(1,1,n);
		scanf("%d",&m);
		for(int i = 1; i <= m; i++){
			scanf("%d%d",&k,&v);
			st.update(1,1,n,k,v);
			if(st.sum[1]==st.mx[1]){
				printf("%d\n",st.sum[1]-st.mn[1]);
			}
			else{
				printf("%d\n",max(st.sum[1]-st.mn[1],st.mx[1]));
			}
		}
	}
	return 0;
}