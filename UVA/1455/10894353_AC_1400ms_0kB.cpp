#include<bits/stdc++.h>
#define clr(a) memset((a),0,sizeof (a));
using namespace std;
const int maxn = 1e5+11;
const int maxy = 1e6+11;
struct ST{
    int lc[maxy<<2],rc[maxy<<2],lx[maxy<<2],rx[maxy<<2];
    int city[maxy<<2],state[maxy<<2];
    int addc[maxy<<2],adds[maxy<<2];
    int tot,root;
    void init(){
        tot=root=0;
        clr(city);clr(state);
        clr(addc);clr(adds);
    }
    int node(){
        lc[tot]=rc[tot]=0;
        return tot++;
    }
    int build(int l,int r){
        int now=node();
        lx[now]=l;rx[now]=r;
        if(l==r) return now;
        int m=l+r>>1;
        lc[now]=build(l,m);
        rc[now]=build(m+1,r);
        return now;
    }
    void pd(int now){
        if(addc[now]){
            city[lc[now]]+=addc[now];
            city[rc[now]]+=addc[now];
            addc[lc[now]]+=addc[now];
            addc[rc[now]]+=addc[now];
            addc[now]=0;
        }
        if(adds[now]){
            state[lc[now]]+=adds[now];
            state[rc[now]]+=adds[now];
            adds[lc[now]]+=adds[now];
            adds[rc[now]]+=adds[now];
            adds[now]=0;
        }
    }
    void update(int now,int L,int R,int v,int flag){
        if(L<=lx[now]&&rx[now]<=R){
			if(!flag){
                city[now]+=v;
                addc[now]+=v;
                return;
            }
            else{
                state[now]+=v;//没有len
                adds[now]+=v;
                return;
            }
            return;
        }
        int m=lx[now]+rx[now]>>1;
        pd(now);
        if(L<=m) update(lc[now],L,R,v,flag);
        if(R>m) update(rc[now],L,R,v,flag);
    }
    int query(int now,int k,int flag){
        if(lx[now]==rx[now]){
            return flag?state[now]:city[now];
        }
        pd(now); 
        int m=lx[now]+rx[now]>>1;
        if(k<=m) return query(lc[now],k,flag);
        return query(rc[now],k,flag);
    }
}st;
struct UF{
    int p[maxn];
    int city[maxn],state[maxn];
    int low[maxn],high[maxn];
    void init(int y[],int n){
        for(int i = 0; i < n; i++){
            p[i]=i;
            city[i]=state[i]=1;
            low[i]=high[i]=y[i];
        }
    }
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    void link(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
		
        st.update(st.root,low[a]+1,high[a],-city[a],0);
        st.update(st.root,low[a]+1,high[a],-state[a],1);
        
        st.update(st.root,low[b]+1,high[b],-city[b],0);
        st.update(st.root,low[b]+1,high[b],-state[b],1);
        
        if(a>b) swap(a,b);
        p[b]=a;
        low[a]=min(low[a],low[b]);
        high[a]=max(high[a],high[b]);
        city[a]+=city[b]; state[a]=1;
        st.update(st.root,low[a]+1,high[a],city[a],0);
        st.update(st.root,low[a]+1,high[a],state[a],1);
    }
}uf;
int y[maxn],t;
char str[1111];
int main(){
    int T,q,n,a,b;double pos; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%d%d",&t,&y[i]);
        uf.init(y,n);st.init();st.build(0,maxy);
        scanf("%d",&q);
        for(int i = 0; i < q; i++){
            scanf("%s",str);
            if(str[0]=='r'){
                scanf("%d%d",&a,&b);
                uf.link(a,b);
            }
            else{
                scanf("%lf",&pos);
                printf("%d %d\n",st.query(st.root,(int)(pos+1),1),st.query(st.root,(int)(pos+1),0));
            }
        }
    }
    return 0;
}