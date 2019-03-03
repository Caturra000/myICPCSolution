
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int inf=1<<30;
struct node
{
    int to,cap;
    unsigned  rev;
};
int dep[N],n,m;
vector<node>v[N];
void add_Node(int from, int to, int cap)  //重边情况不影响
{
    v[from].push_back((node) { to, cap, v[to].size() });
    v[to].push_back((node) { from, 0, v[from].size() - 1 });
}
int bfs(int s,int t)
{
    queue<int>q;
    while(!q.empty())q.pop();
    memset(dep,-1,sizeof(dep));
    dep[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++)
            if(v[u][i].cap>0&&dep[v[u][i].to]==-1)
            {
                dep[v[u][i].to]=dep[u]+1;
                q.push(v[u][i].to);
            }
    }
    return dep[t]!=-1;
}
int dfs(int u,int t,int micap)
{
    if(u==t)return micap;
    int tmp;
    for(int i=0;i<v[u].size();i++)
    {
        node &now=v[u][i];
        if(now.cap>0&&dep[u]+1==dep[now.to]&&(tmp=dfs(now.to,t,min(now.cap,micap))))
        {
            now.cap-=tmp;
            v[now.to][now.rev].cap+=tmp;
            return tmp;
        }
    }
    return 0;
}
int dinic(int s,int t)
{
    int ans=0,tmp;
    while(bfs(s,t))
        while(1)
        {
            tmp=dfs(s,t,inf);
            if(tmp==0)break;
            ans+=tmp;
        }
    return ans;
}
int main()
{
    while(cin>>n>>m)
    {
        memset(v,0,sizeof(v));
        int u,v,w;
        while(n--)
        {
            cin>>u>>v>>w;
            add_Node(u,v,w);
        }
        cout<<dinic(1,m)<<"\n";
    }
}//test