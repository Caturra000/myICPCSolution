#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<ctime>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e5 + 11;
const int MOD = 1e9+7;
typedef long long ll;
ll read(){
    ll x = 0, f = 1; register char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x*f;
}
ll a[MAXN],b[MAXN];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    ll mn[MAXN<<2],mx[MAXN<<2],cnt[MAXN<<2];
    ll lazy[MAXN<<2];
    void pu(int o){
        mx[o]=max(mx[lc],mx[rc]);
        mn[o]=min(mn[lc],mn[rc]);
        cnt[o]=cnt[lc]+cnt[rc];
    }
    void build(int o,int l,int r){
        lazy[o]=0;
        if(l==r){
            mn[o]=b[l];
            mx[o]=0;
            cnt[o]=0;
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pu(o);
    }
    void pd(int o){
        if(lazy[o]){
            mx[lc]+=lazy[o];
            mx[rc]+=lazy[o];
            lazy[lc]+=lazy[o];
            lazy[rc]+=lazy[o];
            lazy[o]=0;
        }
    }
    void update(int o,int l,int r,int L,int R){
        if(l==r){
            mx[o]++;
            while(mx[o]>=mn[o]) cnt[o]+=mx[o]/mn[o],mn[o]+=b[l];
            //while(mx[o]>=mn[o]) mx[o]-=mn[o],cnt[o]++;
            return;
        }
        if(L<=l&&r<=R){
            if(mx[o]+1<mn[o]){
                mx[o]++;
                lazy[o]++;
                return;
            }
        }
        int mid=l+r>>1;
        pd(o);
        if(L<=mid) update(lc,l,mid,L,R);
        if(R>mid) update(rc,mid+1,r,L,R);
        pu(o);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R) return cnt[o];
        pd(o);
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid) ans+=query(lc,l,mid,L,R);
        if(R>mid) ans+=query(rc,mid+1,r,L,R);
        return ans;
    }
}st;
int main(){
    int n,m;
    while(cin>>n>>m){
        rep(i,1,n) b[i]=read();
        st.build(1,1,n);
        char str[666];
        while(m--){
            scanf("%s",str+1);
            int l=read();
            int r=read();
            if(str[1]=='a'){
                st.update(1,1,n,l,r);
            }else{
                println(st.query(1,1,n,l,r));
            }
        }
    }
    return 0;
}