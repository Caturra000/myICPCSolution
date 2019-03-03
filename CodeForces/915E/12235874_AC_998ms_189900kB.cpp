#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e6+11;
int ll[maxn],rr[maxn],mark[maxn];
int ra[maxn],n,q;
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define scann(a,b) scanf("%d%d",&a,&b)
#define println(a) printf("%lld\n",a)
typedef long long LL;
struct ST{
    LL sum[maxn<<2];
	int lazy[maxn<<2];
    #define lc o<<1
    #define rc o<<1|1
    void init(){memset(lazy,-1,sizeof lazy);}
    void pu(int o){sum[o]=sum[lc]+sum[rc];}
    void pd(int o,int l,int r){
        if(~lazy[o]){
            lazy[lc]=lazy[rc]=lazy[o];
            int m = l+r>>1;
            sum[lc]=1ll*(ra[m]-ra[l-1])*lazy[o];
            sum[rc]=1ll*(ra[r]-ra[m])*lazy[o];
            lazy[o]=-1;
        }
    }
    void build(int o,int l,int r){
        if(l==r){
            sum[o]=1ll*ra[r]-ra[l-1];
            return;
        }
        int m = l+r>>1;
        build(lc,l,m);
        build(rc,m+1,r);
        pu(o);
    }
    void update(int o,int l,int r,int L,int R,int v){
        if(L<=l&&r<=R){
            sum[o]=1ll*(ra[r]-ra[l-1])*v;
            lazy[o]=v;
            return;
        }
        pd(o,l,r);
        int m = l+r>>1;
        if(L<=m) update(lc,l,m,L,R,v);
        if(R>m) update(rc,m+1,r,L,R,v);
        pu(o);
    }
    LL query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[o];
        pd(o,l,r);
        int m = l+r>>1;
        LL ans=0;
        if(L<=m) ans+=query(lc,l,m,L,R);
        if(R>m) ans+=query(rc,m+1,r,L,R);
        return ans;
    }
}st;
int main(){
    while(scann(n,q)^-1){
        rep(i,1,q) {scann(ll[i],rr[i]); scan(mark[i]);}
        rep(i,1,q) {ra[i]=ll[i]; ra[i+q]=rr[i];} ra[2*q+1]=1; ra[2*q+2]=n;
        sort(ra+1,ra+2*q+3);
        int qq = unique(ra+1,ra+2*q+3)-ra-1;
        int tot=qq;
		rep(i,1,qq-1){
			if(ra[i]+1<ra[i+1]) ra[++tot]=(ra[i]+1>=n?n:ra[i]+1);
		} 
		sort(ra+1,ra+tot+1);
		tot=unique(ra+1,ra+tot+1)-ra-1;
		qq=tot;
		for(int i=qq;i>1;i--){
			if(ra[i]-1>ra[i-1]) ra[++tot]=(ra[i]-1<=1?1:ra[i]-1);
		}
		sort(ra+1,ra+tot+1);
		tot=unique(ra+1,ra+tot+1)-ra-1;
        rep(i,1,q) ll[i]=lower_bound(ra+1,ra+tot+1,ll[i])-ra,rr[i]=lower_bound(ra+1,ra+tot+1,rr[i])-ra; 
        st.init();st.build(1,1,tot);
        rep(i,1,q){
            st.update(1,1,tot,ll[i],rr[i],(mark[i]==1?0:1));
            println(st.query(1,1,tot,1,tot));
        }
    }
    return 0;
}