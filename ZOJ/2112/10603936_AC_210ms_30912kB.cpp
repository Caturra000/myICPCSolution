//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<stdio.h>
#include <string>
#include<string.h>
#include<utility>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define eps 1e-8
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d%d",&x,&y)
#define ll long long int
#define mod 1000000007
#define maxn 60005
#define maxm 2500005
int m,n,nn,tot;
int a[maxn],f[maxn],T[maxn],S[maxn];
int sum[maxm],l[maxm],r[maxm];
int use[maxn];
int h(int x){//该值在离散化后线段树的位置
    return lower_bound(f+1,f+1+nn,x)-f;
}
void update(int pr,int lx,int rx,int v,int k){//插入，即新建第i个线段树
    l[++tot]=l[pr];r[tot]=r[pr];sum[tot]=sum[pr]+k;
    if(lx==rx) return;
    int mid=(lx+rx)>>1;
    if(v<=mid) {
            l[tot]=tot+1;
            update(l[pr],lx,mid,v,k);
    }
    else {
            r[tot]=tot+1;
            update(r[pr],mid+1,rx,v,k);
    }
}
void build(int rt,int lx,int rx){//初始化空树
    sum[rt]=0;
    if(lx==rx) return;
    l[rt]=++tot;
    int mid=(lx+rx)>>1;
    build(tot,lx,mid);
    r[rt]=++tot;
    build(tot,mid+1,rx);
}
int lowbit(int x){return x&(-x);}
int Sum(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=sum[l[use[i]]];
    return res;
}
void add(int x,int v,int k)
 {
     int tt;
    for(int i=x;i<=n;i+=lowbit(i)){
        tt=S[i];
        S[i]=tot+1;
        update(tt,1,nn,v,k);
    }
 }
int query(int L,int R,int k){
    for(int i=L-1;i;i-=lowbit(i)) use[i]=S[i];//use记录要操作的线段树下标
    for(int i=R;i;i-=lowbit(i)) use[i]=S[i];
    int lx=1,rx=nn;
    int lt=T[L-1],rt=T[R];
    while(lx<rx){
        int mid=(lx+rx)>>1;
        int tmp=Sum(R)-Sum(L-1)+sum[l[rt]]-sum[l[lt]];
        if(k<=tmp){
            rx=mid;
            for(int i=L-1;i;i-=lowbit(i)) use[i]=l[use[i]];
            for(int i=R;i;i-=lowbit(i)) use[i]=l[use[i]];
            lt=l[lt];rt=l[rt];
        }
        else{
            lx=mid+1;k-=tmp;
            for(int i=L-1;i;i-=lowbit(i)) use[i]=r[use[i]];
            for(int i=R;i;i-=lowbit(i)) use[i]=r[use[i]];
            lt=r[lt];rt=r[rt];
        }
    }
    return f[lx];
}
char op[5];
int q[10005][4],t;
int main()
{
    rd(t);
    while(t--){
    rd2(n,m);
    for(int i=1;i<=n;i++) {
            rd(a[i]);f[i]=a[i];
    }
    nn=n;
    for(int i=1;i<=m;i++){
        scanf("%s",op);
        if(op[0]=='Q') {
            scanf("%d%d%d",&q[i][1],&q[i][2],&q[i][3]);
            q[i][0]=1;
        }
        else{
            scanf("%d%d",&q[i][1],&q[i][2]);
            q[i][0]=0;
            f[++nn]=q[i][2];
        }
    }
    sort(f+1,f+1+nn);
    nn=unique(f+1,f+1+nn)-f-1;//离散化线段树，并去重
    tot=0;
    T[0]=0;
    build(0,1,nn);
    for(int i=1;i<=n;i++){
        T[i]=tot+1;          //T[i]记录第i个线段树的根
        update(T[i-1],1,nn,h(a[i]),1);
    }
    for(int i=1;i<=n;i++) S[i]=T[0];
   // int L,R,k,x;
    for(int i=1;i<=m;i++){
        if(q[i][0]){
            printf("%d\n",query(q[i][1],q[i][2],q[i][3]));
        }
        else{
            add(q[i][1],h(a[q[i][1]]),-1);
            add(q[i][1],h(q[i][2]),1);
            a[q[i][1]]=q[i][2];
        }
    }
    }
    return 0;
}
//just test