#include<bits/stdc++.h>
#include<unordered_map>
#include<ext/pb_ds/priority_queue.hpp>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define println(x) print(x),print('\n')
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pr = pair<ll,ll>;
const int MAXN = 6e4+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
int a[MAXN],pre[MAXN],n;
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    double mn[MAXN<<2],lazy[MAXN<<2];
    void pu(int o){
        mn[o]=min(mn[lc],mn[rc]);
    }
    void build(int o,int l,int r,double x){
        mn[o]=1e12;
        lazy[o]=0;
        if(l==r){
            mn[o]=(double)(l-1.0)*x;
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid,x);
        build(rc,mid+1,r,x);
        pu(o);
    }
    void pd(int o){
        if(lazy[o]>1e-7){
            mn[lc]+=lazy[o];
            mn[rc]+=lazy[o];
            lazy[lc]+=lazy[o];
            lazy[rc]+=lazy[o];
            lazy[o]=0;
        }
    }
    void update(int o,int l,int r,int L,int R,double v){
        if(L<=l&&r<=R){
            mn[o]+=v;
            lazy[o]+=v;
            return;
        }
        pd(o);
        int mid=l+r>>1;
        if(L<=mid) update(lc,l,mid,L,R,v);
        if(R>mid)  update(rc,mid+1,r,L,R,v);
        pu(o);
    }
    double query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R) return mn[o];
        pd(o);
        int mid=l+r>>1;
        double ans=1e18;
        if(L<=mid) ans=min(ans,query(lc,l,mid,L,R));
        if(R>mid)  ans=min(ans,query(rc,mid+1,r,L,R));
        return ans;
    }
}st;
bool C(double mid){
    st.build(1,1,n,mid);
    memset(pre,0,sizeof pre);
    rep(i,1,n){
        st.update(1,1,n,pre[a[i]]+1,i,1);
        double t=st.query(1,1,n,1,i);
        if(t<=(double)i*mid) return 1;
        pre[a[i]]=i;
    }
    return 0;
}
int main(){
    fastIO;
    int T; cin>>T;
    while(T--){
        cin>>n;
        rep(i,1,n) cin>>a[i];
        double lo=0,hi=n+5,mid;
        int freq=40;
        while(freq--){
            mid=(lo+hi)/2.0;
            if(C(mid)) hi=mid;
            else lo=mid;
        }
        cout<<fixed<<setprecision(12)<<lo<<endl;
    }
    return 0;
}