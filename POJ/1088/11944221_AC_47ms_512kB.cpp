#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iterator>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define println(a) printf("%lld\n",a)
using namespace std;
const int maxn = 2e2+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
int R,C;
int G[maxn][maxn],dp[maxn][maxn];
bool ok(int i,int j){
    return i>=1&&i<=R&&j>=1&&j<=C;
}
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int DP(int i,int j){
    if(!ok(i,j)) return -oo;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxlen=1;
    rep(k,0,3){
        int x=i+dx[k],y=j+dy[k];
        if(ok(x,y)&&G[x][y]>G[i][j]) maxlen=max(maxlen,DP(x,y)+1);
    }
    return dp[i][j]=maxlen;
    
}
int main(){
    ios::sync_with_stdio(0);
    while(cin>>R>>C){
        rep(i,1,R) rep(j,1,C) cin>>G[i][j];
        memset(dp,-1,sizeof dp);
        // rep(i,1,R) rep(j,1,C) rep(k,0,3){
        //     int x=i+dx[k],y=j+dy[k];
        //     if(ok(x,y)&&G[x][y]>G[i][j]) dp[i][j]=max(dp[i][j],dp[x][y]+1);
        // }
        int ans=0;
        rep(i,1,R)rep(j,1,C)ans=max(ans,DP(i,j));
        cout<<ans<<endl;
    }
    return 0;
}