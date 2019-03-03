#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 1e5+ 1e3,INF = 0x3f3f3f3f;
//struct edge{
//	int to,cost;
//}; 
//vector<edge> G[maxn];

struct node1{
	int to,w;
	int next;
}edge[maxn<<1]; int head[maxn],tot;
void adde(int u,int v,int w){//单向 
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int vis[maxn],cnt[maxn],pre[maxn];
long long d[maxn];
int n,m,from,to,cost,lll,mmax,last,w;
int Scan()     //输入外挂
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
bool spfa(int s){
	deque<int> q;
	memset(d,INF,sizeof d);
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	memset(pre,0,sizeof pre);
	d[s]=0; q.push_front(s);
	vis[s]=1;
	double sum = 0;
	while(!q.empty()){
		mmax = 0;
		int u = q.front(); q.pop_front();sum-=(double)d[u];
		//if(mmax<d[u]) mmax = d[u],last = u;
		for(int i = head[u]; i !=-1; i = edge[i].next){
			int v = edge[i].to;
			//edge e = G[u][i];
			if(d[v]>d[u]+edge[i].w){
				pre[v] = u;
				d[v] = d[u]+edge[i].w;
				if(mmax<d[v]) mmax = d[v],last = v;
				cnt[v]++;
				if(!vis[v]){
					if(!q.empty()&&sum/q.size()<d[v]||q.front()>d[v])
						q.push_back(v);
					else
						q.push_front(v);
					sum+=(double)d[v];
					vis[v]=1;
				}
			}
			if(cnt[v]>=n) return 1;
		}
		vis[u] = 0;
	}
	return 0;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(head,-1,sizeof head);tot=0;
		for(int i = 0; i < m; i++){
			//scanf("%d%d%d",&from,&to,&cost);
			from=Scan();to=Scan();cost=Scan(); 
			adde(from,to,cost);adde(to,from,cost);
		}
		bool flag = spfa(1);
		if(flag) printf("-1\n");
		else if(n==1) printf("1\n");
		else{
			stack<int> s; 
//			for(int i = 1; i <= n; i++) cout<<pre[i]<<endl;
			for(int i = n; i!=1; i=pre[i]){
				if(i==0){
					flag=1;
					break;
				}
				s.push(i);
			}
			if(s.size()==0) flag=1;
			if(flag) printf("-1\n");
			else{
				if(s.size()>0) printf("1 ");
				else printf("1\n");
				while(!s.empty()){
					if(s.size()!=1){
						printf("%d ",s.top());s.pop();
					}
					else{
						printf("%d\n",s.top());s.pop();
					}
				}
			}
		}
	}
	return 0;
}