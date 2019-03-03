#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
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
    int x[2],val;
    bool operator < (const Point &rhs) const{
        return x[D]<rhs.x[D];
    }
};
//struct REC{
//    int x[2],val;
//    bool operator < (const REC &rhs) const{
//        return x[D]<rhs.x[D];
//    }
//}rec[MAXN];
struct KD{
    int son[MAXN][2],lx[MAXN][2],rx[MAXN][2];
    int size[MAXN];
    ll sum[MAXN];
    Point p[MAXN];
    int root,tot;
    void pu(int o){
        int lc=son[o][0],rc=son[o][1];
        rep(i,0,1){
            lx[o][i]=rx[o][i]=p[o].x[i];
            if(lc){
                if(lx[lc][i]<lx[o][i]) lx[o][i]=lx[lc][i];
                if(rx[lc][i]>rx[o][i]) rx[o][i]=rx[lc][i];
            }
            if(rc){
                if(lx[rc][i]<lx[o][i]) lx[o][i]=lx[rc][i];
                if(rx[rc][i]>rx[o][i]) rx[o][i]=rx[rc][i];
            }
        }
        sum[o]=p[o].val+sum[lc]+sum[rc];
        size[o]=1+size[lc]+size[rc];
    }
    void init(){
        root=tot=D=0;
    }
    bool ok(int o){
        int lc=son[o][0],rc=son[o][1];
        int ls=size[lc]<<2;
        int rs=size[rc]<<2;
        int sz=size[o]<<1|1; 
        return ls<=sz&&rs<=sz;
    }
    void insert(int &o,int now,int x,int y,int v){
        if(!o){
            o=++tot;
            p[o].x[0]=lx[o][0]=rx[o][0]=x;
            p[o].x[1]=lx[o][1]=rx[o][1]=y;
            p[o].val=sum[o]=v;size[o]=1;
            son[o][0]=son[o][1]=0;
            return;
        }else if(p[o].x[0]==x&&p[o].x[1]==y){
            p[o].val+=v;sum[o]+=v;
            return;
        }else if(now==0){
            if(x<p[o].x[0]) insert(son[o][0],1,x,y,v);
            else insert(son[o][1],1,x,y,v);
        }else{
            if(y<p[o].x[1]) insert(son[o][0],0,x,y,v);
            else insert(son[o][1],0,x,y,v);
        }
        pu(o);
    }
    bool inside(int x_1,int y_1,int x_2,int y_2,int X1,int Y1,int X2,int Y2){
        return x_1<=X1&&X2<=x_2&&y_1<=Y1&&Y2<=y_2;
    }
    bool outside(int x_1,int y_1,int x_2,int y_2,int X1,int Y1,int X2,int Y2){
        return x_1>X2||x_2<X1||y_1>Y2||y_2<Y1;
    }
    ll query(int o,int x_1,int y_1,int x_2,int y_2){
        if(!o) return 0;
        #define RECT  lx[o][0],lx[o][1],rx[o][0],rx[o][1]
        #define POT   p[o].x[0],p[o].x[1],p[o].x[0],p[o].x[1]
        if(inside(x_1,y_1,x_2,y_2,RECT)) return sum[o];
        if(outside(x_1,y_1,x_2,y_2,RECT)) return 0;
        ll res=0;
        if(inside(x_1,y_1,x_2,y_2,POT)) res=p[o].val;
        return res+query(son[o][0],x_1,y_1,x_2,y_2)+query(son[o][1],x_1,y_1,x_2,y_2);
    }
    int rebuild(int now,int l,int r){
        int mid=l+r>>1; son[mid][0]=son[mid][1]=0;
        D=now; nth_element(p+l,p+mid,p+r+1);
        // p[mid].x[0]=rec[mid].x[0];p[mid].x[1]=rec[mid].x[1];
        // val[mid]=sum[mid]=rec[mid].val;size[mid]=1;
        sum[mid]=p[mid].val; size[mid]=1;
        lx[mid][0]=rx[mid][0]=p[mid].x[0];
        lx[mid][1]=rx[mid][1]=p[mid].x[1];
        if(l<mid) son[mid][0]=rebuild(now^1,l,mid-1);
        if(r>mid) son[mid][1]=rebuild(now^1,mid+1,r);
        pu(mid);
        return mid;
    }
    void recycle(){
        root=rebuild(0,1,tot);
    }
}kd;
int main(){
    ll n,lastans=0;
    while(cin>>n){
        kd.init();
        int m=10000;
        while(1){
            int op=read();
            if(op==3) break;
            else if(op==1){
                int x=read()^lastans;
                int y=read()^lastans;
                int v=read()^lastans;
                kd.insert(kd.root,0,x,y,v);
                if(kd.tot==m) kd.recycle(),m+=10000;
            }else{
                int x_1=read()^lastans;
                int y_1=read()^lastans;
                int x_2=read()^lastans;
                int y_2=read()^lastans;
                lastans=kd.query(kd.root,x_1,y_1,x_2,y_2);
                println(lastans);
            }
        }
    }
    return 0;
}