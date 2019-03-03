#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 5e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7;
ll read() {
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[666],x,y,n,m,k;
int main(){
    while(cin>>n>>m>>k){
        if(n+m-2<k){
            println(-1);
            continue;
        }
        ll ans=-INF;
        if(n>m) swap(n,m);
        if(k<n) ans=max((n/(k+1))*m,( m/(k+1))*n );
        else if(k>=n&&k<m) ans=n*(m/(k+1));
        else if(k>=m&&k<=n+m-2){
                ans=max(1ll*m/(k-n+2),1ll*n/(k-m+2));
        }
        println(ans);
        // ll ans1,ans2,ans3;
        // ans1=ans2=ans3=-INF;
        // if(n-1>=k){
        //     ans1=m*(n/(k+1));
        // }
        // if(m-1>=k){
        //     ans2=n*(m/(k+1));
        // }
        // if(n+m-2>=k){
        //     ll t=k/2;
        //     ll t2=k-t;
        //     ans3=max((n/(t+1))*(m/(t2+1)),(m/(t+1)*(n/(t2+1))));
        // }
        // println(max(ans1,max(ans2,ans3)));
    }
    return 0;
}