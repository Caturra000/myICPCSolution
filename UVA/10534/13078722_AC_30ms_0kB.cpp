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
const int maxn = 1e5+11;
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
// int to[maxn<<1],nxt[maxn<<1],head[maxn],tot;
// void init(){
//     memset(head,-1,sizeof head);
//     tot=0;
// }
// void add(int u,int v){
//     to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
//     swap(u,v);
//     to[tot]=v;nxt[tot]=head[u];head[u]=tot++;
// }
// double A[maxn],B[maxn],C[maxn],k[maxn],e[maxn];
// bool isleaf(int u,int fa){
//     int cnt=0;
//     erep(i,u){
//         int v=to[i];
//         if(v!=fa)cnt++;
//         if(cnt==1)return 0;
//     }
//     return 1;
// }
// void DP(int u,int fa){
//     if(A[u]!=ERR)return;
//     if(isleaf(u,fa)){
//         A[u]=k[u];
//         B[u]=(1.0-e[u]-k[u]);
//         C[u]=(1.0-e[u]-k[u]);
//         return;
//     }
//     int num=0;
//     double sumA=0,sumB=0,sumC=0;
//     erep(i,u){
//         int v=to[i];
//         num++;
//         if(v==fa)continue;
//         DP(v,u);
//         sumA+=A[v];
//         sumB+=B[v];
//         sumC+=C[v];
//     }
//     int i=u;
//     A[i]=(k[i]+(1-k[i]-e[i])/num*sumA)/(1.0-(1.0-k[i]-e[i])/num*sumB);
//     B[i]=(1.0-k[i]-e[i])/num/(1.0-(1.0-k[i]-e[i])/num*sumB);
//     C[i]=((1.0-k[i]-e[i])+(1.0-k[i]-e[i])/num*sumC)/(1.0-(1.0-k[i]-e[i])/num*sumB);
    
// }
int dp[maxn],a[maxn],n;
int dp2[maxn],b[maxn];
int tmp1[maxn],tmp2[maxn];
int main(){
    while(cin>>n){
        rep(i,1,n) b[i]=a[i]=read();
        reverse(b+1,b+1+n);
        memset(dp,0x3f,sizeof dp);
        memset(dp2,0x3f,sizeof dp2);
        int len=1;
        rep(i,1,n){
            int pos=lower_bound(dp+1,dp+n,a[i])-dp;
            dp[pos]=a[i];
            len=max(len,pos);
            tmp1[i]=pos;
            // cout<<i<<" "<<pos<<" "<<len<<endl;
        }
        // cout<<"www"<<endl;
        len=1;
        rep(i,1,n){
            int pos=lower_bound(dp2+1,dp2+1+n,b[i])-dp2;
            dp2[pos]=b[i];
            len=max(len,pos);
            tmp2[i]=pos;
            // cout<<i<<" "<<pos<<" "<<len<<endl;
        }
        int ans=-oo;
        rep(i,1,n){
            ans=max(min(tmp1[i],tmp2[n-i+1])*2-1,ans);
        }
        println(ans);
    }
    return 0;
}