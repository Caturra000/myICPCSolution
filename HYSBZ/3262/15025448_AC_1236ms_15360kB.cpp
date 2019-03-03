#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 2e5+11;
const int MOD = 1e9+7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct QUERY{
    int a,b,c,val,ans;
    bool operator < (const QUERY &rhs) const{ //分治时对b排序 
        if(b!=rhs.b) return b<rhs.b;
        return c<rhs.c; //树状数组对c维护 //不要也可以 
    }
}Q[MAXN],tmp[MAXN],a[MAXN];
bool cmp(QUERY a,QUERY b){
    if(a.a!=b.a) return a.a<b.a;
    if(a.b!=b.b) return a.b<b.b;
    return a.c<b.c; 
}
int ans[MAXN],S,W,n,m;
struct FT{
    ll ft[MAXN];
    inline int lowbit(int x){return x&-x;}
    void update(int k,int v){
        while(k<=m){
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
        while(k<=m){
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
        if(Q[p].b<=Q[q].b){
            ft.update(Q[p].c,Q[p].val);
            tmp[++cnt]=Q[p++];
        }else{
            Q[q].ans+=ft.query(Q[q].c);
            tmp[++cnt]=Q[q++];
        }
    }
    while(p<=mid) tmp[++cnt]=Q[p++];
    while(q<=r){
        Q[q].ans+=ft.query(Q[q].c);
        tmp[++cnt]=Q[q++];
    }
    rep(i,l,p-1) ft.clear(Q[i].c);
    rep(i,1,cnt) Q[i+l-1]=tmp[i];
}
int main(){
    while(cin>>n>>m){
        ft.init();
        rep(i,1,n){
            a[i].a=read();
            a[i].b=read();
            a[i].c=read();
        }
        sort(a+1,a+1+n,cmp);//保证a有序且可去重 
        int cnt=0,num=0;
        rep(i,1,n){
            ++num;
            if(a[i].a!=a[i+1].a||a[i].b!=a[i+1].b||a[i].c!=a[i+1].c){
                Q[++cnt].a=a[i].a;
                Q[cnt].b=a[i].b;
                Q[cnt].c=a[i].c;    
                Q[cnt].val=num;
                Q[cnt].ans=0;
                num=0;
            }
        }
        solve(1,cnt);
        rep(i,1,cnt) ans[Q[i].ans+Q[i].val-1]+=Q[i].val;//xiuzheng
        rep(i,0,n-1) println(ans[i]);
    }
    return 0;
}