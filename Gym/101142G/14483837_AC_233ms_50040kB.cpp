#include<bits/stdc++.h>
#include<unordered_map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int dep[MAXN],p[MAXN][21],leaf[MAXN];
bool mark[MAXN];
bool vis[MAXN];
int dfn[MAXN],dfned[MAXN],pre[MAXN],CLOCK;
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
int rec[MAXN];
unordered_map<int,int> s[MAXN];
set<int> s2[MAXN],s3[MAXN];
void init(){
    memset(head,-1,sizeof head);
    memset(mark,0,sizeof mark);
    memset(vis,0,sizeof vis);
    memset(rec,0,sizeof rec);
    rep(i,0,MAXN-1) s[i].clear(),s2[i].clear(),s3[i].clear(); 
    tot=CLOCK=0;
}
void add(int u,int v){
    to[tot]=v,nxt[tot]=head[u];
    head[u]=tot++;
}
int dfs(int u,int fa,int d){
    dep[u]=d;dfn[u]=++CLOCK;pre[CLOCK]=u;
    int num=0;
    bool flag=0;
    rep(i,0,20){
        if(mark[u]) p[u][i]=u;//!!!!!
        else if(i) p[u][i]=p[p[u][i-1]][i-1];
        else p[u][i]=fa;
    }
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        //num+=
        dfs(v,u,d+1);
        flag=1;
    }
//    if(flag==0&&!mark[u+n]){
//        add(u+2*n,u);add(u,u+2*n);
//        dfs(u+n,u,d+1);
//        mark[u+2*n]=1;
//    }
    dfned[u]=CLOCK;
    return leaf[u]=(flag?0:1);
}
int rmq(int u,int k){
    rep(i,0,20){
        if(k>>i&1) u=p[u][i];
    }
    return u;
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    rep(i,0,20){
        if((dep[u]-dep[v])>>i&1){
            u=p[u][i];
        }
    }
    if(u==v)return u;
    rrep(i,20,0){
        if(p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
const int INF = 1<<30;
int ori[MAXN<<2];
void oribuild(int o,int l,int r){
    if(l==r){
        ori[o]=(leaf[pre[l]]==1)?1:0;//!!!
        return;
    }
    int mid=l+r>>1;
    oribuild(o<<1,l,mid);
    oribuild(o<<1|1,mid+1,r);
    ori[o]=ori[o<<1]+ori[o<<1|1];
}
int query(int o,int l,int r,int L,int R){
    if(L<=l&&r<=R) return ori[o];
    int mid=l+r>>1;
    int ans=0;
    if(L<=mid) ans+=query(o<<1,l,mid,L,R);
    if(R>mid) ans+=query(o<<1|1,mid+1,r,L,R);
    return ans;
}
int main(){
    freopen("gangsters.in","r",stdin);
    freopen("gangsters.out","w",stdout);
    int n,m;
    while(cin>>n>>m){
        init();
        rep(i,2,n){
            int u=read();
            if(u==1) mark[i]=1;
            add(u,i);
            add(i,u);
        }
        dfs(1,-1,1); oribuild(1,1,CLOCK);
        //st[0].build(1,1,CLOCK,0);
        char op[6];
        int ans1=0,ans2=0;
        while(m--){
            scanf("%s",op);
            int u=read();
            if(op[0]=='+'){
                int top=rmq(u,1e5+11);
                //s[top][u]++;
                ans1-=(int)s3[top].size();
                ans2-=rec[top];
                s2[top].insert(dfn[u]);
                s3[top].clear();
                int l=*s2[top].begin();  
                int r=*s2[top].rbegin();
                int tmp=lca(pre[l],pre[r]);
                s3[top].insert(tmp);
                ans1++;
                rec[top]=query(1,1,CLOCK,dfn[tmp],dfned[tmp])-(int)s2[top].size(); 
                ans2+=rec[top];
                printf("%d %d\n",ans1,ans2);
            }else{
                int top=rmq(u,1e5+11);
                ans1-=(int)s3[top].size();
                ans2-=rec[top];
                s2[top].erase(dfn[u]);
                s3[top].clear();
                if((int)s2[top].size()==1){
                    int t=*s2[top].begin();
                    s3[top].insert(pre[t]);
                    ans1++;
                    rec[top]=0;
                    printf("%d %d\n",ans1,ans2);
                    continue;
                }else if((int)s2[top].size()==0){
                    printf("%d %d\n",ans1,ans2);
                    rec[top]=0;
                    continue;
                }
                int l=*s2[top].begin();
                int r=*s2[top].rbegin();
                int tmp=lca(pre[l],pre[r]);
                s3[top].insert(tmp);
                ans1++;
                rec[top]=query(1,1,CLOCK,dfn[tmp],dfned[tmp])-(int)s2[top].size();
                ans2+=rec[top];
                printf("%d %d\n",ans1,ans2);
            }
        }
    }
    return 0;
}