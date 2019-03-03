#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2.5e6+11;
const int MAXM = 1e7+11; 
const int MOD = 1e9+7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int MAXV;
struct QUERY{
    int x,y,val,type;
    bool operator < (const QUERY &rhs) const{
        if(x!=rhs.x) return x<rhs.x;
        return abs(type)<abs(rhs.type);
    }
}Q[MAXN],tmp[MAXN];
QUERY node(int _x,int _y,int _v,int _t){
    QUERY q;
    q.x=_x;q.y=_y;q.val=_v;q.type=_t;
    return q; 
}
int ans[MAXN];
struct FT{
    int ft[MAXN];
    inline int lowbit(int x){return x&-x;}
    void add(int k,int v){
        while(k<=MAXV){
            ft[k]+=v;
            k+=lowbit(k);
        }
    }
    int query(int k){
        int res=0;
        while(k>0){
            res+=ft[k];
            k-=lowbit(k);
        }
        return res;
    }
    void clear(int k){
        while(k<=MAXV){
            if(ft[k]){
                ft[k]=0;
            }else{
                break;
            }
            k+=lowbit(k);
        }
    }
    void init(){
        memset(ft,0,sizeof ft);
    }
}ft;
void solve(int l,int r){
    if(l==r) return;
    int mid=l+r>>1;
    solve(l,mid);
    solve(mid+1,r);
    int cnt=0,p=l,q=mid+1;
    while(p<=mid&&q<=r){
        if(Q[p]<Q[q]){
            if(Q[p].type==0) ft.add(Q[p].y,1);
            tmp[++cnt]=Q[p++];
        }else{
            // if(Q[q].type==-1) sum-=ft.sum(Q[q].y);
            if(Q[q].type==-1) ans[Q[q].val]-=ft.query(Q[q].y);
            if(Q[q].type==1) ans[Q[q].val]+=ft.query(Q[q].y);
            tmp[++cnt]=Q[q++]; 
        }
    }
    while(p<=mid) tmp[++cnt]=Q[p++];
    while(q<=r){
        if(Q[q].type==-1) ans[Q[q].val]-=ft.query(Q[q].y);
        if(Q[q].type==1) ans[Q[q].val]+=ft.query(Q[q].y);
        tmp[++cnt]=Q[q++];
    }
    rep(i,1,cnt) Q[i+l-1]=tmp[i];
    rep(i,1,cnt) ft.clear(tmp[i].y);
}
int main(){
    int n,m;
    while(cin>>n>>m){
        int cnt=0,ansid=0;
        MAXV=0;
        ft.init(); memset(ans,0,sizeof ans);
        rep(i,1,n){
            int x=read()+1;
            int y=read()+1; MAXV=max(MAXV,y);
            Q[++cnt]=node(x,y,0,0);
        }
        rep(i,1,m){
            int x_1=read()+1;
            int y_1=read()+1;
            int x_2=read()+1;
            int y_2=read()+1;
            Q[++cnt]=node(x_1-1,y_1-1,++ansid,1);
            Q[++cnt]=node(x_2,y_1-1,ansid,-1);
            Q[++cnt]=node(x_1-1,y_2,ansid,-1);
            Q[++cnt]=node(x_2,y_2,ansid,1);
            MAXV=max(MAXV,y_1);
            MAXV=max(MAXV,y_2);
        }
        solve(1,cnt);
        rep(i,1,ansid) println(ans[i]);
    }
    return 0;
}