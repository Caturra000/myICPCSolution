#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN<<1],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v){
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
}
int deg[1003],n,m; 
bool topo(int rt){
    stack<int> stk;
    deg[rt]--; stk.push(rt);
    int cnt=0;
    queue<int>que;
    rep(i,1,n) if(!deg[i]) que.push(i),cnt++;
    while(!que.empty()){
        int u=que.front(); que.pop();
        for(int i=head[u];~i;i=nxt[i]){
            int v=to[i];
            --deg[v]; stk.push(v);
            if(!deg[v]) que.push(v),cnt++; 
        }
    }
    while(!stk.empty()){
        ++deg[stk.top()];
        stk.pop();
    }
    return cnt==n;
}
int main(){
    while(cin>>n>>m){
        init();
        memset(deg,0,sizeof deg);
        rep(i,1,m){
            int u=read();
            int v=read();
            deg[v]++;
            add(u,v);
        }
        bool flag=0;
        rep(i,1,n) if(topo(i)){
            flag=1;
            printf("YES\n");
            break;
        }
        if(!flag) printf("NO\n");
    }
    return 0;
}
