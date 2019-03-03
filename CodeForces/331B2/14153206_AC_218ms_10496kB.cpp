#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 3e5+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int a[MAXN],pos[MAXN];
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct ST{
    #define lc o<<1
    #define rc o<<1|1
//    int head[MAXN<<2],tail[MAXN<<2], //quanz
    int cnt[MAXN<<2];
    void pu(int o,int l,int r){
//        if(tail[rc]==0){
//            cnt[o]=cnt[lc];
//            head[o]=head[lc];
//            tail[o]=tail[lc];
//        }else if(head[lc]==0){
//            cnt[o]=cnt[rc];
//            head[o]=head[rc];
//            tail[o]=tail[rc];
//        }else{
//            cnt[o]=cnt[lc]+cnt[rc];
//            if(tail[lc]<head[rc]&&pos[tail[lc]]<pos[head[rc]]) cnt[o]--;
//            head[o]=head[lc];
//            tail[o]=tail[rc];
//        }
        cnt[o]=cnt[lc]+cnt[rc];
        int taillc=l+r>>1;
        int headrc=taillc+1;
        if(pos[taillc]<pos[headrc]) cnt[o]--;
    }
    void build(int o,int l,int r){
//        head[o]=tail[o]=0;
        if(l==r){
//            head[o]=tail[o]=a[l];
            cnt[o]=1;
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pu(o,l,r);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return cnt[o];
        }
        int mid=l+r>>1;
        ll ans1=0,ans2=0,ans3=0; 
        if(L<=mid) ans1=query(lc,l,mid,L,R);
        if(R>mid) ans2=query(rc,mid+1,r,L,R);
//        if(ans1&&ans2) ans3=tail[lc]<head[rc]&&pos[tail[lc]]<pos[head[rc]]?-1:0;
        if(ans1&&ans2){
            int taillc=l+r>>1;
            int headrc=taillc+1;
            if(pos[taillc]<pos[headrc]) ans3=-1;
        }
        return ans1+ans2+ans3;
    }
    void update(int o,int l,int r,int k,int v=1){
        if(l==r){
//            head[o]=tail[o]=v;
//            cnt[o]=1;
            return;
        }
        int mid=l+r>>1;
        if(k<=mid) update(lc,l,mid,k,v);
        else update(rc,mid+1,r,k,v);
        pu(o,l,r);
    }
}st;
int main(){
    int n,m;
    while(cin>>n){
        rep(i,1,n){
            a[i]=read();
            pos[a[i]]=i;
        }
        st.build(1,1,n);
        m=read();
        rep(i,1,m){
            int x,y,z;
            x=read();y=read();z=read();
            if(x==1){
//                int yy=pos[y],zz=pos[z];
////                cout<<yy<<" "<<zz<<endl;
//                if(yy>zz) swap(yy,zz);
//                cout<<st.query(1,1,n,yy,zz)<<endl;
                println(st.query(1,1,n,y,z));
            }else{
                int yy=a[y],zz=a[z];
                swap(pos[yy],pos[zz]);
                swap(a[y],a[z]);
                st.update(1,1,n,yy,1);
                st.update(1,1,n,zz,1);
            }
        }
    }
    return 0;
}