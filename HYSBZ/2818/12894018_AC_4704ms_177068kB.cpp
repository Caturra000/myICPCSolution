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
const int maxn = 1e7+11;
const double eps = 1e-7;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int prime[maxn],mu[maxn],tot;
bool vis[maxn],isprime[maxn];
ll sum[maxn];
void get(int n){
    mu[1]=1;
    rep(i,2,n){
        if(!vis[i])prime[++tot]=i,mu[i]=-1;
        rep(j,1,tot){
            if(i*prime[j]>maxn)break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
    rep(i,1,n){
        sum[i]=sum[i-1]+mu[i];
    }
}
ll cal(int n){
    ll ans=0;int pos=0;
    for(int i=1;i<=n;i=pos+1){
        pos=n/(n/i);
        ans+=(sum[pos]-sum[i-1])*(n/i)*(n/i);
    }
    return ans;
}
int main(){
    int n;
    get(maxn-1);
    while(~iin(n)){
        int tmp=1;
        ll ans=0;
        while(prime[tmp]<=n&&tmp<=tot){
            ans+=cal(n/prime[tmp]);
            tmp++;
        }
        println(ans);
    }
    return 0;
}