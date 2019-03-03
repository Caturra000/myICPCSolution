#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 2e5+10, INF = 0x3f3f3f3f;
typedef pair<int,int> P;
struct node{
	int mmin,mmax;
}st[maxn<<2];
int n,m,l,r;
void pushup(int rt){
	st[rt].mmax=max(st[rt<<1].mmax,st[rt<<1|1].mmax);
	st[rt].mmin=min(st[rt<<1].mmin,st[rt<<1|1].mmin);
}
void build(int l,int r,int rt){
	if(l==r){
//		st[rt].mmin=st[rt].mmax=a[l];
		scanf("%d",&st[rt].mmax);st[rt].mmin=st[rt].mmax;
		return;
	}
	int m = (l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt,int pos){
	if(L<=l&&R>=r&&pos==0){
		return st[rt].mmin;
	}
	if(L<=l&&R>=r&&pos==1){
		return st[rt].mmax;
	}
	int m = (l+r)>>1;
	int q = pos?-INF:INF;
	if(L<=m){
		if(pos) q=max(q,query(L,R,l,m,rt<<1,pos));
		else q=min(q,query(L,R,l,m,rt<<1,pos));
	}
	if(R>m){
		if(pos) q=max(q,query(L,R,m+1,r,rt<<1|1,pos));
		else q=min(q,query(L,R,m+1,r,rt<<1|1,pos));
	}
	return q;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(st,0,sizeof st);
//		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		build(1,n,1);
		for(int i = 1; i <= m; i++){
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r,1,n,1,1)-query(l,r,1,n,1,0));
		}
	}
	return 0;
}