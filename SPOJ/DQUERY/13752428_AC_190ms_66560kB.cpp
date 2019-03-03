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
#include<bitset>
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
const int MAXN = 1e6+11;
const double EPS = 1e-7;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7; 
unsigned int SEED = 17;
const ll INF = 1ll<<60;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Node{
    int l,r,id;
}Q[MAXN];
ll a[MAXN],cnt[MAXN],pre[MAXN],pos[MAXN],ans[MAXN];
ll L,R,ANS,SIZE,n,m,k;
bool cmp(Node a,Node b){
    if(pos[a.l]!=pos[b.l]) return pos[a.l]<pos[b.l];
    return a.r<b.r;
}
inline void add(int cur){
    ANS+=cnt[a[cur]]==0?1:0;
    cnt[a[cur]]++;
}
inline void del(int cur){
    cnt[a[cur]]--;
    ANS-=cnt[a[cur]]==0?1:0;
}
int main(){
    while(cin>>n){
        memset(cnt,0,sizeof cnt);
        SIZE=sqrt(n);
        rep(i,1,n){
            a[i]=read();
            pos[i]=i/SIZE;
        }
        m=read();
        rep(i,1,m){
            Q[i].l=read();
            Q[i].r=read();
            Q[i].id=i;
        }
        sort(Q+1,Q+1+m,cmp);
        L=1; R=0; ANS=0;
        rep(i,1,m){
            while(L<Q[i].l){
                del(L);
                L++;
            }
            while(L>Q[i].l){
                L--;
                add(L);
            }
            while(R<Q[i].r){
                R++;
                add(R);
            }
            while(R>Q[i].r){
                del(R);
                R--;
            }
            ans[Q[i].id]=ANS;
        }
        rep(i,1,m) println(ans[i]);
    }
    return 0;
}