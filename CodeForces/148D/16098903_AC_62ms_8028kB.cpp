#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#include<unordered_map>
#define rep(i,j,k) for( int i=j;i<=k;i++)
#define rrep(i,j,k) for( int i=j;i>=k;i--)
#define erep(i,u) for( int i=head[u];~i;i=nxt[i])
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
const int MAXN = 1e3+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
using ll = long long;
using P  = pair<ll,ll>;
int w,b;
double dp[MAXN][MAXN];
double DP(int w,int b){
    if(w<=0) return 0;
    if(b<=0) return 1;
    if(dp[w][b]>-1) return dp[w][b];
    double W=w,B=b;
    double ans=W/(W+B);// diyilun zhijie na
    if(w+b>=3) ans=ans+B/(W+B)*(B-1)/(W+B-1)*( (B-2)/(W+B-2)*DP(w,b-3) + W/(W+B-2)*DP(w-1,b-2) ); // dierlun longnaheishu (liuchuheishu / baishu)
    return dp[w][b]=ans;
}
int main(){
    fastIO;
    while(cin>>w>>b){
        for(int i=0;i<=w;i++) for(int j=0;j<=b;j++) dp[i][j]=-3;
        cout<<fixed<<setprecision(12)<<(DP(w,b))<<endl;
    }
    return 0;
}