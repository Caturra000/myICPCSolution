#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
struct ST{
	int color[maxn<<2],lazy[maxn<<2];
	void init(){
		memset(color,0,sizeof color);
		memset(lazy,0,sizeof lazy);
	}
	void pu(int o){
		color[o] = color[o<<1] | color[o<<1|1];
	}
	void build(int o,int l,int r){
		if(l==r){
			color[o]=1;
			return;
		}
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		pu(o);
	}
	void pd(int o){
		if(lazy[o]){
			lazy[o<<1]=lazy[o<<1|1]=lazy[o];
			color[o<<1]=color[o<<1|1]=lazy[o];
			lazy[o]=0;
		}
	}
	void update(int o,int l,int r,int L,int R,int v){
		if(L<=l&&r<=R){
			color[o]=1<<(v-1);
			lazy[o]=1<<(v-1);
			return;
		}
		pd(o);
		int m=l+r>>1;
		if(L<=m) update(o<<1,l,m,L,R,v);
		if(R>m) update(o<<1|1,m+1,r,L,R,v);
		pu(o);
	}
	int query(int o,int l,int r,int L,int R){
		if(L<=l&&r<=R){
			return color[o];
		}
		pd(o);
		int m=l+r>>1;
		int ans=0;
		if(L<=m) ans|=query(o<<1,l,m,L,R);
		if(R>m) ans|=query(o<<1|1,m+1,r,L,R);
		return ans;
	}
}st; 
int count(int x){
	int cnt=0;
	for(int i = 0; i <= 30; i++){
		if((1<<i)&x) cnt++;
	}
	return cnt;
}
int main(){
    int n,m,q,c,l,r;char str[10];
    while(scanf("%d%d%d",&n,&m,&q)!=EOF){
        st.init();st.build(1,1,n);
        for(int i = 1; i <= q; i++){
            scanf("%s",str);
            if(str[0]=='C'){
                scanf("%d%d%d",&l,&r,&c);
                if(l>r) swap(l,r);
                st.update(1,1,n,l,r,c);
            }
            else{
                scanf("%d%d",&l,&r);
                if(l>r) swap(l,r);
                printf("%d\n",count(st.query(1,1,n,l,r)));
            }
        }
    }
    return 0;
}