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
const int MAXN = 2e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
unsigned int SEED = 19260817;
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
    int val[MAXN],fix[MAXN],size[MAXN];
    int dep[MAXN];
    #define lc son[o][0]
    #define rc son[o][1]
    void init(){
        root=0;
        son[0][0]=son[0][1]=0;
        val[0]=fix[0]=size[0]=0;
        dep[0]=0;
        tot=1;
    }
    int node(int v,int d){
        son[tot][0]=son[tot][1]=0;
        val[tot]=v; fix[tot]=Rand();
        size[tot]=1;dep[tot]=d;
        return tot++;
    }
    void pu(int o){
        size[o]=size[lc]+size[rc]+1;
    }
    void split(int o,int pivot,int &a,int &b){
        if(!o){
            a=b=0;
            return;
        }else if(val[o]>pivot){
            b=o;
            split(lc,pivot,a,lc);
            pu(o);
        }else{
            a=o;
            split(rc,pivot,rc,b);
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
    void insert(int v,int d){
        int a,b,t=node(v,d);
        split(root,v,a,b);
        root=merge(merge(a,t),b);
    }

    int kth(int k){
        int o=root;
        while(1){
            if(k<=size[lc]){
                o=lc;
            }else if(k==size[lc]+1){
                return o;
            }else{
                k-=size[lc]+1;
                o=rc;
            }
        } 
    }
    int kth(int o,int k){
    	if(!o)return o;//
        while(1){
            if(k<=size[lc]){
                o=lc;
            }else if(k==size[lc]+1){
                return o;
            }else{
                k-=size[lc]+1;
                o=rc;
            }
        } 
    }
    int insert(int v){
        int a,b;
        split(root,v-1,a,b);
        int x=kth(a,size[a]);
        int y=kth(b,1);
        bool flag=0;
        if(dep[x]<dep[y]) flag=1;
        root=merge(a,b);
        int d=(flag?dep[y]:dep[x])+1;
        insert(v,d);
        return flag?val[y]:val[x];
    }
}tp;
int n,a[MAXN],ans[MAXN];
int main(){
    while(cin>>n){
        tp.init();
        rep(i,1,n) a[i]=read();tp.insert(a[1],1);
        rep(i,2,n) ans[i]=tp.insert(a[i]);
        rep(i,2,n) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}