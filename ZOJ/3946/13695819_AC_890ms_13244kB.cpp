#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int from[MAXN<<1],to[MAXN<<1],nxt[MAXN<<1],cost[MAXN<<1],tim[MAXN<<1];
int head[MAXN],tot;
int n,m;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v,int d,int c){
    to[tot]=v;
    from[tot]=u;
    cost[tot]=c;
    tim[tot]=d;
    nxt[tot]=head[u];
    head[u]=tot++;

    swap(u,v);

    to[tot]=v;
    from[tot]=u;
    cost[tot]=c;
    tim[tot]=d;
    nxt[tot]=head[u];
    head[u]=tot++;
}
bool vis[MAXN];
ll best[MAXN];
ll dis[MAXN];
void spfa(int s){
    memset(vis,0,sizeof vis);
    memset(dis,INF,sizeof dis);
    memset(best,-1,sizeof best);
    queue<int> que;que.push(s);
    dis[s]=0;vis[s]=1;
    while(!que.empty()){
        int u=que.front();que.pop();vis[u]=0;
        for(int i=head[u]; ~i; i=nxt[i]){
            int v=to[i],d=tim[i],c=cost[i];
            if(dis[v]>dis[u]+d){
                dis[v]=dis[u]+d;
                best[v]=i;
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }else if(dis[v]==dis[u]+d){
                if(cost[i]<cost[best[v]]) best[v]=i;
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
        
    }
    vector<int> vec;
    for(int i=0;i<n;i++){
        int j=best[i]; if(j==-1) continue;
        vec.push_back(j);
        // if(j==-1)continue;
        // cout<<"best"<<" "<<from[j]<<" "<<to[j]<<" "<<tim[j]<<" "<<cost[j]<<endl;
    }
    int last=-1;
    sort(vec.begin(),vec.end());
    unique(vec.begin(),vec.end());
    ll sum=0;
    for(int i=0;i<n;i++) sum+=dis[i];
    cout<<sum<<" ";
    sum=0;
    for(int i=0;i<n;i++){
        if(best[i]!=-1) sum+=cost[best[i]];
    }
    cout<<sum<<endl;
}
int main(){
    int T; cin>>T;
    while(T--){
        cin>>n>>m;
        init();
        for(int i=0;i<m;i++){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            add(a,b,c,d);
        }
        spfa(0);
    }
    return 0;
}