#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 5e4+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct QAQ{
    int l,r,id;
    bool operator < (const QAQ &orz)const{
        return r<orz.r;
    }
}b[MAXN];
int ans[MAXN],a[MAXN],last[MAXN];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    int mx[MAXN<<2];
    void pu(int o){
        mx[o]=max(mx[lc],mx[rc]);
    }
    void build(int o,int l,int r){
        mx[o]=0;
        if(l==r) return;
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
    }
    void update(int o,int l,int r,int k,int v){
        if(l==r){mx[o]=max(mx[o],v);return;}
        int mid=l+r>>1;
        if(k<=mid) update(lc,l,mid,k,v);
        else update(rc,mid+1,r,k,v);
        pu(o);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R) return mx[o];
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid) ans=max(ans,query(lc,l,mid,L,R));
        if(R>mid) ans=max(ans,query(rc,mid+1,r,L,R));
        return ans;
    }
}st;
int main(){
    int T=read();
    while(T--){
        int n=read();
        rep(i,1,n) a[i]=read();
        int m=read();
        memset(ans,0,sizeof ans);
        memset(last,0,sizeof last);
        int cur=1; 
        rep(i,1,m){
            b[i].l=read();
            b[i].r=read();
            b[i].id=i;
        }
        sort(b+1,b+1+m);
        st.build(1,1,n);
        for(int i=1;i<=n;i++){
            for(ll j=1;j*j<=a[i];j++) if(a[i]%j==0){
                if(last[j]) st.update(1,1,n,last[j],j);
                if(last[a[i]/j]&&a[i]!=j*j) st.update(1,1,n,last[a[i]/j],a[i]/j);
                last[j]=i;
                last[a[i]/j]=i;
            }
            while(cur<=m&&b[cur].r==i){
                ans[b[cur].id]=st.query(1,1,n,b[cur].l,b[cur].r);
                ++cur;
            }
        }
        rep(i,1,m) println(ans[i]);
    }
    return 0;
}