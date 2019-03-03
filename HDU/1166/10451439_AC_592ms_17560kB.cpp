#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1e6;
int st[maxn<<2],a[maxn],n;
void pushup(int rt){
	st[rt]=st[rt<<1]+st[rt<<1|1];
}
void build(int l,int r,int rt){
	if(l==r){
		st[rt]=a[l];
		return;
	}
	int m = (l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt); 
}
void update(int k,int v,int l,int r,int rt){
	if(l==r){
		st[rt]+=v;
		return;
	}
	int m = (l+r)>>1;
	if(k<=m) update(k,v,l,m,rt<<1);
	else update(k,v,m+1,r,rt<<1|1);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(L<=l&&R>=r) return st[rt];
	int m = (l+r)>>1;
	int ans = 0;
	if(L<=m) ans+=query(L,R,l,m,rt<<1);
	if(R>m) ans+=query(L,R,m+1,r,rt<<1|1);
	return ans;
}
void update(int k,int v){
	update(k,v,1,n,1);
}
int query(int L,int R){
	return query(L,R,1,n,1);
}
int main(){
//	ios::sync_with_stdio(false);
	int k,v,s,e,flag;
	int T,kase=0;scanf("%d",&T);
	while(T--){
		++kase;flag=0;
		cin>>n;memset(st,0,sizeof st);
		for(int i = 1; i <= n; i++) cin>>a[i];
		build(1,n,1);
		char str[100];
		
		while(scanf("%s",str)!=EOF){
			if(str[0]=='E') break;
			else if(str[0]=='A'){
				scanf("%d%d",&k,&v); 
				update(k,v);
			}
			else if(str[0]=='S'){
				scanf("%d%d",&k,&v); 
				update(k,-v);
			}
			else if(str[0]=='Q'){
				scanf("%d%d",&s,&e); 
				if(flag==0){
					flag=1;
					printf("Case %d:\n",kase);
				}
				printf("%d\n",query(s,e));
			}
		}
	}
	return 0;
}