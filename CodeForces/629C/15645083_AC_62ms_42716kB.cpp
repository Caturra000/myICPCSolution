#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 1e5 + 11;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0, f=1; register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll dp[2333][2333];
char str[MAXN];
int n,m;
int main(){
    dp[0][0]=1;
    rep(i,1,2018){
        dp[i][0]=dp[i-1][1];
        rep(j,1,i){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;//+'('和+')'
        }
    }
    while(cin>>n>>m){
        scanf("%s",str+1);
        int prea=0,preb=0,valid=INF;
        rep(i,1,m){
            if(str[i]=='(') prea++;
            else preb++;
            valid=min(valid,prea-preb);//保证后期枚举左边随时合法
        }
        ll ans=0;
        rep(i,0,n-m){
            rrep(j,n-m,0){
                int k=j+prea-preb;
                if(j<-valid) break;
                if(k>n-m-i) continue; //保证右边合法
                ans=ans+dp[i][j]*dp[n-m-i][k]%MOD;
                if(ans>=MOD) ans%=MOD;
            }
        }
        println(ans);
    }
    return 0;
}