#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iter(i,j) for(int i=0;i<(j).size();i++)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 1e6+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
double dp[MAXN];
int p[MAXN];
int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
int main(){
    while(cin>>n>>m){//[n,...]fin
        if(n==0&&m==0) break;
        rep(i,0,n+6) p[i]=i;
        rep(i,1,m){
            int u=read();
            int v=read();
            p[u]=v;
        }
        memset(dp,0,sizeof dp);
        rrep(i,n-1,0){
            double tmp=0;
            rep(j,1,6){
                int t=i+j;
                t=find(t);
                tmp+=dp[t];
            }
            dp[i]=1.0+tmp/6.0;
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}