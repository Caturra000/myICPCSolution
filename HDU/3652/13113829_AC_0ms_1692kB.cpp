#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;
const int maxn = 20;
typedef long long ll;
int a[maxn];
ll r,dp[maxn][2][2][13];
ll DP(int cur,int pre,int ok,int mod,int limit){
    if(cur==0&&ok&&mod==0) return 1;
    if(!limit&&dp[cur][pre][ok][mod]!=-1) return dp[cur][pre][ok][mod];
    else if(cur==0) return 0;
    int up=(limit?a[cur]:9);
    ll ans=0;
    rep(i,0,up){
        if(pre&&i==3)ans+=DP(cur-1,0,1,(mod*10+i)%13,limit&&a[cur]==i);
        else ans+=DP(cur-1,i==1,ok,(mod*10+i)%13,limit&&a[cur]==i);
    }
    return limit?ans:dp[cur][pre][ok][mod]=ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    while(~scanf("%lld",&r)){
        int cur=0;
        while(r){
            a[++cur]=r%10;
            r/=10;
        }
        printf("%lld\n",DP(cur,0,0,0,1));
    }
    return 0;
}