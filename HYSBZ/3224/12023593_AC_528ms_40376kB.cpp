#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+11;
unsigned int SEED = 17;
inline int Rand(){
    SEED=SEED*1103515245+12345;
    return SEED/65536;
}
struct TP{
    int son[maxn][2],val[maxn],fix[maxn],size[maxn];
    int tot,root;
    #define lc son[o][0]
    #define rc son[o][1]
    void init(){
        root=0;
        tot=1;
        son[0][0]=son[0][1]=val[0]=fix[0]=size[0]=0;
    }
    void pu(int o){
        size[o]=1+size[lc]+size[rc];
    }
    int node(int v){
        son[tot][0]=son[tot][1]=0;
        size[tot]=1;
        val[tot]=v;
        fix[tot]=Rand();
        return tot++;
    }
    int merge(int a,int b){
        if(!a)return b;if(!b)return a;
        if(fix[a]<fix[b]){
            son[a][1]=merge(son[a][1],b);
            pu(a);
            return a;
        }
        else{
            son[b][0]=merge(a,son[b][0]);
            pu(b);
            return b;
        }
    }
    void split(int o,int k,int &a,int &b){
        if(!o) a=b=0;
        else{
            if(val[o]<=k){
                a=o;
                split(rc,k,rc,b);
            }
            else{
                b=o;
                split(lc,k,a,lc);
            }
            pu(o);
        }
    }
    int kth(int o,int k){
        while(1){
            if(k<=size[lc]) o=lc;
            else if(k==size[lc]+1) return o;
            else{k-=size[lc]+1;o=rc;}
        }
    }
    ////
    void insert(int o,int v){
        int a,b;
        split(root,v,a,b);// if 无根 ?
        root=merge(merge(a,node(v)),b);
    }
    void del(int o,int k){
        int a,b,c;
        split(root,k,a,c);
        split(a,k-1,a,b);
        b=merge(son[b][0],son[b][1]);
        root=merge(merge(a,b),c);
    }
    int krank(int k){
        int a,b;
        split(root,k-1,a,b);
        int ans=size[a]+1;
        root=merge(a,b);
        return ans;
        
    }
    int rankk(int k){
        return val[kth(root,k)];
    }
    int pre(int k){
        int a,b;
        split(root,k-1,a,b);
        int ans=val[kth(a,size[a])];//
        root=merge(a,b);
        return ans;
    }
    int succ(int k){
        int a,b;
        split(root,k,a,b);
        int ans=val[kth(b,1)];
        root=merge(a,b);
        return ans;
    }
}tp;
int main(){
    int n,op,x,a,b,c;
    while(scanf("%d",&n)^-1){
        tp.init();
        for(int i = 1; i <= n;i++){
            scanf("%d%d",&op,&x);
            if(op==1){
                tp.insert(tp.root,x);
            }
            if(op==2){
                tp.del(tp.root,x);
            }
            if(op==3){
                printf("%d\n",tp.krank(x));
            }
            if(op==4){
                printf("%d\n",tp.rankk(x));
            }
            if(op==5){
                printf("%d\n",tp.pre(x));
            }
            if(op==6){
                printf("%d\n",tp.succ(x));
            }
        }
    }
    return 0;
}