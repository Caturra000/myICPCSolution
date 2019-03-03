#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 3e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int num[int(1e6+11)];
int sai(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            num[j]++;
        }
    }
}
int a[MAXN];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    ll sum[MAXN<<2];
    int mx[MAXN<<2];
    void pu(int o){
        sum[o]=sum[lc]+sum[rc];
        mx[o]=max(mx[lc],mx[rc]);
    }
    void build(int o,int l,int r){
        if(l==r){
            sum[o]=mx[o]=a[l];
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);   
        pu(o);
    }
    void update(int o,int l,int r,int L,int R){
        if(mx[o]<=2)return;
        if(l==r){
            sum[o]=mx[o]=num[mx[o]];
            return;
        }
        int mid=l+r>>1;
        if(L<=mid) update(lc,l,mid,L,R);
        if(R>mid) update(rc,mid+1,r,L,R);
        pu(o);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return sum[o];
        }
        int mid=l+r>>1;
        ll res=0;
        if(L<=mid) res+=query(lc,l,mid,L,R);
        if(R>mid) res+=query(rc,mid+1,r,L,R);
        return res;
    }
}st;
int main(){
    sai(1e6);
    int n,m;
    while(cin>>n>>m){
        rep(i,1,n) a[i]=read();
        st.build(1,1,n);
        while(m--){
            int op=read();
            int l=read();
            int r=read();
            if(op==1) st.update(1,1,n,l,r);
            else println(st.query(1,1,n,l,r)); 
        }
    }
    return 0;
}