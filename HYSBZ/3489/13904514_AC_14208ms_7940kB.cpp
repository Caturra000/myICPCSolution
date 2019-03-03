#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
const int INF = 0x7fffffff;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int D;
struct Point{
    int x[3],val;
    bool operator < (const Point &rhs) const{
        return x[D]<rhs.x[D];
    }
};
struct KD{
    int son[MAXN][2],lx[MAXN][3],rx[MAXN][3];
    int size[MAXN];
    int mx[MAXN];
    Point p[MAXN];
    int root,tot;
    void pu(int o){
        mx[o]=p[o].val;
        int lc=son[o][0],rc=son[o][1];
        rep(i,0,2){
            lx[o][i]=rx[o][i]=p[o].x[i];
            if(lc){
                if(mx[lc]>mx[o]) mx[o]=mx[lc];
                if(lx[lc][i]<lx[o][i]) lx[o][i]=lx[lc][i];
                if(rx[lc][i]>rx[o][i]) rx[o][i]=rx[lc][i];
            }
            if(rc){
                if(mx[rc]>mx[o]) mx[o]=mx[rc];
                if(lx[rc][i]<lx[o][i]) lx[o][i]=lx[rc][i];
                if(rx[rc][i]>rx[o][i]) rx[o][i]=rx[rc][i];
            }
        }
        size[o]=1+size[lc]+size[rc];
    }
    void init(int n){
        root=D=0; tot=n;
    }
    inline bool inside(int o,int l,int r){
        return lx[o][2]>r&&rx[o][1]<l&&lx[o][0]>=l&&rx[o][0]<=r;
    }
    inline bool outside(int o,int l,int r){
        return lx[o][0]>r||rx[o][0]<l||lx[o][1]>=l||rx[o][2]<r;
    }
    inline bool in(int o,int l,int r){
        int x=p[o].x[0],y=p[o].x[1],z=p[o].x[2];
        return x>=l&&x<=r&&y<l&&z>r;
    }
//    ll query(int o,int l,int r){// l<=x<=r && y<l && z>r //上一个<l 下一个>r
//        if(!o) return 0;
//        if(inside(o,l,r)) return mx[o];
//        if(outside(o,l,r)) return 0;
//        ll res=0;
//        if(in(o,l,r)) res=p[o].val;
//        return max(res,max(query(son[o][0],l,r),query(son[o][1],l,r)));
//    }
    int ANS;
    void query(int o,int l,int r){
        if(!o) return;
        if(inside(o,l,r)){
            if(ANS<mx[o]) ANS=mx[o];
            return;
        }
        if(outside(o,l,r)) return;
        if(in(o,l,r)&&ANS<p[o].val) ANS=p[o].val;
        int lc=son[o][0], rc=son[o][1];
        if(mx[lc]>mx[rc]){
            if(mx[lc]>ANS) query(lc,l,r); 
            if(mx[rc]>ANS) query(rc,l,r);
        }else{
            if(mx[rc]>ANS) query(rc,l,r);
            if(mx[lc]>ANS) query(lc,l,r);
        }
    }
    int build(int now,int l,int r){
        int mid=l+r>>1; son[mid][0]=son[mid][1]=0;
        D=now; nth_element(p+l,p+mid,p+r+1);
        mx[mid]=p[mid].val; size[mid]=1;
        rep(i,0,2) lx[mid][i]=rx[mid][i]=p[mid].x[i];
        if(l<mid) son[mid][0]=build((now+1)%3,l,mid-1);
        if(r>mid) son[mid][1]=build((now+1)%3,mid+1,r);
        pu(mid); return mid;
    }
    ll query(int l,int r){
        ANS=0;
        query(root,l,r);
        return ANS;
    }
}kd;
int a[MAXN],pre[MAXN],nxt[MAXN];
int main(){
    ll n,m,lastans=0;
    while(cin>>n>>m){
        rep(i,1,n) pre[i]=-1;
        rep(i,1,n) nxt[i]=n+1;
        rep(i,1,n) a[i]=read();
        rep(i,1,n){
            kd.p[i].x[0]=i;
            kd.p[i].val=a[i];
            kd.p[i].x[1]=pre[a[i]];
            pre[a[i]]=i;
        }
        rrep(i,n,1){
            kd.p[i].x[2]=nxt[a[i]];
            nxt[a[i]]=i;
        }
        kd.init(n); kd.root=kd.build(0,1,n);
        rep(i,1,m){
            int x=read();
            int y=read();
            int l=min((x+lastans)%n+1,(y+lastans)%n+1);
            int r=max((x+lastans)%n+1,(y+lastans)%n+1);
            ll res=kd.query(l,r);
            println(res);
            lastans=res;
        }
    }
    return 0;
}
