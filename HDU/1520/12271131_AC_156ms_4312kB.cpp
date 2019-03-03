#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
using namespace std;
typedef long long ll;
const int maxn  = 2e5+11;
int dp[maxn][2];
int w[maxn];
bool flag[maxn];
int to[maxn<<1],nxt[maxn<<1],head[maxn],tot;
void init(){memset(head,-1,sizeof head);tot=0;}
void add(int u,int v){
    to[tot]=v;nxt[tot]=head[u];
    head[u]=tot++;
}
int DP(int u,int now){
    if(~dp[u][now]) return dp[u][now];
    int ans=now?w[u]:0;
    for(int i = head[u]; ~i; i = nxt[i]){
        int v=to[i];
        if(now==0) ans+=max(max(DP(v,now),DP(v,now^1)),0);
        else ans+=max(0,DP(v,now^1));
    }
    return dp[u][now]=ans;
}
int DP(int u){
    dp[u][0]=0;
    dp[u][1]=w[u];
    for(int i = head[u]; ~i; i = nxt[i]){
        int v=to[i];
        DP(v);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
    return max(dp[u][0],dp[u][1]);
}
int main(){
    int n,u,v,rt;
    while(scanf("%d",&n)!=EOF){
        init();memset(flag,0,sizeof flag);
        rep(i,1,n) scanf("%d",&w[i]);
        while(scanf("%d%d",&u,&v)!=EOF){
            if(u*v==0)break;
            add(v,u);flag[u]=1;
        }
        rep(i,1,n) if(!flag[i]){
            rt=i;
            break;
        }
        memset(dp,-1,sizeof dp);
        printf("%d\n",max(DP(rt,0),DP(rt,1)));
    }
    return 0;
}