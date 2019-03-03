#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 2e6+11;
bool Hash[30030];
int li[30030],ri[30030];
int arr[maxn],n;
struct ST{
    int cover[maxn<<2];
    #define lc o<<1
    #define rc o<<1|1
    void init(){memset(cover,0,sizeof cover);}
    void build(int o,int l,int r){
        cover[o]=0;
        if(l==r) return;
        int m=l+r>>1;
        build(lc,l,m);
        build(rc,m+1,r);
    }
    void pd(int o){
        if(cover[o]){
            cover[lc]=cover[rc]=cover[o];
            cover[o]=0;
        }
    }
    void update(int o,int l,int r,int L,int R,int v){
        if(L<=l&&r<=R){
            cover[o]=v;
            return;
        }
        pd(o);
        int m=l+r>>1;
        if(L<=m) update(lc,l,m,L,R,v);
        if(R>m) update(rc,m+1,r,L,R,v);
    }
    int query(int o,int l,int r,int L,int R){
        if(cover[o]){
            if(!Hash[cover[o]]){
                Hash[cover[o]]=1;
                return 1;
            }
            else return 0; 
        }
    	pd(o);
        if(l==r) return 0;//base: not found
        int m=l+r>>1;
        int ans=0;
        if(L<=m) ans+=query(lc,l,m,L,R);
        if(R>m) ans+=query(rc,m+1,r,L,R);
        return ans;
    }
}st;
int C(int x){
    if(x>=10000000) return 10000000;
    else if(x<=1) return 1;
    return x;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(Hash,0,sizeof Hash);
        rep(i,1,n){
            scanf("%d%d",&li[i],&ri[i]);
            arr[i]=li[i];arr[i+n]=ri[i];
        }
        arr[2*n+1]=1;arr[2*n+2]=10000000;
        int tot=2*n+2;
        sort(arr+1,arr+1+tot);
        int tmp=tot;
        rep(i,1,tmp-1){
            if(arr[i+1]-arr[i]>1){
                arr[++tot]=C(arr[i+1]-1);
                arr[++tot]=C(arr[i]+1);
            }
        }
        sort(arr+1,arr+1+tot);
        tot=unique(arr+1,arr+1+tot)-arr-1;
        rep(i,1,n){
            li[i]=lower_bound(arr+1,arr+1+tot,li[i])-arr;
            ri[i]=lower_bound(arr+1,arr+1+tot,ri[i])-arr;
        }
        st.init(); st.build(1,1,tot);
        rep(i,1,n){
            st.update(1,1,tot,li[i],ri[i],i);
        }
        printf("%d\n",st.query(1,1,tot,1,tot));
    }
    return 0;
}