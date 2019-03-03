#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 2e5+11;
int ans[maxn]; 
struct ST{
	int val[maxn<<2];
	void pu(int o){
		val[o]=val[o<<1]+val[o<<1|1];
	}
	void build(int o,int l,int r){
		if(l==r){
			val[o]=1;
			return; 
		}
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		pu(o);
	}
	void update(int o,int l,int r,int k,int v,int key){
		if(l==r){
			val[o]+=v;//占位v=-1
			ans[l]=key; 
			return; 
		}
		int m=l+r>>1;
		if(val[o<<1]>=k) update(o<<1,l,m,k,v,key);//还够位子 
//		else update(o<<1|1,m+1,r,k,v,key);
		else update(o<<1|1,m+1,r,k-val[o<<1],v,key);
		pu(o);
	}
}st;
int n,pos[maxn],val[maxn];
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i++){
			scanf("%d%d",&pos[i],&val[i]);
			pos[i]++;
		}
		st.build(1,1,n);
		for(int i = n-1; i >= 0; i--){
			st.update(1,1,n,pos[i],-1,val[i]); 
		}	
		for(int i = 1; i <= n; i++){
			if(i==n)printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}