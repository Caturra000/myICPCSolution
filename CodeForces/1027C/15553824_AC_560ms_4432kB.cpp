#include<bits/stdc++.h>
#include<unordered_map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
using namespace std;
const int MAXN = 1e6 + 11;
const int MOD = 1e9+7;
typedef long long ll;
const ll INF = 1ll<<62;
ll read(){
    ll x = 0, f = 1; register char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x*f;
}
int a[MAXN];
inline double cal(int x,int y){
     ll p=a[x]+a[y]<<1;
     ll s=1ll*a[x]*a[y];
     return (double)p*p/s;
}
int main(){
    int T=read();
    while(T--){
        map<int,int> mp;
        int n=read();
        int cnt=0;
        rep(i,1,n) mp[read()]++;
        map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();++it){
            int x=(*it).first,y=(*it).second;
            if(y<2) continue;
            a[++cnt]=x;
            if(y>3) a[++cnt]=x;
        }
        double ans=1e18;
        int x,y;
        rep(i,1,cnt-1){
            if(ans>cal(i,i+1)){
                ans=cal(i,i+1);
                x=a[i],y=a[i+1];
            }
        }
        printf("%d %d %d %d\n",x,y,x,y);
    }
    return 0;
}