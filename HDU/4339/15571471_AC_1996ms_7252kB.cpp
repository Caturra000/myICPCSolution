#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
using namespace std;
const int MAXN = 1e6 + 11;
const int MOD = 1ll<<30;
typedef long long ll;
const ll INF = 1ll<<62;
ll read(){
    ll x = 0, f = 1; register char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x*f;
}
struct FT{
    int ft[MAXN];
    void init(){memset(ft,0,sizeof ft);}
    inline int lowbit(int x){return x&-x;}
    void update(int k,int v){while(k<MAXN)ft[k]+=v,k+=lowbit(k);}
    int query(int k){
        int res=0;
        while(k>0){
            res+=ft[k];
            k-=lowbit(k);
        }
        return res;
    }
}ft;
char s[2][MAXN];
int main(){
    int T=read(),kase=0;
    while(T--){
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        int m=read();
        int n=max(strlen(s[0]+1),strlen(s[1]+1));
        char ch[7];
        ft.init();
        rep(i,1,n) if(s[0][i]!=s[1][i]) ft.update(i,1);
        printf("Case %d:\n",++kase);
        while(m--){
            int op=read();
            if(op==1){
                int wh=read();
                int i=1+read();
                scanf("%s",ch+1);
                if(i>n) continue;
                bool flag=(s[0][i]!=s[1][i]);
                s[wh-1][i]=ch[1];
                bool flag2=(s[0][i]!=s[1][i]);
                if(flag==flag2) continue;
                else if(flag==1&&flag2==0) ft.update(i,-1);
                else ft.update(i,1);
            }else{
                int k=1+read();
                if(k>n){
                    println(0);
                    continue;
                }
                int lo=k,hi=n,ans=k-1;
                while(lo<=hi){
                    int mid=lo+hi>>1;
                    if(ft.query(mid)-ft.query(k-1)==0) ans=mid,lo=mid+1;
                    else hi=mid-1;
                }
                println(ans-k+1);
            }
        }
    }
    return 0;
}