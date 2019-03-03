#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 3.5e4+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int last[MAXN];
ll dp[52][MAXN],a[MAXN];
struct ST{
    ll mx[MAXN<<2],lazy[MAXN<<2];
    #define lc o<<1
    #define rc o<<1|1
    void pu(int o){
        mx[o]=max(mx[lc],mx[rc]);
    }
    void build(int o,int l,int r,int k){
        lazy[o]=0;
        if(l==r){
            mx[o]=dp[k][l];
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid,k);
        build(rc,mid+1,r,k);
        pu(o);
    }
    void pd(int o){
        if(lazy[o]){
            mx[lc]+=lazy[o],mx[rc]+=lazy[o];
            lazy[lc]+=lazy[o],lazy[rc]+=lazy[o];
            lazy[o]=0;
        }
    }
    void update(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            mx[o]++;
            lazy[o]++;
            return;
        }
        pd(o);
        int mid=l+r>>1;
        if(L<=mid) update(lc,l,mid,L,R);
        if(R>mid) update(rc,mid+1,r,L,R);
        pu(o);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R) return mx[o];
        int mid=l+r>>1; ll res=0;
        pd(o);
        if(L<=mid) res=max(res,query(lc,l,mid,L,R));
        if(R>mid) res=max(res,query(rc,mid+1,r,L,R));
        return res;
    }
}st;
/*
struct FT{
    int ft[MAXN<<1];
    void init(){memset(ft,0,sizeof ft);}
    #define lowbit(x) (x&-x)
    void update(int k,int v){while(k<(MAXN<<1))ft[k]+=v,k+=lowbit(k);}
    int query(int k){return k>0?ft[k]+query(k-lowbit(k)):0;}
}ft;
*/
int main(){
    int n,k;
    while(cin>>n>>k){
        memset(last,0,sizeof last);
        memset(dp,0,sizeof dp);
        rep(i,1,n) a[i]=read();
        rep(i,1,n){
            if(!last[a[i]]) dp[1][i]=dp[1][i-1]+1,last[a[i]]=i;
            else dp[1][i]=dp[1][i-1];
        }
        rep(kk,2,k){
            st.build(1,1,n,kk-1);//dp[kk-1][..]
            memset(last,0,sizeof last);
            rep(i,kk,n){
                int pos=last[a[i]];
                if(pos<1) pos=1;
                st.update(1,1,n,pos,i-1);
                dp[kk][i]=st.query(1,1,n,1,i-1);
                last[a[i]]=i;
            }
        }
        println(dp[k][n]);
    }
    return 0;
}