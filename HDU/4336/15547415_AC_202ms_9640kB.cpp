#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 2e6+11;
double p[233];
double dp[MAXN];
int n;
int main(){
    while(cin>>n){
        rep(i,1,n) scanf("%lf",&p[i]);
        int S=1<<n;--S; dp[S]=0;
        for(int i=S-1;i>=0;--i){//S-1!!!!
            double x=0;
            double y=0;
            for(int j=0;j<n;j++){
                if(i>>j&1) continue;
                y+=dp[i|(1<<j)]*p[j+1];
                x+=p[j+1];
            }
            dp[i]=(1.0+y)/x;
        }
        printf("%.12lf\n",dp[0]);
    }
    return 0;
}