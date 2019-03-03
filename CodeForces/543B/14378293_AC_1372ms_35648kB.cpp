#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 3e3+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],cost[MAXN<<1],head[MAXN],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,int w){
    to[tot]=v,cost[tot]=w,nxt[tot]=head[u];
    head[u]=tot++;
}
typedef pair<int,int> P;
int dis[MAXN][MAXN];
void dijkstra(int st){
    dis[st][st]=0;
    priority_queue<P,vector<P>,greater<P> > que; 
    que.push(P(st,0));
    while(que.empty()^1){
        P p=que.top(); que.pop();
        int u=p.first;
        if(dis[st][u]<p.second) continue;
        for(int i=head[u];~i;i=nxt[i]){
            int v=to[i],w=cost[i];
            if(dis[st][v]>dis[st][u]+w){
                dis[st][v]=dis[st][u]+w;
                que.push(P(v,dis[st][v]));
            }
        }
    }
}
int main(){
    int n,m;
    while(cin>>n>>m){
        init();
        rep(i,1,m){
            int u=read();
            int v=read();
            add(u,v,1);
            add(v,u,1);
        }
        memset(dis,0x3f,sizeof dis);
        rep(i,1,n) dijkstra(i);
        int s1,t1,l1,s2,t2,l2;
        cin>>s1>>t1>>l1>>s2>>t2>>l2;
        if(dis[s1][t1]>l1||dis[s2][t2]>l2){
            println(-1);
            continue;
        }
        int cnt=dis[s1][t1]+dis[s2][t2];
        rep(i,1,n) rep(j,1,n){
            // int tmp=dis[i][j]; //directed
            bool flag1,flag2;
            int tmp1,tmp2;
            tmp1=dis[s1][i]+dis[i][j]+dis[j][t1];
            tmp2=dis[s2][i]+dis[i][j]+dis[j][t2];
            flag1=bool(tmp1<=l1);
            flag2=bool(tmp2<=l2);
            if(flag1&&flag2) cnt=min(cnt,tmp1+tmp2-dis[i][j]);
            tmp1=dis[s1][j]+dis[j][i]+dis[i][t1];
            tmp2=dis[s2][j]+dis[j][i]+dis[i][t2];
            flag1=bool(tmp1<=l1);
            flag2=bool(tmp2<=l2);
            if(flag1&&flag2) cnt=min(cnt,tmp1+tmp2-dis[i][j]);
            tmp1=dis[s1][i]+dis[i][j]+dis[j][t1];
            tmp2=dis[s2][j]+dis[j][i]+dis[i][t2];
            flag1=bool(tmp1<=l1);
            flag2=bool(tmp2<=l2);
            if(flag1&&flag2) cnt=min(cnt,tmp1+tmp2-dis[i][j]);
            tmp1=dis[s1][j]+dis[j][i]+dis[i][t1];
            tmp2=dis[s2][i]+dis[i][j]+dis[j][t2];
            flag1=bool(tmp1<=l1);
            flag2=bool(tmp2<=l2);
            if(flag1&&flag2) cnt=min(cnt,tmp1+tmp2-dis[i][j]);
        }
        println(m-cnt);
    }
    return 0;
}