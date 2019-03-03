#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
using namespace std;
typedef long long ll;
const int maxn  = 1e6+11;
int n,V,t,a,b;
ll dp[maxn];
int C[maxn],W[maxn];
bool flag[maxn];
void _01(int C,int W){
    rrep(v,V,C){
        dp[v]=max(dp[v],dp[v-C]+W);
    }
}
void _oo(int C,int W){
    rep(v,C,V){
        dp[v]=max(dp[v],dp[v-C]+W);
    }
}
int main(){
    while(scanf("%d%d",&n,&V)!=EOF){
        rep(i,1,n){
            scanf("%d%d%d",&t,&a,&b);
            C[i]=b,W[i]=a;flag[i]=t-1;
        }
        memset(dp,0,sizeof dp);
        rep(i,1,n){
            if(flag[i]) _01(C[i],W[i]);
            else _oo(C[i],W[i]);
        }
        printf("%lld\n",dp[V]);
    }
    return 0;
}