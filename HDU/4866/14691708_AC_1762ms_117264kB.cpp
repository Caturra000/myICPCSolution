#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
const int MAXM = 2e6+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct LINE{
    int l,r,d;
    bool operator < (const LINE &rhs) const{
        return d<rhs.d;
    }
}line[MAXN];
typedef pair<ll,ll> P;
struct FST{
    ll val[MAXN<<6];
    int cnt[MAXN<<6];
    int lc[MAXN<<6],rc[MAXN<<6];
    int T[MAXN],tot;
    void init(){tot=0;}
    int build(int l,int r){
        int cur=++tot;
        cnt[cur]=val[cur]=lc[cur]=rc[cur]=0;
        if(l==r) return cur;
        int mid=l+r>>1;
        lc[cur]=build(l,mid);
        rc[cur]=build(mid+1,r);
        return cur;
    }
    inline void copy(int cur,int old){
        lc[cur]=lc[old];
        rc[cur]=rc[old];
        cnt[cur]=cnt[old];
        val[cur]=val[old];
    }
    int update(int old,int l,int r,int L,int R,ll v){
        int cur=++tot;
        copy(cur,old);
        //cnt[cur]++;
        if(L<=l&&r<=R){
            val[cur]+=v;
            cnt[cur]++;
            return cur;
        }
        int mid=l+r>>1;
        if(L<=mid) lc[cur]=update(lc[old],l,mid,L,R,v);
        if(R>mid) rc[cur]=update(rc[old],mid+1,r,L,R,v);
        return cur;
    }
    P query(int cur,int l,int r,int k){
        P p=P(cnt[cur],val[cur]);
        if(l==r) return p;
        int mid=l+r>>1;
        if(k<=mid){
             P t=query(lc[cur],l,mid,k);
             return P(p.first+t.first,p.second+t.second);
        }
        else{
            P t=query(rc[cur],mid+1,r,k);
            return P(p.first+t.first,p.second+t.second);
        }
    }
}fst;
int n,m,X,PP;
int main(){
    while(cin>>n>>m>>X>>PP){
        rep(i,1,n){
            line[i].l=read();
            line[i].r=read();
            line[i].d=read();
        }
        sort(line+1,line+1+n);
        fst.init(); fst.T[0]=fst.build(1,X);
        rep(i,1,n) fst.T[i]=fst.update(fst.T[i-1],1,X,line[i].l,line[i].r,line[i].d);
        ll pre=1;
        rep(i,1,m){
            ll x=read();
            ll a=read();
            ll b=read();
            ll c=read();
            int lo=0,hi=n,mid;
            ll k=(a*pre+b)%c;
            P p;
            while(lo<hi){
                mid=lo+(hi-lo)/2;
                p=fst.query(fst.T[mid],1,X,x);
                if(p.first>=k) hi=mid;
                else lo=mid+1;
            }
            P res=fst.query(fst.T[lo],1,X,x);
            if(pre>PP) res.second<<=1;
            pre=res.second;
            println(res.second);
        }
    }
    return 0;
}