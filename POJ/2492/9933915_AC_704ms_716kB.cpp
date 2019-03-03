#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
const int maxn = 5000;
int p[maxn],rank[maxn];
using namespace std;
int n,m,flag,kase,a,b;

void init(){
	for(int i = 0; i < maxn; i++)
		p[i] = i;
	memset(rank,0,sizeof rank);
	flag = 0;
}
int find(int x){
	return p[x]==x?x:find(p[x]);
}
bool same(int x,int y){
	return find(x)==find(y);
}
bool link(int x,int y){
	x = find(x); y = find(y);
	if(x==y) return false;
	if(rank[x]<rank[y])
		p[x] = y;
	else{
		p[y] = x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
	return true;
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i = 0; i < m; i++){
			scanf("%d%d",&a,&b);
			if(same(a,b)){
				flag = 1;
			}
			else{
				link(a,b+n);
				link(a+n,b);
			}
		}
		printf("Scenario #%d:\n",++kase);
		if(flag) printf("Suspicious bugs found!\n\n");
		else	printf("No suspicious bugs found!\n\n");
	}
	return 0;
} 