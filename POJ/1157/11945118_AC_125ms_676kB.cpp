#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,j,k) for(int i = j; i <= k; i++)
using namespace std;
const int maxn = 2e2+11;
const int oo = 0x3f3f3f3f;
int a[maxn][maxn],n,m;
long long dp[maxn][maxn];
int main(){
    while(cin>>n>>m){
        rep(i,1,n)rep(j,1,m)cin>>a[i][j];
        memset(dp,0,sizeof dp);
        rep(i,1,n)dp[i][i]=dp[i-1][i-1]+a[i][i];
        rep(i,1,n)rep(j,i+1,m) dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i][j-1]);
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
