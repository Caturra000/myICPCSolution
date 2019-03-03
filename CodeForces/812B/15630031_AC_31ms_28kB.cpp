#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
using namespace std;
const int MAXN = 1e6 + 11;
const int MOD = 1ll<<30;
typedef long long ll;
const ll INF = 1ll<<62;
ll read(){
    ll x = 0, f = 1; register char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x*f;
}
int dp[23][2],n,m;
char str[23][333];
int main(){
    while(cin>>n>>m){
        rep(i,1,n) scanf("%s",str[n-i+1]+1);
        int t=n;
        rrep(i,n,1){
            bool flag=0; 
            rep(j,1,m+2) if(str[i][j]=='1') flag=1;
            if(flag==0) t--;
            else break; 
        }
        n=t;
        if(t==0){
            println(0);
            continue;
        }
        dp[1][0]=0;dp[1][1]=m+1;
        if(n==1){
            int leftmax=1;
            rep(j,2,m+1) if(str[1][j]=='1') leftmax=j;
            println(leftmax-1);
            continue;
        }
        rep(i,2,n){
            int leftmax=1,rightmax=m+2;
            rep(j,2,m+1) if(str[i-1][j]=='1') leftmax=j;
            rrep(j,m+1,2) if(str[i-1][j]=='1') rightmax=j;
            if(i!=2) dp[i][0]=min(dp[i-1][0]+2*(leftmax-1)+1,dp[i-1][1]+m+2);
            else dp[i][0]=min(dp[i-1][0]+2*(leftmax-1)+1,2*(m+2)-1);
            if(i!=2) dp[i][1]=min(dp[i-1][0]+m+2,dp[i-1][1]+2*(m+2-rightmax)+1);
            else dp[i][1]=m+2;
        }
        int leftmax=1,rightmax=m+2;
        rep(j,2,m+1) if(str[n][j]=='1') leftmax=j;
        rrep(j,m+1,2) if(str[n][j]=='1') rightmax=j;
        int ans=min(dp[n][0]+(leftmax-1),dp[n][1]+(m+2-rightmax));
        println(ans);
    }
    return 0;
}