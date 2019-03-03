#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define print(a) printf("%lld",(ll)(a))
#define printbk(a) printf("%lld ",(ll)(a))
#define println(a) printf("%lld\n",(ll)(a))
using namespace std;
const int MAXN = 3e4+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
typedef unsigned long long ull;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const ull PRIME = 233333;
const int MOD = 1e9+7;
ull prime[MAXN];
char str[MAXN][233];
ull haxi[MAXN][233];
ull tmp[MAXN];
int n,m,l;
int main(){
    prime[0]=1; rep(i,1,233)prime[i]=prime[i-1]*PRIME;
    while(cin>>n>>m>>l){
        memset(haxi,0,sizeof haxi);
        rep(i,1,n){
            scanf("%s",str[i]+1);
        }
        rep(i,1,n){
            rep(j,1,m){
                haxi[i][j]=haxi[i][j-1]+(ll)str[i][j]*prime[m-j+1];
            }
        }
        ll res=0;
        rep(i,1,m){
            rep(j,1,n){
                tmp[j]=haxi[j][m]-haxi[j][i]+haxi[j][i-1];
            }
            sort(tmp+1,tmp+n+1);
            ll cnt=1;
            rep(j,2,n){
                if(tmp[j-1]==tmp[j]){
                    res+=cnt;
                    cnt++;
                }else{
                    cnt=1;
                }
            }
        }
        println(res);
    }
    return 0;
}