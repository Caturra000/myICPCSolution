#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<bitset>
#define lc o<<1
#define rc o<<1|1
using namespace std;
const int maxn = 1e5+11;
int li[maxn],ri[maxn],qi[maxn];
struct ST{
    int huo[maxn<<2],lazy[maxn<<2];
    void pd(int o){
        if(lazy[o]){
            lazy[lc]|=lazy[o];
            lazy[rc]|=lazy[o];
            huo[lc]|=lazy[o];
            huo[rc]|=lazy[o];
            lazy[o]=0;
        }
    }
    void pu(int o){
        huo[o]&=huo[lc];
        huo[o]&=huo[rc];
    }
    void build(){
        memset(huo,0,sizeof huo);
        memset(lazy,0,sizeof lazy);
    }
    void update(int o,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            lazy[o]|=val;
            huo[o]|=val;
            return;
        }
        int mid=l+r>>1;
        pd(o);
        if(L<=mid) update(lc,l,mid,L,R,val);
        if(R>mid) update(rc,mid+1,r,L,R,val);
        pu(o);
    }
    int query(int o,int l,int r,int k){
        if(l==r){
            return huo[o];
        }
        pd(o);
        int mid=l+r>>1;
        if(k<=mid) return query(lc,l,mid,k);
        else return query(rc,mid+1,r,k);
    }
    int query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return huo[o];
        }
        pd(o);
        int mid=l+r>>1;
        int ans=~0;
        if(L<=mid) ans&=query(lc,l,mid,L,R);
        if(R>mid) ans&=query(rc,mid+1,r,L,R);
        return ans;
    }
}st;
int n,m;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        st.build();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d",&li[i],&ri[i],&qi[i]);
            st.update(1,1,n,li[i],ri[i],qi[i]);
        }
        bool flag=0;
        for(int i = 0; i < m; i++){
            if(st.query(1,1,n,li[i],ri[i])!=qi[i]){
                flag=1;break;
            }
        }
        if(flag) printf("NO\n");
        else{
            printf("YES\n");
            for(int i = 1; i <= n; i++){
                if(i==n) printf("%d\n",st.query(1,1,n,i));
                else printf("%d ",st.query(1,1,n,i));
            }
        }
    }
    return 0;
}