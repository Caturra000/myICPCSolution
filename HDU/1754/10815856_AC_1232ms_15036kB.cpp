#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 200017;
const int maxn = N<<2;
const int INF = 0x3f3f3f3f;
int n,m,a[N],l,r,k,v;
struct ST{
	int lc[maxn],rc[maxn],lx[maxn],rx[maxn],mx[maxn],mn[maxn],lazy[maxn];
	int root,tot;
	void init(){
		root=tot=0;
		memset(lx,-1,sizeof lx);
		memset(rx,-1,sizeof rx);
//		memset(rc,-1,sizeof rc);
//		memset(lc,-1,sizeof lc);
	}
	void pu(int now){
		mx[now]=max(mx[lc[now]],mx[rc[now]]);
		mn[now]=min(mn[lc[now]],mn[rc[now]]);
	}
	void pd(int now){
		if(lazy[now]){
			;;;;;;;
		}
	}
	int build(int l,int r){
		int now=tot++,m=(l+r)>>1;
		lx[now]=l;rx[now]=r;
		if(r-l<1){
			mn[now]=mx[now]=a[l];
			return now;//NOTE 
		}
		lc[now]=build(l,m);
		rc[now]=build(m+1,r);
		pu(now);
		return now;
	}
	void update(int now,int k,int v){
		if(lx[now]==-1||rx[now]==-1) return;
		int m=(lx[now]+rx[now])>>1;
		if(lx[now]==rx[now]){
			mn[now]=v;
			mx[now]=v;
			return;
		}
		if(k<=m) update(lc[now],k,v);//左边包含m 
		else update(rc[now],k,v);
		pu(now);
	}
	int query(int now,int L,int R){
		if(lx[now]>R||rx[now]<L) return -INF;//完全越界 
		if(lx[now]>=L&&rx[now]<=R) return mx[now];//完全内部
		return max(query(lc[now],L,R),query(rc[now],L,R)); 
	}
}st;
char str[5];
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		st.init();st.build(1,n);
		for(int i = 0; i < m; i++){
			scanf("%s",str);
			if(str[0]=='Q'){
				scanf("%d%d",&l,&r);
				printf("%d\n",st.query(0,l,r));
			}
			else{
				scanf("%d%d",&k,&v);
				st.update(0,k,v);
			}
		}
	}
	return 0;
} 