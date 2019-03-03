#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<bitset>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iter(i,j) for(int i=0;i<(j).size();i++)
#define print(a) printf("%lld",(ll)a)
#define println(a) printf("%lld\n",(ll)a)
#define printbk(a) printf("%lld ",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int MAXN = 3e4+11;
const int oo = 0x3f3f3f3f;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN][6],ra[MAXN][6];
bitset<MAXN> bs[MAXN][6],t;
int main(){
    int n;
    while(cin>>n){
        rep(i,0,n) rep(j,1,5) bs[i][j].reset();
        rep(i,1,n) rep(j,1,5) ra[a[i][j]=read()][j]=i;
        rep(i,2,n) rep(j,1,5){
            bs[i][j]=bs[i-1][j];
            bs[i][j][ra[i-1][j]]=1;
        }
        rep(i,1,n){
            t=bs[a[i][1]][1];
            rep(j,2,5) t&=bs[a[i][j]][j];
            println(t.count());
        }
    }
    return 0;
}