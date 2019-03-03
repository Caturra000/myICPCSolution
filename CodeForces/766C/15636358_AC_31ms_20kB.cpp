#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e3 + 11;
const int MOD = 1e9+7;
typedef long long ll;
ll read(){
    ll x=0, f=1; register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[221];
int dp[3][MAXN];
char str[MAXN];
int n;
int main(){
    while(cin>>n){
        memset(dp[0],0,sizeof dp[0]);
        memset(dp[1],0x80,sizeof dp[1]);
        memset(dp[2],0x3f,sizeof dp[2]);
        scanf("%s",str+1);
        rep(i,0,25) a[i]=read();
        dp[0][0]=1;
        dp[2][0]=0;
        rep(i,1,n){
            int len=a[str[i]-'a'];
            rrep(j,i,1){
                len=min(len,a[str[j]-'a']);
                if(i-j+1>len) break;
                dp[0][i]=(dp[0][i]+dp[0][j-1])%MOD;
                dp[1][i]=max(dp[1][i],dp[1][j-1]);
                dp[1][i]=max(dp[1][i],i-j+1);
                dp[2][i]=min(dp[2][i],dp[2][j-1]+1);
            }
        }
        rep(i,0,2) println(dp[i][n]);
    }
    return 0;
}