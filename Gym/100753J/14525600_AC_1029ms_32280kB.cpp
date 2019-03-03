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
const int MAXN = 1e3+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int kind[MAXN],p[MAXN],s[MAXN];
ll dp[2][103][20003];//di i ge you j jinbi you k yinbi = zuiduode jinianpin
int main(){
    int g,c,n;
    string str;
    while(cin>>g>>c>>n){
        rep(i,1,n){
            cin>>str;
            if(str[1]=='e'){//generous
                kind[i]=0;
            }else if(str[0]=='h'){//honest
                kind[i]=1;
            }else{//greedy
                kind[i]=2;
            }
            p[i]=read();
            s[i]=read();
        }
        memset(dp,0x80,sizeof dp);
        int Limit=2e4+1;
        dp[0][c][0]=0;
        ll mx=0;
        rep(i,1,n){
            double tmp=1.0*(g-s[i])/p[i];
            int down=floor(tmp);
            int top=ceil(tmp);
            int real=round(tmp);
            down*=p[i];top*=p[i];real*=p[i];
            rep(j,0,c){
                rep(k,0,Limit){
                    
                    dp[i&1][j][k]=dp[i-1&1][j][k];
                    
                    if(kind[i]==0){
                        if(k-top<s[i]&&k-top>=0&&j+1<=c) dp[i&1][j][k]=max(dp[i&1][j][k],dp[i-1&1][j+1][k-top]+1);
                        else if(k+s[i]<=Limit) dp[i&1][j][k]=max(dp[i&1][j][k],dp[i-1&1][j][k+s[i]]+1);
                    }else{
                        if(kind[i]==1){
                            if(j+1<=c&&k-real>=0) dp[i&1][j][k]=max(dp[i&1][j][k],dp[i-1&1][j+1][k-real]+1);
                            if(k+s[i]<=Limit) dp[i&1][j][k]=max(dp[i&1][j][k],dp[i-1&1][j][k+s[i]]+1);
                        }else{
                            if(j+1<=c&&k-down>=0) dp[i&1][j][k]=max(dp[i&1][j][k],dp[i-1&1][j+1][k-down]+1);
                            if(k+s[i]<=Limit) dp[i&1][j][k]=max(dp[i&1][j][k],dp[i-1&1][j][k+s[i]]+1);
                        }
                    }
                }
            }
        }
        rep(j,0,c) rep(k,0,2e4) mx=max(mx,dp[n&1][j][k]);
        cout<<mx<<endl;
    }
    return 0;
}