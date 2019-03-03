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
const int maxn = 2e4+11;
const double eps = 1e-10;
typedef long long ll;
const int oo = 0x3f3f3f3f;
const double ERR = -2.3333;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
// double dp[maxn];//zhandouliwei i shi taoli de qiwang
// double dp[maxn];//d
//if manzu dp[i]=dp[i]+p t[i]
//else bumanzu dp[i]=p dp[i+ci]+1

// int n,f,c[maxn],t[maxn];
// int main(){
//     while(cin>>n>>f){
//         rep(i,1,n) c[i]=read();
//         rep(i,1,n) t[i]=(int)((1.0+sqrt(5))/2.0*c[i]*c[i]);
//         memset(dp,0,sizeof dp);
//         int Limit=-1;
//         ll sum=0;
//         rep(i,1,n){
//             sum+=t[i];
//             Limit=max(Limit,c[i]+1);
//         }
//         rep(i,Limit,Limit<<1)dp[i]=(double)sum/n;
//         rrep(i,Limit-1,f) rep(j,1,n){
//             if(i>c[j]) dp[i]+=(double)1.0/n*t[j];
//             else dp[i]+=(double)(1.0/n*(1+dp[i+c[j]]));
//         }
//         printf("%.3lf\n",dp[f]);
//     }
//     return 0;
// }
int to[maxn<<1],nxt[maxn<<1],head[maxn],tot;
void init(){
    memset(head,-1,sizeof head);
    tot=0;
}
void add(int u,int v){
    to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
    swap(u,v);
    to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
}
double A[maxn],B[maxn],C[maxn],k[maxn],e[maxn];
bool isleaf(int u,int fa){
    int cnt=0;
    erep(i,u){
        int v=to[i];
        if(v!=fa)cnt++;
        if(cnt==1)return 0;
    }
    return 1;
}
void DP(int u,int fa){
    if(A[u]!=ERR)return;
    if(isleaf(u,fa)){
        A[u]=k[u];
        B[u]=(1.0-e[u]-k[u]);
        C[u]=(1.0-e[u]-k[u]);
        return;
    }
    int num=0;
    double sumA=0,sumB=0,sumC=0;
    erep(i,u){
        int v=to[i];
        num++;
        if(v==fa)continue;
        DP(v,u);
        sumA+=A[v];
        sumB+=B[v];
        sumC+=C[v];
    }
    int i=u;
    A[i]=(k[i]+(1-k[i]-e[i])/num*sumA)/(1.0-(1.0-k[i]-e[i])/num*sumB);
    B[i]=(1.0-k[i]-e[i])/num/(1.0-(1.0-k[i]-e[i])/num*sumB);
    C[i]=((1.0-k[i]-e[i])+(1.0-k[i]-e[i])/num*sumC)/(1.0-(1.0-k[i]-e[i])/num*sumB);
    
}
int main(){
    int T=read(),kase=0;
    while(T--){
        init();
        int n=read();
        rep(i,1,n){
            A[i]=B[i]=C[i]=ERR;
        }
        rep(i,1,n-1){
            int u=read();
            int v=read();
            add(u,v);
        }
        rep(i,1,n){
            scanf("%lf%lf",&k[i],&e[i]);
            k[i]/=100.0;
            e[i]/=100.0;
        }
        DP(1,0);
        double ans=(fabs(1.0-A[1])<eps?ERR:C[1]/(1.0-A[1]));
        printf("Case %d: ",++kase);
        if(ans==ERR) printf("impossible\n");
        else printf("%.6lf\n",ans);
    }
    return 0;
}