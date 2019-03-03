#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 5e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
int CLOCK,st[MAXN],ed[MAXN],n,m;
char str[MAXN];
vector<int> save[MAXN][27];
void init(){
    memset(head,-1,sizeof head);
    tot=CLOCK=0;
}
void add(int u,int v){
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
    swap(u,v);
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot++;
}
void dfs(int u,int p,int d){
    st[u]=++CLOCK;
    save[d][str[u]-'a'].push_back(st[u]);
    erep(i,u){
        int v=to[i];
        if(v==p)continue;
        dfs(v,u,d+1);
    }
    ed[u]=CLOCK;
}
int main(){
    while(cin>>n>>m){
        init();
        rep(i,2,n) add(i,read());
        scanf("%s",str+1);
        memset(save,0,sizeof save);
        dfs(1,-1,1);
        rep(i,1,m){
            int u=read();
            int d=read();
            bool flag=0,fflag=0;
            rep(j,0,25){
                vector<int>::iterator it1=lower_bound(save[d][j].begin(),save[d][j].end(),st[u]);
                vector<int>::iterator it2=upper_bound(save[d][j].begin(),save[d][j].end(),ed[u]);
                int cha=it2-it1;
                if((cha&1)&&!flag) flag=1;
                else if((cha&1)&&flag){
                    fflag=1;break;
                }
            }
            if(fflag) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}