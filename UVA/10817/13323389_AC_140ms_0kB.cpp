#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
int s,m,n,a[maxn],aa[maxn],b[maxn],bb[maxn];
bool vis[maxn];
ll dp[123][1<<8|1][1<<8|1];//m teachers S subjects 1person 2person
//shu zu tai da hui hen hao shi
ll DP(int cur,int S1,int S2){
    if(cur>m+n)return S2==(1<<s)-1?0:1ll<<33;
    if(~dp[cur][S1][S2]) return dp[cur][S1][S2];
    int all=(1<<s)-1;
    ll ans=1ll<<33;
    if(cur>m) ans=DP(cur+1,S1,S2);
    ans=min(ans,DP(cur+1,S1-(S1&b[cur])+(all&b[cur]),S2|(S1&b[cur]))+a[cur]);
    return dp[cur][S1][S2]=ans;
}
int main(){
    while(cin>>s>>m>>n){
        if(s==0) break;
        rep(i,1,m+n){
            scanf("%d",&a[i]);
            int t=0;char ch;
            while(ch=getchar()){
                if(ch>='0'&&ch<='9')t|=1<<(ch-'0'-1);
                else if(ch=='\n'||ch==EOF)break;
            }
            b[i]=t;
        }
        memset(dp,-1,sizeof dp);
        cout<<DP(0,0,0)<<endl;
    }
    return 0;
}
