#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
const int MOD = 1e9+7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct QUERY{
    int a,b,c;
    bool operator < (const QUERY &rhs) const{
        if(b!=rhs.b) return b<rhs.b;
        return c<rhs.c;
    }
}Q[MAXN],tmp[MAXN];
bool cmp(QUERY a,QUERY b){
    if(a.a!=b.a) return a.a<b.a;
    if(a.b!=b.b) return a.b<b.b;
    return a.c<b.c; 
}
int S,W,n,m;
ll ans[MAXN];
struct FT{
    ll ft[MAXN];
    inline int lowbit(int x){return x&-x;}
    void update(int k,int v){
        while(k<=n){
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
        while(k<=n){
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
    int p=l,q=mid+1,cnt=0;
    while(p<=mid&&q<=r){
        if(Q[p].b<Q[q].b){
            ft.update(Q[p].c,1);
            tmp[++cnt]=Q[p++];
        }else{
            ans[Q[q].a]+=ft.query(Q[q].c);
            tmp[++cnt]=Q[q++];
        }
    }
    while(p<=mid) tmp[++cnt]=Q[p++];
    while(q<=r){
        ans[Q[q].a]+=ft.query(Q[q].c);
        tmp[++cnt]=Q[q++];
    }
    rep(i,l,p-1) ft.clear(Q[i].c);
    rep(i,1,cnt) Q[i+l-1]=tmp[i];
}
int ord[MAXN];
int main(){
    while(cin>>n>>m){
        int cnt=0,t=n;
        rep(i,1,n){
            int x=read();
            Q[++cnt].a=0;
            Q[cnt].b=i;
            Q[cnt].c=x;
        }
        memset(ord,0,sizeof ord);
        rep(i,1,m){
            int x=read();
            ord[x]=i;
        }
        int tt=m;
        rep(i,1,n) if(ord[i]==0) ord[i]=++tt;
        rep(i,1,n) Q[i].a=n-ord[Q[i].c]+1;
        rep(i,1,n) Q[i].c=n-Q[i].c+1;
        sort(Q+1,Q+1+cnt,cmp);
        ft.init();
        solve(1,cnt);
        rep(i,1,n){
            Q[i].c=n-Q[i].c+1;
            Q[i].b=n-Q[i].b+1;
        }
        sort(Q+1,Q+1+cnt,cmp);
        ft.init();
        solve(1,cnt);
        rep(i,1,n) ans[i]+=ans[i-1];
        rrep(i,n,n-m+1) println(ans[i]); 
    }
    return 0;
}