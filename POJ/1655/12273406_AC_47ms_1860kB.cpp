#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
int to[maxn<<1],nxt[maxn<<1],head[maxn],tot;
int son[maxn];
bool vis[maxn];
int id,sz,n;
void init(){memset(head,-1,sizeof head);tot=0;}
void add(int u,int v){
    to[tot]=v;nxt[tot]=head[u];
    head[u]=tot++;
}
void dfs(int u){
    son[u]=0;vis[u]=1;
    int tmp=0;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(vis[v])continue;
        dfs(v);
        son[u]+=1+son[v];
        tmp=max(tmp,1+son[v]);
    }
    tmp=max(tmp,n-son[u]-1);//fanbian
    if( tmp<sz ||(tmp==sz&&u<id)) sz=tmp,id=u;
}
int main(){
    int T,u,v; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        memset(vis,0,sizeof vis);
        memset(son,0,sizeof son);
        id=sz=oo;
        rep(i,1,n-1){
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        dfs(1);
        printf("%d %d\n",id,sz);
    }
    return 0;
}