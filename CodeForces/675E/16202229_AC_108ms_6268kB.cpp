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
const int MAXN = 2e5+11;
const int INF  = 0x3f3f3f3f;
const double EPS = 1e-7;
ll a[MAXN];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    int val[MAXN<<2];
    void pu(int o){
        if(a[val[lc]]>a[val[rc]]) val[o]=val[lc];
        else val[o]=val[rc];
    }
    void build(int o,int l,int r){
        if(l==r){
            val[o]=l;
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pu(o);
    }
    int query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R) return val[o];
        int mid=l+r>>1;
        int t1=-INF,t2=-INF;
        if(L<=mid) t1=query(lc,l,mid,L,R);
        if(R>mid)  t2=query(rc,mid+1,r,L,R);
        if(t2==-INF) return t1;
        if(t1==-INF) return t2;
        if(a[t1]>a[t2]) return t1;
        return t2;
    }
}st;
ll dp[MAXN],n;
int main(){
    fastIO;
    while(cin>>n){
        memset(dp,0,sizeof dp);
        rep(i,1,n-1) cin>>a[i];
        st.build(1,1,n-1);
        ll ans=0;
        rrep(i,n-1,1){
            int pos=st.query(1,1,n-1,i+1,a[i]);
            if(i==n-1) pos=n;
            dp[i]=dp[pos]+(n-i)-(a[i]-pos);
            ans+=dp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}