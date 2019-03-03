#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
struct Grpah{
    int head[maxn],V;
    int to[maxn<<1],nxt[maxn<<1],tot;
    int dfn[maxn],low[maxn],dtime;
    int sccs[maxn],sccn;
    int st[maxn],sz,sn[maxn]; bool in[maxn];
    void init(){
        sccn=dtime=sz=tot=0;
		memset(head,-1,sizeof head);
        memset(in,0,sizeof in);
        memset(dfn,0,sizeof dfn);memset(low,0,sizeof low);
        memset(sn,0,sizeof sn);
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
               sn[sccn]++;
           }while(u!=v);
        //    cout<<"sccn!!! "<<sccn<<endl;
       }
   }
    void scc(){
        for(int i = 1; i <= V; i++)
            if(!dfn[i]) dfs(i);
    }
}G;
int main(){
    int n,m,a,b;
    while(scanf("%d%d",&n,&m)!=EOF){
    	G.init();G.V=n;
        for(int i = 1; i <= m; i++){
            scanf("%d%d",&a,&b);
            G.add(a,b);
        }
        G.scc();
        int od[maxn];memset(od,0,sizeof od);
        for(int i = 1; i <= n; i++){//from
            for(int j = G.head[i]; ~j; j=G.nxt[j]){//to
                if(G.sccs[i]!=G.sccs[G.to[j]]&&G.sccs[i]){//not scc of i Note0
                    od[G.sccs[i]]++;
                }
            }
        }
        int cnt=0,pos;//bool vis[maxn]; memset(vis,0,sizeof vis);
        for(int i = 1; i <= G.sccn; i++){
            if(!od[i]){
                cnt++;pos=i;
            }
        }
        if(cnt>1) {printf("0\n");continue;}
        else printf("%d\n",G.sn[pos]);
    }
    return 0;
}