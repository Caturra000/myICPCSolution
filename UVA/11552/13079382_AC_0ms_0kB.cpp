#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 1e4+11;
const double eps = 1e-10;
typedef long long ll;
const int oo = 0x3f3f3f3f;
const double ERR = -2.3333;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int dp[maxn][27];
char str[maxn];
int have[29],kind;
int main(){
    int T=read();
    while(T--){
        int k=read();
        s1(str);
        memset(dp,0x3f,sizeof dp);
        int n=strlen(str+1);
        int m=n/k;
        rep(i,1,m){
            int left=1+(i-1)*k,right=i*k;
            kind=0;memset(have,0,sizeof have);
            rep(j,left,right){
                have[str[j]-'a']++;
                if(have[str[j]-'a']==1) kind++;
            }
            if(i==1) rep(j,0,'z'-'a'){
                if(have[j]) dp[1][j]=kind;
            }
            if(i==1)continue;
            rep(j,0,'z'-'a'){
                if(!have[j])continue;
                rep(k,0,'z'-'a'){
                    if(j==k){
                        if(kind==1){
                            dp[i][j]=min(dp[i][j],dp[i-1][k]);//all j
                        }else{
                            dp[i][j]=min(dp[i][j],dp[i-1][k]+kind);
                        }
                    }else if(have[k]){
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+kind-1);
                    }else{
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+kind);
                    }
                }
            }
            
        }
        int ans=oo;
        rep(i,0,'z'-'a'){
            ans=min(ans,dp[m][i]);
        }
        println(ans);
    }
    return 0;
}