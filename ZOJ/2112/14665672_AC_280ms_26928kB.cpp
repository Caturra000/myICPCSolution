#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 6e4+11;
const int MAXM = MAXN<<5;
const int MAXT = MAXN; //!!!!
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[MAXN],b[MAXN],c[MAXN],Q[10006][3],n,m,nn,N;
map<int,int> mp;
char str[1<<5];
const int FLAG = 1e9+7;
struct FST{
    int num[MAXM];
    int lc[MAXM],rc[MAXM];
    int T[MAXN],dT[MAXN],tot;
    void init(){
        memset(T,0,sizeof T);
        memset(dT,0,sizeof dT);
        memset(lc,0,sizeof lc);
        memset(rc,0,sizeof rc);
        memset(num,0,sizeof num);
        tot=0;
    }
    int build(int l,int r){
        int cur=++tot;
        lc[cur]=rc[cur]=num[cur]=0;
        if(l==r) return cur;
        int mid=l+r>>1;
        lc[cur]=build(l,mid);
        rc[cur]=build(mid+1,r);
        num[cur]=num[lc[cur]]+num[rc[cur]];
        return cur;
    }
    inline void copy(int cur,int old){
        num[cur]=num[old];
        lc[cur]=lc[old];
        rc[cur]=rc[old];
    }
    int update(int old,int l,int r,int k,int v){
        int cur=++tot;
        copy(cur,old);
        num[cur]+=v;
        if(l==r) return cur;
        int mid=l+r>>1;
        if(k<=mid) lc[cur]=update(lc[old],l,mid,k,v);
        else rc[cur]=update(rc[old],mid+1,r,k,v);
        return cur;
    }
}fst;
struct FT{
    int fstid[MAXT][2];
    void init(){
        memset(fstid,0,sizeof fstid);
    }
    inline int lowbit(int x){
        return x&-x;
    }
    void update(int k,int v){
        int t=lower_bound(b+1,b+1+N,a[k])-b;
        for(int i=k;i<MAXT;i+=lowbit(i)){
            fst.dT[i]=fst.update(fst.dT[i],1,N,t,v);
        }
    }
    int query(int k,bool who){
        int res=0;
        for(int i=k;i>0;i-=lowbit(i)){
            res+=fst.num[fst.lc[fstid[i][who]]];
        }
        return res;
    }
}ft;
int query(int st,int ed,int L,int R,int l,int r,int k){
    for(int i=L;i>0;i-=ft.lowbit(i)) ft.fstid[i][0]=fst.dT[i];
    for(int i=R;i>0;i-=ft.lowbit(i)) ft.fstid[i][1]=fst.dT[i];
    while(1){
        if(l==r) return l;
        int t=fst.num[fst.lc[ed]]-fst.num[fst.lc[st]];
        t+=ft.query(R,1);
        t-=ft.query(L,0);
        if(k<=t){
            ed=fst.lc[ed];
            st=fst.lc[st];
            for(int i=L;i>0;i-=ft.lowbit(i)) ft.fstid[i][0]=fst.lc[ft.fstid[i][0]]; 
            for(int i=R;i>0;i-=ft.lowbit(i)) ft.fstid[i][1]=fst.lc[ft.fstid[i][1]];
            r=l+r>>1;
        }else{
            k-=t;
            ed=fst.rc[ed];
            st=fst.rc[st];
            for(int i=L;i>0;i-=ft.lowbit(i)) ft.fstid[i][0]=fst.rc[ft.fstid[i][0]];
            for(int i=R;i>0;i-=ft.lowbit(i)) ft.fstid[i][1]=fst.rc[ft.fstid[i][1]];
            l=l+r>>1;l++;
        }
    }
}
int main(){
    //freopen("t.in","r",stdin);
    //freopen("t.out","w",stdout);
    int T=read();
    while(T--){
        n=read(); m=read();
        mp.clear(); nn=n; ft.init();
        rep(i,1,n) b[i]=a[i]=read();
        rep(i,1,m){
            scanf("%s",str);
            Q[i][2]=FLAG;
            Q[i][0]=read();
            Q[i][1]=read();
            if(str[0]=='Q') Q[i][2]=read();
            else{
                ++nn;
                b[nn]=a[nn]=Q[i][1];
            }
        }
        sort(b+1,b+1+nn);
        N=unique(b+1,b+1+nn)-b-1;
        rep(i,1,nn) c[i]=lower_bound(b+1,b+1+N,a[i])-b;
        rep(i,1,nn) mp[c[i]]=a[i];
        fst.init(); fst.T[0]=fst.build(1,N);
        rep(i,1,n) fst.T[i]=fst.update(fst.T[i-1],1,N,c[i],1);
        rep(i,1,n) fst.copy(fst.dT[i]=++fst.tot,fst.T[0]);
        rep(i,1,m){
            if(Q[i][2]!=FLAG){
                int L=Q[i][0];
                int R=Q[i][1];
                int k=Q[i][2];
                println(mp[query(fst.T[L-1],fst.T[R],L-1,R,1,N,k)]);
            }else{
                int k=Q[i][0];
                int v=Q[i][1];
                ft.update(k,-1);
                a[k]=v;
                ft.update(k,1);
            }
        }
    }
    return 0;
}