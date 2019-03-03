#include<bits/stdc++.h>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ssb=cin.rdbuf();sb=cout.rdbuf();
#define println(x) print(x),print('\n');
using namespace std;
const int MAXN = 4e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const int BUFL = 1e6+11;
char Obuf[BUFL],Ibuf[BUFL];
char *optr=Obuf,*ist=0,*ied=0;
streambuf *sb,*ssb;
inline void print(char c){optr==Obuf+BUFL?(sb->sputn(Obuf,BUFL),optr=Obuf),*optr++=c:*optr++=c;}
inline void flush(){sb->sputn(Obuf,optr-Obuf);}
inline char pick(){return ist==ied?ied=Ibuf+ssb->sgetn(ist=Ibuf,BUFL),(ist==ied?-1:*ist++):*ist++;}
template<class T>
inline void print(T x){
    if(x==0) {print(char(48));return;}
    if(x<0){print(char('-'));x=-x;}
    static char buf[233];
    register int cnt;
    for(cnt=0;x;x/=10) buf[++cnt]=x%10|48;
    while(cnt) print(buf[cnt--]);
}
template<class T>
inline int read(T &t){
    ll x; register char c,f; f=1;
    while(!((c=pick())>='0'&&c<='9')&&(c^-1)&&(c^45));
    if(c==-1) return EOF;
    if(c==45) c=pick(),f=0;
    for(x=c-48;(c=pick())>='0'&&c<='9';(x=((x<<3)+(x<<1)))+=c-48);
    t=f?x:-x;return 1;
}
int to[MAXN<<1],nxt[MAXN<<1],head[MAXN],tot;
ll cost[MAXN<<1];
void init(int n){
    memset(head,-1,(n+2)*sizeof(int));
    tot=0;
}
void add(int u,int v,ll w=0){
    to[tot]=v;
    cost[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot++;
}
int n,k;
int size[MAXN],msize[MAXN][5];
inline int sub(int a,int b,int mod){
    return ((a%mod-b%mod)%mod+mod)%mod;
}
ll dfs(int u,int fa,int d){
    rep(i,0,4) msize[u][i]=0;
    size[u]=1; msize[u][d%k]=1;
    ll ans=0;
    for(int i=head[u];~i;i=nxt[i]){
        int v=to[i];
        if(v==fa) continue;
        ans+=dfs(v,u,d+1);
        ans+=(ll)size[v]*(n-size[v]);
        rep(i,0,k-1){
            rep(j,0,k-1){
                int r=sub(i+j,d<<1,k);
                int t=sub(k,r,k);
                ans+=(ll)t*msize[u][i]*msize[v][j];
            }
        }
        rep(i,0,k-1) msize[u][i]+=msize[v][i];
        size[u]+=size[v];
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("stdin.txt","r",stdin);
    #endif
    fastIO;
    while(~read(n)){
        read(k);
        init(n);
        rep(i,1,n-1){
            int u,v;
            read(u);
            read(v);
            add(u,v);
            add(v,u);
        }
        println(dfs(1,-1,0)/k);
    }
    flush();
    return 0;
}