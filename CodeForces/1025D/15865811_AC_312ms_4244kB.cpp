#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
typedef long long ll;
using namespace std;
const int MAXN = 1e3+11;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll ooo= 0x3f3f3f3f;
const int MOD = 1e9+7;
ll read(){
   ll x=0,f=1;register char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   return x*f;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
bool ok[MAXN][MAXN],L[MAXN][MAXN],R[MAXN][MAXN],can[MAXN][MAXN];
int a[MAXN],n;
int main(){
    while(cin>>n){
        memset(L,0,sizeof L);
        memset(R,0,sizeof R);
        memset(ok,0,sizeof ok);
        rep(i,1,n) a[i]=read();
        rep(i,1,n) rep(j,i+1,n){
            if(gcd(a[i],a[j])>1){
                can[i][j]=can[j][i]=1;
            }else{
                can[i][j]=can[j][i]=0;
            }
        }
        rep(i,1,n) ok[i][i]=L[i][i]=R[i][i]=1;
        rep(len,1,n){
            rep(l,1,n-len+1){
                int r=l+len-1;
                rep(rt,l,r){
                    if(L[l][rt]&&R[rt][r]){
                        ok[l][r]=1;
                        if(can[rt][l-1]) R[l-1][r]=1;
                        if(can[rt][r+1]) L[l][r+1]=1;
                    }
                }
            }
        }
        if(ok[1][n]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}