#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 200010;
int p[maxn],r[maxn];
int n,m,u,v,l,rc,cnt,k;
void init(){
	memset(r,0,sizeof r);
	memset(p,-1,sizeof p);
	cnt = 0;
}
int find(int x){
	if(p[x]==-1) return x;
	int t = find(p[x]);
	r[x]+=r[p[x]];
	return p[x]=t;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&u,&v,&k);
			if(u>v) swap(u,v);
			u-=1;
			int t1 = find(u), t2 = find(v);
			if(t1!=t2){
				p[t2]=t1;
				r[t2]=r[u]-r[v]+k;
			}
			else{
				if(r[v]-r[u]!=k) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}