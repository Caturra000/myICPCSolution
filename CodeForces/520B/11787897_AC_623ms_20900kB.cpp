#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e6+11;
const int oo = 0x3f3f3f3f;
int to[maxn<<1],nxt[maxn<<1],cost[maxn<<1];
int head[maxn],tot;
void init(){
	memset(head,-1,sizeof head);
	tot=0;
}
void add(int u,int v,int w){
	to[tot]=v;cost[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot++;
}
bool inq[maxn];
int d[maxn];
int spfa(int s,int t){
	memset(inq,0,sizeof inq);
	memset(d,oo,sizeof d);
	queue<int> que;
	que.push(s);d[s]=0;inq[s]=1;
	while(!que.empty()){
		int u = que.front(); que.pop();
		inq[u]=0;
		for(int i = head[u]; ~i; i = nxt[i]){
			int v=to[i],w=cost[i];
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(!inq[v]){
					inq[v]=1;
					que.push(v);
				}
			}
		}
	}
	return d[t];
}
int n,m;
int main(){
	while(cin>>n>>m){
		if(m<=n)cout<<n-m<<endl;
		else{
			init();
			for(int i = 3*m; i > 0; i--){
				add(i,i-1,1);
			}
			for(int i = 1; i <= 3*m; i++){
				if(2*i>3*m) break;
				if(2*i<=3*m) add(i,2*i,1);
			}
			cout<<spfa(n,m)<<endl;
		}
	}
	return 0;
}