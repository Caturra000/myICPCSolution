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
const int maxn = 66666+11;
const double eps = 1e-7;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
// int prime[maxn],mu[maxn],tot;
// bool vis[maxn],isprime[maxn];
// ll sum[maxn];
// void get(int n){
//     mu[1]=1;
//     rep(i,2,n){
//         if(!vis[i])prime[++tot]=i,mu[i]=-1;
//         rep(j,1,tot){
//             if(i*prime[j]>maxn)break;
//             vis[i*prime[j]]=1;
//             if(i%prime[j]==0){
//                 mu[i*prime[j]]=0;
//                 break;
//             }else{
//                 mu[i*prime[j]]=-mu[i];
//             }
//         }
//     }
//     rep(i,1,n){
//         sum[i]=sum[i-1]+mu[i];
//     }
// }
// ll cal(int n,int m){
//     if(n>m) swap(n,m);
//     ll ans=0;int pos=0;
//     for(int i=1;i<=n;i=pos+1){
//         pos=min(n/(n/i),m/(m/i));
//         ans+=(sum[pos]-sum[i-1])*(n/i)*(m/i);
//     }
//     return ans;
// }
// int main(){
//     int n,m;
//     get(maxn-1);
//     while(cin>>n>>m){
//         int tmp=min(n,m);
//         ll ans=0;
//         rep(i,1,tmp){
//             if(i==1) ans+=cal(n/i,m/i);
//             else ans+=cal(n/i,m/i)*(2*(i-1)+1);
//         }
//         println(ans);
//     }
//     return 0;
// }
double dp[maxn];//zhandouliwei i shi taoli de qiwang
// double dp[maxn];//d
//if manzu dp[i]=dp[i]+t[i]
//else bumanzu dp[i]=dp[i+ci]+1

int n,f,c[maxn],t[maxn];
int main(){
    while(cin>>n>>f){
        rep(i,1,n) c[i]=read();
        rep(i,1,n) t[i]=(int)((1.0+sqrt(5))/2.0*c[i]*c[i]);
        memset(dp,0,sizeof dp);
        int Limit=-1;
        ll sum=0;
        rep(i,1,n){
            sum+=t[i];
            Limit=max(Limit,c[i]+1);
        }
        rep(i,Limit,Limit<<1)dp[i]=(double)sum/n;
        rrep(i,Limit-1,f) rep(j,1,n){
            if(i>c[j]) dp[i]+=(double)1.0/n*t[j];
            else dp[i]+=(double)(1.0/n*(1+dp[i+c[j]]));
        }
        printf("%.3lf\n",dp[f]);
    }
    return 0;
}