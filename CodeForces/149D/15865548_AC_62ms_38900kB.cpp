#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 732+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
const int MOD = 1e9+7;
ll read(){
   ll x=0,f=1;register char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
ll dp[MAXN][MAXN][3][3];
int match[MAXN];
char str[MAXN];
void DP(int l,int r){
    if(l==r){
        rep(i,0,2) rep(j,0,2) dp[l][r][i][j]=0;
        return;
    }
    if(l+1==r){
        dp[l][r][0][0]=0;
        dp[l][r][1][1]=0;
        dp[l][r][2][2]=0;
        dp[l][r][1][2]=0;
        dp[l][r][2][1]=0;
        
        
        dp[l][r][1][0]=1;
        dp[l][r][0][1]=1;
        dp[l][r][2][0]=1;
        dp[l][r][0][2]=1;
    }else if(match[l]==r){
        DP(l+1,r-1);
        rep(i,0,2) rep(j,0,2) dp[l][r][i][j]=0; 
        rep(i,0,2) rep(j,0,2){ // i==j ok/ err 0
            if(j!=1) dp[l][r][0][1]+=dp[l+1][r-1][i][j];
            if(j!=2) dp[l][r][0][2]+=dp[l+1][r-1][i][j];
            if(i!=1) dp[l][r][1][0]+=dp[l+1][r-1][i][j];
            if(i!=2) dp[l][r][2][0]+=dp[l+1][r-1][i][j];
            rep(x,0,2) rep(y,0,2){
                if(dp[l][r][x][y]>=MOD) dp[l][r][x][y]%=MOD;
            }
        }
    }else{
        DP(l,match[l]); DP(match[l]+1,r);
        rep(i,0,2) rep(j,0,2) dp[l][r][i][j]=0;
        rep(i,0,2) rep(j,0,2) rep(x,0,2) rep(y,0,2)if((x==y&&x==0)||(x!=y)){
            dp[l][r][i][j]+=dp[l][match[l]][i][x]*dp[match[l]+1][r][y][j]%MOD;
            if(dp[l][r][i][j]>=MOD) dp[l][r][i][j]%=MOD;
        }
    }
} 
int main(){
    while(~scanf("%s",str+1)){
        memset(dp,-1,sizeof dp);
        stack<int> stk;
        int n=strlen(str+1);
        rep(i,1,n){
            if(str[i]=='(') stk.push(i);
            else{
                int pos=stk.top();stk.pop();
                match[pos]=i;
            }
        }
        DP(1,n);
        ll res=0;
        rep(i,0,2) rep(j,0,2) res=(res+dp[1][n][i][j])%MOD;
        println(res);
    }
    return 0;
}