#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e5+11;
int lc[maxn<<5],rc[maxn<<5],lazy[maxn<<5],T[maxn],tot;
ll st[maxn<<5];
int n,mm,cur,L,R,v,t;char str[50];
void init(){
    memset(lc,0,sizeof lc);memset(rc,0,sizeof rc);memset(st,0,sizeof st);
    memset(lazy,0,sizeof lazy);memset(T,0,sizeof T);
    tot=0;cur=0;
}
int build(int l,int r){
    int now=tot++;
    if(l==r){
        scanf("%lld",&st[now]);
        return now;
    }
    int m=(l+r)>>1;
    lc[now]=build(l,m);
    rc[now]=build(m+1,r);
    st[now]=st[lc[now]]+st[rc[now]];
    return now;
}
int update(int pre,int L,int R,int v,int l,int r){
    int now=tot++;
    lc[now]=lc[pre];rc[now]=rc[pre];lazy[now]=lazy[pre];st[now]=st[pre];
    st[now]+=(ll)v*(R-L+1);
    if(L==l&&R==r){
        lazy[now]+=v;
        return now;
    }
    int m=(l+r)>>1;
    if(R<=m) lc[now]=update(lc[now],L,R,v,l,m);
    else if(L>m) rc[now]=update(rc[now],L,R,v,m+1,r);
    else{
        lc[now]=update(lc[now],L,m,v,l,m);
        rc[now]=update(rc[now],m+1,R,v,m+1,r);
    }
    return now;
}
ll query(int pre,int L,int R,int l,int r){
    if(L==l&&r==R) return st[pre];
    int m = (l+r)>>1;
    ll ans = (ll)lazy[pre]*(R-L+1);
    if(R<=m) return ans+query(lc[pre],L,R,l,m);
    else if(L>m) return ans+query(rc[pre],L,R,m+1,r);
    else return ans+query(lc[pre],L,m,l,m)+query(rc[pre],m+1,R,m+1,r);
}
int main(){
    while(scanf("%d%d",&n,&mm)!=EOF){
        init();
        T[0]=build(1,n);
        for(int i = 0; i < mm; i++){
            scanf("%s",str);
            if(str[0]=='C'){
                scanf("%d%d%d",&L,&R,&v);
                cur++;
                T[cur]=update(T[cur-1],L,R,v,1,n);
            }
            else if(str[0]=='Q'){
                scanf("%d%d",&L,&R);
                printf("%lld\n",query(T[cur],L,R,1,n));
            }
            else if(str[0]=='H'){
                scanf("%d%d%d",&L,&R,&t);
                printf("%lld\n",query(T[t],L,R,1,n));
            }
            else{
                scanf("%d",&cur);
            }
        }
    }
    return 0;
}