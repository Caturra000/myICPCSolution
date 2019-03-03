#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define erep(i,u) for(int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 1.5e3+11;
const int MOD = 1e9+7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char str[MAXN];
short dp[MAXN][MAXN][28];//dp[i][j][k]:i到j全部变成k的最少代价 
short ans[MAXN][28],n;
int main(){
    while(cin>>n){
        rep(i,1,n) rep(j,1,n) rep(k,0,25) dp[i][j][k]=1<<14;
        scanf("%s",str+1);
        int m=read();
        rep(i,1,n){
            rep(j,0,25){
                if(j==str[i]-'a') dp[i][i][j]=0;
                else dp[i][i][j]=1;
            }
        }
        rep(i,1,n){
            rep(j,i+1,n){
                rep(k,0,25){
                    dp[i][j][k]=dp[i][j][k]>dp[i][j-1][k]+bool(str[j]-'a'!=k)?dp[i][j-1][k]+bool(str[j]-'a'!=k):dp[i][j][k];
                }
            }
        }
        //zuiduogaizhemeduo zifu = ans
        memset(ans,0,sizeof ans);
        rep(i,1,n){
            rep(j,i,n){
                rep(k,0,25){
                    ans[dp[i][j][k]][k]=ans[dp[i][j][k]][k]>j-i+1?ans[dp[i][j][k]][k]:j-i+1;
                }
            }
        }
        rep(i,1,n) rep(k,0,25) ans[i][k]=max(ans[i-1][k],ans[i][k]);
        rep(i,1,m){
            int num=read();
            scanf("%s",str);
            int ch=str[0]-'a';
            println(ans[num][ch]);
        }
    }
    return 0;
} 