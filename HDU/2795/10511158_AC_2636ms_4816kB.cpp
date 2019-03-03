#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 200010;
int st[maxn<<2];
int h,w,n,t;
void pushup(int rt){
    st[rt]=max(st[rt<<1],st[rt<<1|1]);
}
void build(int l,int r,int rt,int w){
	st[rt]=w;
    if(l==r){ 
        return;
    }
    int m = (l+r)>>1;
    build(l,m,rt<<1,w);
    build(m+1,r,rt<<1|1,w);
}
int query(int l,int r,int rt,int w){
	if(l==r){//bs
		st[rt]-=w;
		return l;
	}
	int ans, m=(l+r)>>1;
	if(st[rt<<1]>=w) ans = query(l,m,rt<<1,w);
	else ans = query(m+1,r,rt<<1|1,w);
	pushup(rt);
	return ans;
}
int main(){
    while(scanf("%d%d%d",&h,&w,&n)!=EOF){
    	memset(st,0,sizeof st);
    	int low = min(n,h);
    	build(1,low,1,w);
    	for(int i = 0; i < n; i++){
    		scanf("%d",&t);
    		if(st[1]<t) printf("-1\n");
    		else printf("%d\n",query(1,low,1,t));
		}
	}
	return 0;
}