#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e4+11;
struct node{
    int to,cost,nxt;
}edge[maxn<<1];int head[maxn],tot;
void add(int from,int to,int cost){
    edge[tot].to=to;
    edge[tot].cost=cost;
    edge[tot].nxt=head[from];
    head[from]=tot++;
}
int mmax[maxn],smax[maxn],maxid[maxn],smaxid[maxn];
void dfs1(int u,int p){//v到叶子的最大距离,p[v]=p;
    mmax[u]=0;smax[u]=0;
    for(int i = head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==p) continue;//
        dfs1(v,u);
        if(smax[u]<mmax[v]+edge[i].cost){//更新u 
            smax[u]=mmax[v]+edge[i].cost;
            smaxid[u]=v;
            if(smax[u]>mmax[u]){
                swap(smax[u],mmax[u]);
                swap(smaxid[u],maxid[u]);
            }
        }
    }
}
void dfs2(int u,int p){//p[v]=p
    for(int i = head[u]; i!=-1; i=edge[i].nxt){
        int v = edge[i].to;
        if(v==p) continue;//
        if(v==maxid[u]){
            if(edge[i].cost+smax[u]>smax[v]){//更新v 
                smax[v]=edge[i].cost+smax[u];
                smaxid[v]=u;
                if(smax[v]>mmax[v]){
                    swap(smax[v],mmax[v]);
                    swap(smaxid[v],maxid[v]);
                }
            }
        }
        else{
            if(edge[i].cost+mmax[u]>smax[v]){
                smax[v]=edge[i].cost+mmax[u];
                smaxid[v]=u;
                if(smax[v]>mmax[v]){
                    swap(smax[v],mmax[v]);
                    swap(maxid[v],smaxid[v]);
                }
            }
        }
        dfs2(v,u);
    }
}
int n,from,to,cost; 
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(head,-1,sizeof head);tot=0;
        for(int i = 2; i <= n; i++){
            scanf("%d%d",&to,&cost);
            add(i,to,cost);add(to,i,cost);
        }
        dfs1(1,-1);
//		for(int i = 1; i <= n; i++){
//			cout<<"id:"<<i<<" "<<mmax[i]<<" "<<maxid[i]<<" "<<smax[i]<<" "<<smaxid[i]<<endl;
//		}
//		cout<<"*************************\n";
		dfs2(1,-1);
//		for(int i = 1; i <= n; i++){
//			cout<<"id:"<<i<<" "<<mmax[i]<<" "<<maxid[i]<<" "<<smax[i]<<" "<<smaxid[i]<<endl;
//		}
        for(int i = 1; i <= n; i++){
            printf("%d\n",mmax[i]);
        }
    }
    return 0;
}