#include<bits/stdc++.h>
#include<unordered_map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 5e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int a[MAXN];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    int g[MAXN<<2];
    int cnt;
    void pu(int o){
        g[o]=gcd(g[lc],g[rc]);
    }
    void build(int o,int l,int r){
        if(l==r){
            g[o]=a[l];
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pu(o);
    }
    void update(int o,int l,int r,int k,ll v){
        if(l==r){
            g[o]=v;
            return;
        }
        int mid=l+r>>1;
        if(k<=mid) update(lc,l,mid,k,v);
        else update(rc,mid+1,r,k,v);
        pu(o);
    }
    void query(int o,int l,int r,int L,int R,int x){
        if(cnt>1) return;
        if(l==r&&L<=l&&r<=R){
            if(g[o]%x!=0){
                cnt++;
            }
            return;
        }
        if(L<=l&&r<=R&&g[o]%x==0){
            return;
        }
        int mid=l+r>>1;
        if(L<=mid) query(lc,l,mid,L,R,x);
        if(R>mid) query(rc,mid+1,r,L,R,x);
    }
    bool query(int L,int R,int n,int x){
        cnt=0;
        query(1,1,n,L,R,x);
        return cnt<=1;
    }
}st;
int main(){
    int n,m;
    while(cin>>n){
        rep(i,1,n) a[i]=read();
        st.build(1,1,n);
        m=read();
        while(m--){
            int op=read();
            int x=read();
            int y=read();
            if(op==1){
                int v=read();
                bool flag=st.query(x,y,n,v);
                if(flag) printf("YES\n");
                else printf("NO\n");
            }else{
                st.update(1,1,n,x,y);
            }
        }
    }
    return 0;
}