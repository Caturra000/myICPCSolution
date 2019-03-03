#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector> 
using namespace std;
const int maxn = 1e6+1e5,INF=0x3f3f3f3f;
int p[maxn],n,m,from,to,cost;
struct edge{
	int from,to,cost;
};
vector<edge> E;
bool cmp(edge a,edge b){
	return a.cost>b.cost;
}
int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
}
void link(int a,int b){
	a=find(a);b=find(b);
	if(a!=b) p[a]=b;
}
int kruskal(){
	//memset(p,-1,sizeof p);
	for(int i = 0; i <= n; i++) p[i]=i;
	int ans = INF;
	sort(E.begin(),E.end(),cmp);
	for(int i = 0; i < E.size(); i++){
		int a = E[i].from, b = E[i].to;
		a = find(a); b = find(b);
		if(a==b) continue;
		link(a,b);
		ans = min(ans,E[i].cost);
		int pn = find(n),p1 = find(1);
		if(pn==p1) break;
	}
	return ans;
}
int main(){
	int T,kase; 
	while(scanf("%d",&T)!=EOF){
		kase = 0;
		while(T--){
			E.clear();
			scanf("%d%d",&n,&m);
			for(int i = 0; i < m; i++){
				scanf("%d%d%d",&from,&to,&cost);
				//G[from].push_back(i);
				E.push_back((edge){from,to,cost});
			}
			printf("Scenario #%d:\n%d\n\n",++kase,kruskal());
		}
	}
		
	return 0;
}