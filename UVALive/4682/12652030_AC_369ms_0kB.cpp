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
const int maxn = 1e6+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Trie{
    int son[maxn<<2][2];
    int b[67],tot;
    void init(){
//      memset(son,0,sizeof son);
        tot=0;
        son[0][0]=son[0][1]=0;
    }
    void insert(ll x){
        int now=0;
        rep(i,0,32) b[i]=(x>>i)&1;
        rrep(i,32,0){
            if(!son[now][b[i]]){
                son[now][b[i]]=++tot;
                son[tot][0]=son[tot][1]=0;
            }
            now=son[now][b[i]];
        }
    }
    ll find(ll x){
        int now=0;
        ll  ans=0;
        rep(i,0,32) b[i]=(x>>i)&1;
        rrep(i,32,0){
            if(son[now][b[i]^1]){
                now=son[now][b[i]^1];
                ans+=1ll<<i;
            }else{
                now=son[now][b[i]];
            }
        }
        return ans;
    }
}trie;
ll a[maxn];
int main(){
    int T=read();
    while(T--){
        int n=read();
        rep(i,1,n) a[i]=read();
        rep(i,2,n) a[i]^=a[i-1];
        trie.init();
        rep(i,1,n) trie.insert(a[i]);
        ll ans=-oo;
        rep(i,0,n) ans=max(ans,trie.find(a[i]));
        println(ans);
    }
    return 0;
}