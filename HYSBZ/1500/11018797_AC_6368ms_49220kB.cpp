#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1111;
const int oo = 0x3f3f3f3f;
// #define lc son[o][0]
// #define rc son[o][1]
// #define lcy son[y][0]
struct Splay{
    int root,tot;
    int a[maxn],st[maxn],top;
    int son[maxn][2],pre[maxn],val[maxn],sz[maxn];
    bool flip[maxn];
    int same[maxn],sum[maxn],maxl[maxn],maxr[maxn],maxm[maxn];
    void pu(int o){
        int lc,rc;
        lc=son[o][0];
        rc=son[o][1];
        sz[o]=sz[lc]+sz[rc]+1;
        sum[o]=sum[lc]+sum[rc]+val[o];
        maxl[o]=max(maxl[lc],sum[lc]+val[o]+max(maxl[rc],0));
        maxr[o]=max(maxr[rc],sum[rc]+val[o]+max(maxr[lc],0));
        maxm[o]=max(maxm[lc],maxm[rc]);
        maxm[o]=max(maxm[o],max(maxr[lc],0)+val[o]+max(maxl[rc],0));
    }
    void pd(int o){
        int lc=son[o][0];
        int rc=son[o][1];
        if(flip[o]){
            flip[o]=0;
            swap(son[o][0],son[o][1]);
            if(lc){
                flip[lc]^=1;
                swap(maxl[lc],maxr[lc]);
            }
            if(rc){
                flip[rc]^=1;
                swap(maxl[rc],maxr[rc]);
            }
        }
        if(same[o]!=-oo){
            if(lc){
                same[lc]=val[lc]=same[o];
                sum[lc]=sz[lc]*same[o];
                maxl[lc]=maxr[lc]=maxm[lc]=max(same[o],sum[lc]);
            }
            if(rc){
                same[rc]=val[rc]=same[o];
                sum[rc]=sz[rc]*same[o];
                maxl[rc]=maxr[rc]=maxm[rc]=max(same[o],sum[rc]);
            }
            same[o]=-oo;
        }
    }
//#define PushDown pd
//#define next son
//#define MaxL maxl
//#define MaxR maxr
//#define MaxM maxm
//#define num sz
//#define key val
//    inline void PushDown(int x) {
//        int L, R;
//        L = next[x][0];
//        R = next[x][1];
//        if (flip[x]) {
//            flip[x] = false;
//            swap(next[x][0], next[x][1]);
//            if (L) {
//                flip[L] ^= true;
//                swap(MaxL[L], MaxR[L]);
//            }
//            if (R) {
//                flip[R] ^= true;
//                swap(MaxL[R], MaxR[R]);
//            }
//        }
//        if (same[x] != -oo) {
//            if (L) {
//                same[L] = key[L] = same[x];
//                sum[L] = num[L] * same[x];
//                MaxL[L] = MaxR[L] = MaxM[L] = max(same[x], sum[L]);
//            }
//            if (R) {
//                same[R] = key[R] = same[x];
//                sum[R] = num[R] * same[x];
//                MaxL[R] = MaxR[R] = MaxM[R] = max(same[x], sum[R]);
//            }
//            same[x] = -oo;
//        }
//    }
    void node(int &o,int fa,int v){
        if(~top) o=st[top--];
        else o=++tot;
        flip[o]=0;
        son[o][0]=son[o][1]=0;
        pre[o]=fa;
        val[o]=sum[o]=maxl[o]=maxr[o]=maxm[o]=v;
        sz[o]=1;
        same[o]=-oo;
    }
    void build(int &o,int l,int r,int fa){
        if(l<=r){
            int m=l+r>>1;
            node(o,fa,a[m]);
            build(son[o][0],l,m-1,o);
            build(son[o][1],m+1,r,o);
            pu(o);
        }
    }
    void init(int n){
        top=-1;
        root=tot=0;
        son[0][0]=son[0][1]=pre[0]=val[0]=sz[0]=sum[0]=0;
        flip[0]=0;
        same[0]=maxl[0]=maxr[0]=maxm[0]=-oo;
        node(root,0,-oo);//root=1
        node(son[root][1],root,-oo);
        build(son[son[root][1]][0],1,n,son[root][1]);
        pu(son[root][1]);
        pu(root);
    }
    void rotate(int o,int wh){
        int fa,ffa;
        fa=pre[o];ffa=pre[fa];
        pd(fa);
        son[fa][!wh]=son[o][wh];
        pre[son[o][wh]]=fa;
        son[ffa][son[ffa][1]==fa]=o;
        pre[o]=ffa;
        son[o][wh]=fa;
        pre[fa]=o;
        pu(fa);
    }
    void splay(int o,int to){
        if(o!=to){
            pd(o);
            while(pre[o]!=to){
                if(son[pre[o]][0]==o) rotate(o,1);
                else rotate(o,0);
            }
            pu(o);
            if(!to) root=o;
        }
    }
    int select(int k){
        int o;
        pd(root);
        for(o=root;sz[son[o][0]]+1!=k;){
            if(sz[son[o][0]]+1>k) o=son[o][0];
            else{
                k-=sz[son[o][0]]+1;
                o=son[o][1];
            }
            pd(o);
        }
        return o;
    }
    int getsum(int x,int y){
        x=select(x-1);
        y=select(y+1);
        splay(x,0);
        splay(y,x);
        return sum[son[y][0]];
    }
    void recycle(int o){
        if(o){
            st[++top]=o;
            recycle(son[o][0]);
            recycle(son[o][1]);
        }
    }
    void kill(int x,int y){
        x=select(x-1);
        y=select(y+1);
        splay(x,0);
        splay(y,x);
        recycle(son[y][0]);
        son[y][0]=0;
        pu(y);
        pu(x);
    }
    void makeflip(int x,int y){
        x=select(x-1);
        y=select(y+1);
        splay(x,0);
        splay(y,x);
        y=son[y][0];
        flip[y]^=1;
        swap(maxl[y],maxr[y]);
    }
    void makesame(int x,int y,int v){
        int t;
        x=select(x-1);
        y=select(y+1);
        splay(x,0);
        splay(y,x);
        t=son[y][0];
        same[t]=val[t]=v;
        sum[t]=v*sz[t];
        maxl[t]=maxr[t]=maxm[t]=max(v,sum[t]);
        pu(y);
        pu(x);
    }
    int getmin(int o){
        pd(o);
        while(son[o][0]){
            o=son[o][0];
            pd(o);
        }
        return o;
    }
    void insert(int x,int cnt){
        int y;
        x=select(x);
        splay(x,0);
        y=getmin(son[x][1]);
        splay(y,x);
        build(son[y][0],1,cnt,y);
        pu(y); 
        pu(x);
    }
    int getmaxm(int x,int y){
        x=select(x-1);
        y=select(y+1);
        splay(x,0);
        splay(y,x);
        return maxm[son[y][0]];
    }
}splay;
int n,m,pos,cnt,val;
char str[100];
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d",&splay.a[i]);
        }
        splay.init(n);
        for(int i = 1; i <= m; i++){
            scanf("%s",str);
            if(str[0]=='G'){
                scanf("%d%d",&pos,&cnt);
                printf("%d\n",splay.getsum(pos+1,pos+cnt));
            }
            else if(str[2]=='X'){
                printf("%d\n",splay.getmaxm(2,splay.sz[splay.root]-1));
            }
            else if(str[0]=='I'){
                scanf("%d%d",&pos,&cnt);
                for(int j = 1; j <= cnt; j++){
                    scanf("%d",&splay.a[j]);
                }
                splay.insert(pos+1,cnt);
            }
            else if(str[0]=='D'){
                scanf("%d%d",&pos,&cnt);
                splay.kill(pos+1,pos+cnt);
            }
            else if(str[2]=='K'){
                scanf("%d%d%d",&pos,&cnt,&val);
                splay.makesame(pos+1,pos+cnt,val);
            }
            else if(str[0]=='R'){
                scanf("%d%d",&pos,&cnt);
                splay.makeflip(pos+1,pos+cnt);
            }
        }
    }
    return 0;
}
