#include<bits/stdc++.h>
#include<unordered_map>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1e5+11;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct FST{
    int num[MAXN<<5];
    int T[MAXN],tot;
    int lc[MAXN<<5],rc[MAXN<<5];
    void init(){tot=0;}
    void pu(int o){
        num[o]=num[lc[o]]+num[rc[o]];
    }
    int build(int l,int r){
        int cur=++tot;
        num[cur]=lc[cur]=rc[cur]=0;
        if(l==r) return cur;
        int mid=l+r>>1;
        lc[cur]=build(l,mid);
        rc[cur]=build(mid+1,r);
        return cur;
    }
    void copy(int cur,int old){
        num[cur]=num[old];
        lc[cur]=lc[old];
        rc[cur]=rc[old];
    }
    int update(int old,int l,int r,int k){
        int cur=++tot;
        copy(cur,old);
        if(l==r){
            num[cur]++;
            return cur;
        }
        int mid=l+r>>1;
        if(k<=mid) lc[cur]=update(lc[old],l,mid,k);
        else rc[cur]=update(rc[old],mid+1,r,k);
        pu(cur);
        return cur;
    }
    int query(int st,int ed,int l,int r,int k){
        while(1){
            if(l==r) return l;
            int t1=num[lc[ed]]-num[lc[st]];
            if(k>t1){
                k-=t1;
                ed=rc[ed];
                st=rc[st];
                l=(l+r>>1);l++;
            }else{
                ed=lc[ed];
                st=lc[st];
                r=(l+r>>1);
            }
        }
    }
}fst;
int a[MAXN],b[MAXN],c[MAXN];
unordered_map<int,int> mp;
int main(){
    int n,m,T=read();
    while(T--){
        n=read(); m=read(); mp.clear();
        rep(i,1,n) b[i]=a[i]=read();
        sort(b+1,b+1+n);
        int nn=unique(b+1,b+1+n)-b-1;
        rep(i,1,n) c[i]=lower_bound(b+1,b+1+nn,a[i])-b;
        rep(i,1,n) mp[c[i]]=a[i];
        fst.init(); fst.T[0]=fst.build(1,n);
        rep(i,1,n) fst.T[i]=fst.update(fst.T[i-1],1,n,c[i]);
        while(m--){
            int st=read();st--;
            int ed=read();
            int k=read();
            println(mp[fst.query(fst.T[st],fst.T[ed],1,n,k)]);
        }
    }
    return 0;
}