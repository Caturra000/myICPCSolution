#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
struct Grpah{
    int head[maxn],V;
    int to[maxn<<1],nxt[maxn<<1],tot;
    int dfn[maxn],low[maxn],dtime;
    int sccs[maxn],sccn;
    int st[maxn],sz; bool in[maxn];
    void init(){
        sccn=dtime=sz=tot=0;
		memset(head,-1,sizeof head);
        memset(in,0,sizeof in);
        memset(dfn,0,sizeof dfn);memset(low,0,sizeof low);
    }
    void add(int u,int v){
        to[tot]=v;
        nxt[tot]=head[u];
        head[u]=tot++;
    }
    void dfs(int u){
       int v;
       dfn[u]=low[u]=++dtime;
       in[st[sz++]=u]=1;
       for(int i = head[u]; ~i; i=nxt[i]){
           v=to[i];
           if(!dfn[v]){
               dfs(v);
               low[u]=min(low[u],low[v]);
           }
           else if(in[v]){
               low[u]=min(low[u],dfn[v]);
           }
       }
       if(dfn[u]==low[u]){
           sccn++;
           do{
               v=st[--sz];in[v]=0;
               sccs[v]=sccn;
           }while(u!=v);
//           cout<<"sccn!!! "<<sccn<<endl;
       }
   }
    void scc(){
        for(int i = 1; i <= V; i++)
            if(!dfn[i]) dfs(i);
    }
}G;
int out[maxn];
int main(){
    int from,to,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0) break; 
		G.init();G.V=n;
        for(int i = 1; i <= m; i++){
            scanf("%d%d",&from,&to);
            G.add(from,to);
        }
        G.scc();
        if(G.sccn==1) printf("Yes\n");
		else printf("No\n"); 
    }
    return 0;
}