#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 3e5+11;
const double EPS = 1e-7;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7; 
unsigned int SEED = 17;
const ll INF = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline int Rand(){
    SEED=SEED*1103515245+12345;
    return SEED/65536;
}
struct Treap{
    int son[MAXN][2],root,tot;
    int fix[MAXN],size[MAXN];
    ll val[MAXN],mx[MAXN];
    int stk[MAXN];
    #define lc son[o][0]
    #define rc son[o][1]
    void init(){
        root=0;
        son[0][0]=son[0][1]=0;
        val[0]=fix[0]=size[0]=0;
        mx[0]=0;
        tot=1;
    }
    int node(int v){
        son[tot][0]=son[tot][1]=0;
        val[tot]=v; fix[tot]=Rand();
        size[tot]=1;
        mx[tot]=v;
        return tot++;
    }
    void pu(int o){
        size[o]=size[lc]+size[rc]+1;
        mx[o]=val[o];
        mx[o]=max(mx[o],mx[lc]);
        mx[o]=max(mx[o],mx[rc]);
    }
    void split(int o,int k,int &a,int &b){
        if(!o){
            a=b=0;
            return;
        }else if(k<=size[lc]){
            b=o;
            split(lc,k,a,lc);
            pu(o);
        }else{
            a=o;
            split(rc,k-size[lc]-1,rc,b);
            pu(o);
        }
    }
    int merge(int a,int b){
        if(!a) return b;
        if(!b) return a;
        if(fix[a]<fix[b]){
            son[a][1]=merge(son[a][1],b);
            pu(a);
            return a;
        }else{
            son[b][0]=merge(a,son[b][0]);
            pu(b);
            return b;
        }
    }
    void insert(int pos,int v){
        int a,b,t=node(v);
        split(root,pos,a,b);
        root=merge(merge(a,t),b);
    }
    int get(int pos){
        int a,b,x,y;
        split(root,pos-1,a,b);
        split(b,1,x,y);
        int t=x;
        root=merge(a,merge(x,y));
        return t;
    }
    ll get(int pos,int len){
        int a,b,x,y;
        split(root,pos-1,a,b);
        split(b,len,x,y);
        int ans=mx[x];
        root=merge(a,merge(x,y));
        return ans;
    }
}tp;
int main(){
    int m,mod;
    while(cin>>m>>mod){
        tp.init();
        ll t=0;
        char str[333];
        ll tmp;
        ll curlen=0;
        rep(i,1,m){
            scanf("%s%lld",str+1,&tmp);
            if(str[1]=='Q'){
                if(tmp<=curlen){
                    t=tp.get(curlen-tmp+1,tmp);
                }else{
                    t=tp.get(1,curlen);
                }
                println(t);
            }else if(str[1]=='A'){
                tmp+=t;tmp%=mod;
                tp.insert(curlen,tmp);
                curlen++;
            }
        }
    }
    return 0;
}