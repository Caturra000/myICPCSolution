#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector> 
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge{
	int from,to,cost;
};
vector<edge> es;
int d[1011];
int T,n,m,w,from,to,cost;
bool bellman(){
	memset(d,0,sizeof d);
	for(int i = 0; i < n; i++){
		bool flag = 0;
		for(int j = 0; j < es.size(); j++){
			edge e = es[j];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to] = d[e.from]+e.cost;
				flag = 1;
				if(i==n-1) return 1;
			}
		}
		if(!flag) break;
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		es.clear(); 
		scanf("%d%d%d",&n,&m,&w);
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&from,&to,&cost);
			es.push_back((edge){from,to,cost});
			es.push_back((edge){to,from,cost});
		}
		for(int i = 0; i < w; i++){
			scanf("%d%d%d",&from,&to,&cost);
			es.push_back((edge){from,to,-cost});
		}
		bool flag = bellman();
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}