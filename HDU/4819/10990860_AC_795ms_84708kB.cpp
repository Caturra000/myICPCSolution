#include<bits/stdc++.h>
using namespace std;
const int maxn = 803;
const int oo = 0x3f3f3f3f;
const int xx = 0x80;
#define lc(o) (o)<<1
#define rc(o) (o)<<1|1
int a[maxn][maxn],n;
struct ST{
    int mn[maxn<<2][maxn<<2],mx[maxn<<2][maxn<<2];

    int mmin,mmax;
    void init(){
        memset(mn,oo,sizeof mn);
        memset(mx,xx,sizeof mx);
        mmin=oo;mmax=-oo;
    }
    void pu(int ox,int oy){
        mn[ox][oy]=min(mn[ox<<1][oy],mn[ox<<1|1][oy]);
        mx[ox][oy]=max(mx[ox<<1][oy],mx[ox<<1|1][oy]);
    }
    void _pu(int ox,int oy){
        mn[ox][oy]=min(mn[ox][oy<<1],mn[ox][oy<<1|1]);
        mx[ox][oy]=max(mx[ox][oy<<1],mx[ox][oy<<1|1]);
    }
    void _build(int oy,int l,int r,int ox,int x,int flag){//x:id为ox的外层线段树管辖的行边界(lx==rx)
        if(l==r){
            if(flag) mn[ox][oy]=mx[ox][oy]=a[x][l];
            else pu(ox,oy);
            return;
        }
        int m=l+r>>1;
        _build(oy<<1,l,m,ox,x,flag);
        _build(oy<<1|1,m+1,r,ox,x,flag);
        _pu(ox,oy);
    }
    void build(int ox,int l,int r){
        if(l==r){
            _build(1,1,n,ox,l,1);//[oy yl yr] [ox lx] flag
            return;
        }
        int m=l+r>>1;
        build(ox<<1,l,m);
        build(ox<<1|1,m+1,r);
        // pu(ox,oy);
        _build(1,1,n,ox,0,0);//lx==0? pu
    }
    void _update(int oy,int l,int r,int y,int v,int ox,int flag){
        if(l==y&&r==y){
            if(flag) mx[ox][oy]=mn[ox][oy]=v;
            else pu(ox,oy);
            return;
        }
        int m=l+r>>1;
        if(y<=m) _update(oy<<1,l,m,y,v,ox,flag);
        else _update(oy<<1|1,m+1,r,y,v,ox,flag);
        _pu(ox,oy);
    }
    void update(int ox,int l,int r,int x,int y,int v){//[ox,l,r][x,y->v]
        if(l==x&&r==x){
            _update(1,1,n,y,v,ox,1);
            return;
        }
        int m=l+r>>1;
        if(x<=m) update(ox<<1,l,m,x,y,v);
        if(x>m) update(ox<<1|1,m+1,r,x,y,v);
        _update(1,1,n,y,0,ox,0);//v==0 //pushup
    }
    void _query(int oy,int l,int r,int y1,int y2,int ox){
        if(y1<=l&&r<=y2){
            mmax=max(mmax,mx[ox][oy]);
            mmin=min(mmin,mn[ox][oy]);
            return;
        }
        int m=l+r>>1;
        if(y1<=m) _query(oy<<1,l,m,y1,y2,ox);
        if(y2>m) _query(oy<<1|1,m+1,r,y1,y2,ox);
    }
    void query(int ox,int l,int r,int x1,int x2,int y1,int y2){
        if(x1<=l&&r<=x2){
            _query(1,1,n,y1,y2,ox);
            return;
        }
        int m=l+r>>1;
        if(x1<=m) query(ox<<1,l,m,x1,x2,y1,y2);
        if(x2>m) query(ox<<1|1,m+1,r,x1,x2,y1,y2);
    }
}st;
int main(){
    int T,q,kase=0; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d",&a[i][j]);
            }
        }
        st.init();st.build(1,1,n);
        scanf("%d",&q);
        printf("Case #%d:\n",++kase);
        while(q--){
        	int x,y,L;
            scanf("%d%d%d",&x,&y,&L);
            int x1=max(x-L/2,1);
            int x2=min(x+L/2,n);
            int y1=max(y-L/2,1);
            int y2=min(y+L/2,n);
            st.query(1,1,n,x1,x2,y1,y2);
            printf("%d\n",st.mmax+st.mmin>>1);
            st.update(1,1,n,x,y,st.mmin+st.mmax>>1);
            st.mmin=oo;st.mmax=-oo;
        }
    }
    return 0;
}