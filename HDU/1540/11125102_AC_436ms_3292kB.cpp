#include<bits/stdc++.h>
#define lc o<<1
#define rc o<<1|1
using namespace std;
const int maxn = 2e5+11;
struct ST{
	int ls[maxn<<2],rs[maxn<<2],ms[maxn<<2];
	void pu(int o,int l,int r){
		ls[o]=ls[lc];rs[o]=rs[rc];
		int m = l+r>>1;
		if(ls[o]==m-l+1) ls[o]+=ls[rc];
		if(rs[o]==r-m) rs[o]+=rs[lc];
		ms[o]=max(ms[lc],ms[rc]);
		ms[o]=max(ms[o],rs[lc]+ls[rc]);
	}
	void build(int o,int l,int r){
		ls[o]=rs[o]=ms[o]=r-l+1;
		if(l!=r){
			int m = l+r>>1;
			build(lc,l,m);
			build(rc,m+1,r);
		}
	}
	void update(int o,int l,int r,int k,int v){
		if(l==r){
			ls[o]=rs[o]=ms[o]=v;
			return;
		}
		int m = l+r>>1;
		if(k<=m) update(lc,l,m,k,v);
		else update(rc,m+1,r,k,v);
		pu(o,l,r);
	}
	int query(int o,int l,int r,int k){
		if(l==r||ms[o]==0||ms[o]==r-l+1){//满也不往下走 
			return ms[o];
		}
		int m = l+r>>1;
		if(k<=m){
			if(k>=m-rs[lc]+1) return query(lc,l,m,k)+query(rc,m+1,r,m+1);
			else return query(lc,l,m,k);
		}
		else{
			if(k<=m+1+ls[rc]-1) return query(rc,m+1,r,k)+query(lc,l,m,m);
			else return query(rc,m+1,r,k);
		}
	}
}st; 
//bool D[maxn],B[maxn];
int n,m,k;
char str[100];
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		st.build(1,1,n);
		stack<int> stk; while(!stk.empty())stk.pop();
//		memset(D,0,sizeof D);memset(B,0,sizeof B);
		for(int i = 0; i < m; i++){
			scanf("%s",str);
			if(str[0]=='D'){
				scanf("%d",&k);
//				if(D[k])continue;
//				D[k]=1;B[k]=0;
				st.update(1,1,n,k,0);
				stk.push(k);
			}
			else if(str[0]=='R'){
				if(stk.empty())continue;
				k=stk.top();stk.pop();
//				if(B[k])continue;
//				B[k]=1;D[k]=0;
				st.update(1,1,n,k,1);
			}
			else{
				scanf("%d",&k);
				if(k>n||k<0)continue;
				printf("%d\n",st.query(1,1,n,k));
			}
		}
	}
	return 0;
}