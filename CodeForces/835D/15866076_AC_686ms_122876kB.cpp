#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 5e3+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
const int MOD = 1e9+7;
ll read(){
   ll x=0,f=1;register char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
int ans[MAXN];
char str[MAXN];
int dp[MAXN][MAXN];
bool p[MAXN][MAXN];
int main(){
    while(~scanf("%s",str+1)){
        memset(ans,0,sizeof ans);
        memset(dp,0,sizeof dp);
        memset(p,0,sizeof p);
        int n=strlen(str+1);
        rep(i,1,n) dp[i][i]=p[i][i]=p[i][i-1]=p[i][i+1]=p[i-1][i]=1;
        ans[1]=n;
        rep(len,2,n){
            rep(l,1,n-len+1){
                int r=l+len-1;
                p[l][r]=p[l+1][r-1]&&str[l]==str[r];
                if(p[l][r]) dp[l][r]=dp[l][(l+r-1)/2]+1;
                if(dp[l][r]) ans[dp[l][r]]++;
            }
        }
        rrep(i,n,1) ans[i]+=ans[i+1]; 
        rep(i,1,n){
            if(i==n) println(ans[i]);
            else printbk(ans[i]);
        }
    }
    return 0;
}