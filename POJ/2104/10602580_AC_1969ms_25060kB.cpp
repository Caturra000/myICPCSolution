#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+11;
int L[maxn<<5],R[maxn<<5],st[maxn<<5];
int tot;
int a[maxn],T[maxn],hash[maxn];
int build(int l,int r){
	int rt=(++tot);
	st[rt]=0;
	if(l<r){
		int m = (l+r)>>1;
		L[rt]=build(l,m);
		R[rt]=build(m+1,r);
	}
	return rt;
}
int update(int pre,int l,int r,int x){
	int rt=(++tot);
	L[rt]=L[pre];R[rt]=R[pre];st[rt]=st[pre]+1;
	if(l<r){
		int m = (l+r)>>1;
		if(x<=m) L[rt]=update(L[pre],l,m,x);
		else R[rt]=update(R[pre],m+1,r,x);
	}
	return rt;
}
int query(int u,int v,int l,int r,int k){
	if(l>=r) return l;
	int m = (l+r)>>1;
	int num=st[L[v]]-st[L[u]];
	if(num>=k) return query(L[u],L[v],l,m,k);
	else return query(R[u],R[v],m+1,r,k-num);
}
int main(){
	tot=0;
	int n,m; scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		hash[i]=a[i];
	}
	sort(hash+1,hash+1+n);
	int d=unique(hash+1,hash+1+n)-hash-1;
	T[0]=build(1,d);
	for(int i = 1; i <= n; i++){
		int x = lower_bound(hash+1,hash+1+n,a[i])-hash;
		T[i]=update(T[i-1],1,d,x);
	}
	for(int i = 1; i <= m; i++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		int x = query(T[l-1],T[r],1,d,k);
		printf("%d\n",hash[x]);
	}
	return 0;
}