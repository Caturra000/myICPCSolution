#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define print(a) printf("%lld",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 3e5+11;
const int INF = 0x3f3f3f3f;
typedef long long ll;
char str[MAXN];
struct ST{
    #define lc o<<1
    #define rc o<<1|1
    int pre[MAXN<<2],suf[MAXN<<2],val[MAXN<<2];
    void pu(int o){
        val[o]=val[lc]+val[rc]+bool(pre[rc]&&suf[lc]);
        pre[o]=pre[lc];
        suf[o]=suf[rc];
    }
    void build(int o,int l,int r){
        val[o]=pre[o]=suf[o]=0;
        if(l==r){
            val[o]=0;
            pre[o]=suf[o]=bool(str[l]=='.');
            return;
        }
        int mid=l+r>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pu(o);
    }
    void update(int o,int l,int r,int k,char ch){
        if(l==r){
            val[o]=0;
            pre[o]=suf[o]=bool(ch=='.');
            return;
        }
        int mid=l+r>>1;
        if(k<=mid) update(lc,l,mid,k,ch);
        else update(rc,mid+1,r,k,ch);
        pu(o);
    }
    int ans(){
        return val[1];
    }
}st;
int main(){
    int n,m,pos;char s[8];
    while(cin>>n>>m){
        scanf("%s",str+1);
        st.build(1,1,n);
        rep(i,1,m){
            scanf("%d%s",&pos,s+1);
            st.update(1,1,n,pos,s[1]);
            println(st.ans());
        }
    }
    return 0;
}