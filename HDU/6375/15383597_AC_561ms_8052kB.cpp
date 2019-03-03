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
#define println(a) printf("%d\n",(int)a)
using namespace std;
const int MAXN = 1e6+11;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
unsigned int SEED = 19260817;
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
int rt[MAXN];
struct Treap{
    int son[MAXN][2],root,tot;
    int val[MAXN],fix[MAXN],size[MAXN];
    bool flip[MAXN];
    #define lc son[o][0]
    #define rc son[o][1]
    void init(){
        root=0;
        son[0][0]=son[0][1]=0;
        val[0]=fix[0]=size[0]=0;
        flip[0]=0;
        tot=1;
    }
    int node(int v){
        son[tot][0]=son[tot][1]=0;
        val[tot]=v; fix[tot]=Rand();
        size[tot]=1;flip[tot]=0;
        return tot++;
    }
    void pu(int o){
        size[o]=size[lc]+size[rc]+1;
    }
    void rev(int o){
        swap(lc,rc);
        flip[o]^=1;
    }
    void pd(int o){
        if(flip[o]){
            if(lc) rev(lc);
            if(rc) rev(rc);
            flip[o]=0;
        }
    }
    void split(int o,int k,int &a,int &b){
        if(!o){
            a=b=0;
            return;
        }else if(k<=size[lc]){
            pd(o);
            b=o;
            split(lc,k,a,lc);
            pu(o);
        }else{
            pd(o);
            a=o;
            split(rc,k-size[lc]-1,rc,b);
            pu(o);
        }
    }
    int merge(int a,int b){
        if(!a) return b;
        if(!b) return a;
        if(a) pd(a); if(b) pd(b);
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
    void insert(int rtid,int pos,int v){
        int a,b,t=node(v);
        split(rt[rtid],pos,a,b);
        rt[rtid]=merge(merge(a,t),b);
    }
    int get(int rtid,int pos){
        int a,b,x,y;
        split(rt[rtid],pos-1,a,b);
        split(b,1,x,y);
        int t=x;
        rt[rtid]=merge(a,merge(x,y));
        return t;
    }
    void rev_append(int rtid,int pos,int len){//[pos,pos+len-1]
        int a,b,x,y;
        split(rt[rtid],pos-1,a,b);
        split(b,len,x,y);
        rev(x);
        rt[rtid]=merge(merge(a,y),x);
    }
    void pinjie_rev(int rtid1,int rtid2){
        rev(rt[rtid2]);
        rt[rtid1]=merge(rt[rtid1],rt[rtid2]);
    }
    void pinjie(int rtid1,int rtid2){
        rt[rtid1]=merge(rt[rtid1],rt[rtid2]);
    }
    void del(int rtid,int pos){
        int a,b,x,y;
        split(rt[rtid],pos-1,a,b);
        split(b,1,x,y);
        println(val[x]);
        rt[rtid]=merge(a,y);
    }
}tp;
int main(){
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        memset(rt,0,sizeof rt);
        tp.init();
        while(q--){
            int op=read();
            if(op==1){
                ll x=read();
                ll y=read();
                ll z=read();
                if(rt[x]==0){
                    rt[x]=tp.node(z);
                    continue;
                }
                if(y==0){
                    tp.insert(x,0,z);
                }else{
                    int sz=tp.size[rt[x]];
                    tp.insert(x,sz,z);
                }
            }else if(op==2){
                int id=read();
                int f=read();
                if(rt[id]==0){
                    println(-1);
                    continue;
                }
                if(f==0){
                    tp.del(id,1);
                }else{
                    tp.del(id,tp.size[rt[id]]);
                }
            }else{
                int id1=read();
                int id2=read();//2jie1houmian
                int flag=read();//shun==0/fan==1
                if(flag==0){
                    tp.pinjie(id1,id2);
                    rt[id2]=0;
                }else{
                    tp.pinjie_rev(id1,id2);
                    rt[id2]=0;
                }
            }
        }
    }
    return 0;
}