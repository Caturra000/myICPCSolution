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
const int MAXN = 1e6+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
ll read() {
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int cnt[MAXN],a[MAXN];
void sai(int m) {
    rrep(i,m,1) {
        int t=cnt[i];
        for(int j=2*i;j<=m;j+=i) {
            cnt[j]+=t;
        }
    }
}
int main() {
    int n,m;
    while(cin>>n>>m) {
        memset(cnt,0,sizeof cnt);
        rep(i,1,n) a[i]=read();
        rep(i,1,n) {
            if(a[i]<=m) {
                cnt[a[i]]++;
            }
        }
        sai(m);
        int ans=0,lcm=0;
        for(int i=1;i<=m;i++) {
            if(ans<cnt[i]) {
                ans=cnt[i];
                lcm=i;
            }
        }
        if(lcm==0){
            printf("1 0\n\n");
            continue;
        }
        printf("%d %d\n",lcm,ans);
        bool flag=0;
        for(int i=1;i<=n;i++) {
            if(lcm%a[i]==0) {
                if(flag) printf(" %d",i);
                else flag=1,printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}