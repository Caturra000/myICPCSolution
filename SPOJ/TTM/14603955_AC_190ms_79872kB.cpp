#include<bits/stdc++.h>
#include<unordered_map>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN];
struct FST{
    int lc[MAXN<<5],rc[MAXN<<5],delta[MAXN<<5];
    ll sum[MAXN<<5];
    int T[MAXN],ed[MAXN],tot;
    void init(){
        tot=0;
    }
    void pu(int o){
        sum[o]=sum[lc[o]]+sum[rc[o]];
    }
    int build(int l,int r){
        int cur=++tot;
        delta[cur]=0;
        if(l==r){
            sum[cur]=a[l];
            lc[cur]=rc[cur]=0;
            return cur;
        }
        int mid=l+r>>1;
        lc[cur]=build(l,mid);
        rc[cur]=build(mid+1,r);
        pu(cur);
        return cur;
    }
    int update(int old,int l,int r,int L,int R,int v){
        int cur=++tot;
        delta[cur]=delta[old];
        sum[cur]=sum[old];
        sum[cur]+=(ll)(min(R,r)-max(L,l)+1)*v;
        lc[cur]=lc[old];
        rc[cur]=rc[old];
        if(L<=l&&r<=R){
            delta[cur]+=v;
            return cur; 
        }
        int mid=l+r>>1;
        if(L<=mid)lc[cur]=update(lc[old],l,mid,L,R,v);
        if(R>mid)rc[cur]=update(rc[old],mid+1,r,L,R,v);
        return cur;
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[o];
        int mid=l+r>>1;
        ll ans=(ll)(min(r,R)-max(L,l)+1)*delta[o];
        if(L<=mid) ans+=query(lc[o],l,mid,L,R);
        if(R>mid) ans+=query(rc[o],mid+1,r,L,R);
        return ans;
    }
    
}fst;
int main(){
    int n,m;
    bool flag=0;
    while(cin>>n>>m){
        if(flag==0) flag=1;
        else printf("\n");
        rep(i,1,n) a[i]=read();
        fst.init();
        fst.T[0]=fst.build(1,n);
        int now=0;fst.ed[now]=fst.tot;
        char str[1<<5];
        rep(i,1,m){
            scanf("%s",str);
            if(str[0]=='C'){
                int l=read();
                int r=read();
                int d=read();
                fst.T[now+1]=fst.update(fst.T[now],1,n,l,r,d); 
                now++; fst.ed[now]=fst.tot;
            }else if(str[0]=='Q'){
                int l=read();
                int r=read();
                println(fst.query(fst.T[now],1,n,l,r));
            }else if(str[0]=='H'){
                int l=read();
                int r=read();
                int t=read();
                println(fst.query(fst.T[t],1,n,l,r));
            }else{
                int t=read();
                now=t;fst.tot=fst.ed[t];
            }
        }
    }
    return 0;
}//OK