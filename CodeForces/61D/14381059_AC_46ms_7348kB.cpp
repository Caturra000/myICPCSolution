#include<bits/stdc++.h>
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
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
ll cost[MAXN<<1];
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,ll w){
    to[tot]=v,cost[tot]=w,nxt[tot]=head[u];
    head[u]=tot++;
}
ll dfs(int u,int fa,ll res){
    ll tmp=res;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];ll w=cost[i];
        if(v==fa) continue;
        tmp=max(tmp,dfs(v,u,w+res));        
    }
    return tmp;
}
int main(){
    int n;
    while(cin>>n){
        init();
        ll sum=0;
        rep(i,1,n-1){
            int u=read();
            int v=read();
            ll w=read(); 
            add(u,v,w);
            add(v,u,w);
            sum+=w<<1; 
        }
        sum-=dfs(1,-1,0);
        println(sum);
    }
    return 0;
}