#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
int CLOCK,size[MAXN],st[MAXN],ed[MAXN],pre[MAXN];
int cntVal[MAXN],cntNum[MAXN],tmp,n;
bool vis[MAXN];
ll sum[MAXN],ans[MAXN],c[MAXN];
void init(){
    memset(head,-1,sizeof head);
    memset(cntVal,0,sizeof cntVal);
    memset(cntNum,0,sizeof cntNum);
    memset(sum,0,sizeof sum);
    memset(vis,0,sizeof vis);
    tmp=0;tot=0;CLOCK=0;
}
void add(int u,int v){
    to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
    swap(u,v);
    to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
}
void prepare(int u,int p){
    size[u]=1;
    st[u]=++CLOCK;pre[CLOCK]=u;
    erep(i,u){
        int v=to[i];
        if(v==p)continue;
        prepare(v,u);
        size[u]+=size[v];
    }
    ed[u]=CLOCK;
}
void dfs(int u,int p,bool keep){
    int mx=0,son=-1;
    erep(i,u){
        int v=to[i];
        if(v==p)continue;
        if(size[v]>mx){
            mx=size[v];
            son=v;
        }
    }
    erep(i,u){
        int v=to[i];
        if(v==p)continue;
        if(v==son) continue;
        dfs(v,u,0);
    }
    if(~son) dfs(son,u,1);
    erep(i,u){
        int v=to[i];
        if(v==p)continue;
        if(v==son)continue;
        rep(j,st[v],ed[v]){
            int o=pre[j];
            sum[cntVal[c[o]]]-=c[o];
            cntNum[cntVal[c[o]]]--;
            //if(tmp==cntVal[c[o]]&&cntNum[cntVal[c[o]]]==0) tmp--;
            cntVal[c[o]]++;
            cntNum[cntVal[c[o]]]++;
            sum[cntVal[c[o]]]+=c[o];
            if(tmp<cntVal[c[o]]) tmp=cntVal[c[o]];
        }
    }
    sum[cntVal[c[u]]]-=c[u];
    cntNum[cntVal[c[u]]]--;
    //if(tmp==cntVal[c[u]]&&cntNum[c[u]]==0) tmp--;
    cntVal[c[u]]++;
    cntNum[cntVal[c[u]]]++;
    sum[cntVal[c[u]]]+=c[u];
    if(tmp<cntVal[c[u]]) tmp=cntVal[c[u]];
    
    ans[u]=sum[tmp];

    if(!keep){ //撤销操作
        rep(i,st[u],ed[u]){
            int v=pre[i];
            sum[cntVal[c[v]]]-=c[v];
            cntNum[cntVal[c[v]]]--;
            //if(tmp==cntVal[c[v]]&&cntNum[c[v]]==0) tmp--;//似乎有问题
            cntVal[c[v]]--;
            cntNum[cntVal[c[v]]]++;
            sum[cntVal[c[v]]]+=c[v];
            if(cntNum[tmp]==0) tmp--;//重要
        }
    }
}
int main(){
    while(cin>>n){
        init();
        rep(i,1,n) c[i]=read();
        rep(i,1,n) if(!vis[c[i]]){
            sum[0]+=c[i];
            cntNum[0]++;
            vis[c[i]]=1;
        }
        rep(i,1,n-1){
            int u=read();
            int v=read();
            add(u,v);
        }
        prepare(1,-1);
        dfs(1,-1,0);
        rep(i,1,n){
            if(i==n) println(ans[i]);
            else printbk(ans[i]);
        }
    }
    return 0;
}
