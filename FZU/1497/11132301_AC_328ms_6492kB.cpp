#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring> 
#define lc o<<1
#define rc o<<1|1
using namespace std;
const int maxn = 1e5+11;
struct ST{
	int ls[maxn<<2],rs[maxn<<2],ms[maxn<<2];//最长连续1-有位子 
	int lazy[maxn<<2];
	void init(){
		memset(lazy,-1,sizeof lazy);
	}
	void pu(int o,int l,int r){
		ls[o]=ls[lc];
		rs[o]=rs[rc];
		int m=l+r>>1;
		if(ls[o]==m-l+1) ls[o]+=ls[rc];
		if(rs[o]==r-m) rs[o]+=rs[lc];
		ms[o]=max(ms[lc],ms[rc]);
		ms[o]=max(ms[o],rs[lc]+ls[rc]);
	}
	void build(int o,int l,int r){
		if(l==r){
			ls[o]=rs[o]=ms[o]=1;
			return;
		}
		int m=l+r>>1;
		build(lc,l,m);
		build(rc,m+1,r);
		pu(o,l,r);
	}
	void pd(int o,int l,int r){
		if(lazy[o]==0){
			ls[lc]=rs[lc]=ms[lc]=0;
			ls[rc]=rs[rc]=ms[rc]=0;
			lazy[lc]=lazy[rc]=0;
			lazy[o]=-1;
		}
		else if(lazy[o]==1){
			int m=l+r>>1;
			ls[lc]=rs[lc]=ms[lc]=m-l+1;
			ls[rc]=rs[rc]=ms[rc]=r-m;
			lazy[lc]=lazy[rc]=1;
			lazy[o]=-1;
		}
	}
	void update(int o,int l,int r,int L,int R,int v){
		if(L<=l&&r<=R){
			ls[o]=rs[o]=ms[o]=v?(r-l+1):0;
			lazy[o]=v;
			return;
		}
		pd(o,l,r);
		int m=l+r>>1;
		if(L<=m)update(lc,l,m,L,R,v);
		if(R>m)update(rc,m+1,r,L,R,v);
		pu(o,l,r);
	}
	int query(int o,int l,int r,int len){//pos
		if(l==r) return l;//
		pd(o,l,r);
		int m=l+r>>1;
		if(ms[lc]>=len) return query(lc,l,m,len);//注意优先度 左-中间-右 
		else if(rs[lc]+ls[rc]>=len) return m-rs[lc]+1;
		else return query(rc,m+1,r,len);
	}
}st;
int n,m,pos,len,op;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		st.init();st.build(1,1,n);
		for(int i = 0; i < m; i++){
			scanf("%d",&op);
			if(op==1){
				scanf("%d",&len);
				if(st.ms[1]<len) printf("0\n");
				else{
					pos=st.query(1,1,n,len);
					printf("%d\n",pos);
					st.update(1,1,n,pos,pos+len-1,0);
				}
			}
			else{
				scanf("%d%d",&pos,&len);
				st.update(1,1,n,pos,pos+len-1,1);
			}
		}
	}
	return 0;
}