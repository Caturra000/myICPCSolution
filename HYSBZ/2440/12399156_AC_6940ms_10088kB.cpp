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
const int maxn = 1e6+11;
const double eps = 1e-7;
typedef long long ll;
const ll oo = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int mu[maxn],prime[maxn],cnt;
bool isprime[maxn];
void sai(int n){
    mu[0]=0;mu[1]=1;
    rep(i,2,n) isprime[i]=1;
    rep(i,2,n){
        if(isprime[i]){
            prime[++cnt]=i;
            mu[i]=-1;
        }
        rep(j,1,cnt){
            if(i*prime[j]>n) break;
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            mu[i*prime[j]]=-mu[i];
        }
    }
}
ll C(ll x){
    ll rt=sqrt(x+0.5),ans=0;
    rep(i,1,rt){
        ans+=x/i/i*mu[i];
    }
    return ans;
}
int main(){
    sai((int)1e6-11);
    int T=read();
    while(T--){
        ll x=read();
        ll l=x,r=2e9+50,mid,ans;
        while(r>=l){
            mid=l+r>>1;
            if(C(mid)>=x){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        println(ans);
    }
    return 0;
}