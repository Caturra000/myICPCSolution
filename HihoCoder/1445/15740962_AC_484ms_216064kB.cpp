#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 2e6+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct SAM{
    int tot;
    char str[MAXN];
    int maxlen[MAXN],minlen[MAXN],trans[MAXN][26],slink[MAXN];
    void init(){
        tot=1;
        maxlen[tot]=minlen[tot]=slink[tot]=0;
        rep(i,0,25) trans[tot][i]=0;
    }
    int node(int mx,int mn,int from,int _slink){
        ++tot;
        maxlen[tot]=mx;
        minlen[tot]=mn;
        slink[tot]=_slink;
        rep(i,0,25) trans[tot][i]=trans[from][i];
        return tot;
    }
    int add(char ch,int u){
        int c=ch-'a',v=u;
        int z=node(maxlen[u]+1,-1,0,0);
        while(v&&trans[v][c]==0){
            trans[v][c]=z;
            v=slink[v];
        }
        if(v==0){
            minlen[z]=1;
            slink[z]=1;
            return z;
        }
        int x=trans[v][c];
        if(maxlen[v]+1==maxlen[x]){
            minlen[z]=maxlen[x]+1;
            slink[z]=x;
            return z;
        }
        int y=node(maxlen[v]+1,-1,x,slink[x]);
        slink[z]=slink[x]=y;
        minlen[x]=minlen[z]=maxlen[y]+1;
        while(v&&trans[v][c]==x){
            trans[v][c]=y;
            v=slink[v];
        }
        minlen[y]=maxlen[slink[y]]+1;
        return z;
    }
    void build(){
        int t=tot;
        int len=strlen(str+1);
        rep(i,1,len) t=add(str[i],t);
    }
}sam;
char str[MAXN];
int main(){
    while(~scanf("%s",sam.str+1)){
        sam.init();
        sam.build();
        ll ans=0;
        rep(i,2,sam.tot) ans+=sam.maxlen[i]-sam.minlen[i]+1;
        println(ans);
    }
    return 0;
}