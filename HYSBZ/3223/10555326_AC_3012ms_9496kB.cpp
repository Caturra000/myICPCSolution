#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define clr(a) memset((a),0,sizeof (a))
using namespace std;
const int maxn = 3e5+12, INF = 0x3f3f3f3f;
int a[maxn],f[maxn],ch[maxn][2],size[maxn],key[maxn],delta[maxn],root;
int n,m,l,r;
void init(){
    clr(a);clr(f);clr(ch);clr(size);clr(key);clr(delta);
}
int get(int x){
    return ch[f[x]][1]==x;
}
void update(int x){
    size[x]=1+size[ch[x][0]]+size[ch[x][1]];
}
void pushdown(int x){
    if(x&&delta[x]){
        delta[ch[x][0]]^=1;
        delta[ch[x][1]]^=1;
        swap(ch[x][0],ch[x][1]);//?
        delta[x]=0;
    }
}
int build(int l,int r,int fa){
    if(l>r) return 0;
    int mid=(l+r)>>1;
    f[mid]=fa;key[mid]=a[mid];size[mid]=1;
    int lch=build(l,mid-1,mid);
    int rch=build(mid+1,r,mid);
    ch[mid][0]=lch,ch[mid][1]=rch;
    update(mid);
    return mid;
}
void rotate(int x){
    pushdown(f[x]);//?
    pushdown(x);//
    int old=f[x],oldf=f[old],wh=get(x);
    ch[old][wh]=ch[x][wh^1];
    if(ch[old][wh]) f[ch[old][wh]]=old;
    ch[x][wh^1]=old;
    f[old]=x;
    if(oldf) ch[oldf][ch[oldf][1]==old]=x;
    f[x]=oldf;
    update(old);
    update(x);
}
void splay(int x,int tar){
    for(int fa;(fa=f[x])!=tar;rotate(x)){
        if(f[fa]!=tar) rotate((get(x)==get(fa))?fa:x);
    }
    if(!tar) root=x;
}
int find(int x){
    int now=root;
    while(1){
        pushdown(now);
        if(x<=size[ch[now][0]]) now=ch[now][0];
        else{
            x-=size[ch[now][0]];
            if(x==1) return now;
            x-=1;
            now=ch[now][1];
        }
    }
}
void write(int x){
    pushdown(x);
    if(ch[x][0]) write(ch[x][0]);
    if(key[x]!=-INF&&key[x]!=INF) printf("%d ",key[x]);
    if(ch[x][1]) write(ch[x][1]);
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        a[1]=-INF;a[n+2]=INF; //2...n+1
        for(int i = 1; i <= n; i++) a[i+1]=i;
        root=build(1,n+2,0);
        for(int i = 1; i <= m; i++){
            scanf("%d%d",&l,&r);
            if(l>=r) continue;
            int ll=find(l);
            int rr=find(r+2);
            splay(ll,0);
            splay(rr,ll);
            delta[ch[ch[root][1]][0]]^=1;
        }
        write(root);printf("\n"); 
    }
    return 0;
}
