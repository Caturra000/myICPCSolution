#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
using namespace std;
const int MAXN = 4e4+11;
const int INF = 0x7fffffff;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define lowbit(x) ((x)&(-x))
struct FT{
    ll ft[MAXN];
    void init(){
        memset(ft,0,sizeof ft);
    }
    void update(int k,int v){
        while(k<MAXN){
            ft[k]+=v;
            k+=lowbit(k);
        }
    }
    ll query(int k){
        ll res=0;
        while(k){
            res+=ft[k];
            k-=lowbit(k);
        }
        return res;
    }
    ll query(int l,int r){
        if(l-1>0) return query(r)-query(l-1);
        return query(r);
    }
}ft[2];
struct XJB{
    int v,x;
    bool operator < (const XJB &that) const{
        if(this->v!=that.v) return this->v<that.v;
        return this->x<that.x;
    }
}a[MAXN];
int main(){
    int n;
    while(cin>>n){
        rep(i,1,n){
            a[i].v=read();
            a[i].x=read();
        }
        sort(a+1,a+1+n);
        rep(i,0,1) ft[i].init();
        ft[0].update(a[1].x,1);
        ft[1].update(a[1].x,a[1].x);
        ll res=0;
        rep(i,2,n){
            int r=ft[0].query(a[i].x+1,MAXN-1);
            int l=i-1-r;
            res+=(ll)(ft[1].query(a[i].x+1,MAXN-1)-r*a[i].x)*a[i].v;
            res+=(ll)(l*a[i].x-ft[1].query(a[i].x))*a[i].v;
            ft[0].update(a[i].x,1);
            ft[1].update(a[i].x,a[i].x);
        }
        println(res);
    }
    return 0;
}