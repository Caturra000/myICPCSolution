#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
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
        fix[tot]=rand();
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
}tp;
int main(){
    int n,op,x,a,b,c;
    while(scanf("%d",&n)^-1){
        tp.init();
        for(int i = 1; i <= n;i++){
            scanf("%d%d",&op,&x);
            if(op==1){
                tp.split(tp.root,x,a,b);// if 无根 ?
                tp.root=tp.merge(tp.merge(a,tp.node(x)),b);
            }
            if(op==2){
                tp.split(tp.root,x,a,c);
                tp.split(a,x-1,a,b);
                b=tp.merge(tp.son[b][0],tp.son[b][1]);
                tp.root=tp.merge(tp.merge(a,b),c);
            }
            if(op==3){
                tp.split(tp.root,x-1,a,b);
                printf("%d\n",tp.size[a]+1);
                tp.root=tp.merge(a,b);
            }
            if(op==4){
                printf("%d\n",tp.val[tp.kth(tp.root,x)]);
            }
            if(op==5){
                tp.split(tp.root,x-1,a,b);
                printf("%d\n",tp.val[tp.kth(a,tp.size[a])]);
                tp.root=tp.merge(a,b);
            }
            if(op==6){
                tp.split(tp.root,x,a,b);
                printf("%d\n",tp.val[tp.kth(b,1)]);
                tp.root=tp.merge(a,b);
            }
        }
    }
    return 0;
}