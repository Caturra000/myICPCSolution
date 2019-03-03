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
const int maxn = 1e5+11;
const double eps = 1e-7;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct A{
    int mn,mx;
}a[maxn];
struct B{
    int spf,cov;
}b[maxn];
bool cmp(A a,A b){
    if(a.mx!=b.mx) return a.mx<b.mx;
    return a.mn<b.mn;
}
bool cmp2(B a,B b){
    if(a.spf!=b.spf) return a.spf<b.spf;
    return a.cov>b.cov;
}
int main(){
    int C,L;
    while(~iin(C)){
        L=read();
        rep(i,1,C){
            a[i].mn=read();
            a[i].mx=read();
        }
        sort(a+1,a+C+1,cmp);
        rep(i,1,L){
            b[i].spf=read();
            b[i].cov=read();
        }
        sort(b+1,b+1+L,cmp2);
        int ans=0,now=1;
        // rep(i,1,C){
        //     while(1){
        //         if(now>L)break;
        //         if(b[now].cov>0&&b[now].spf>=a[i].mn&&b[now].spf<=a[i].mx){
        //             b[now].cov--;
        //             ans++;
        //             break;
        //         }else{
        //             now++;
        //         }
        //     }
        // }
        rep(i,1,C){
            rep(j,1,L){
                if(b[j].cov>0&&b[j].spf>=a[i].mn&&b[j].spf<=a[i].mx){
                    b[j].cov--;
                    ans++;
                    break;
                }
            }
        }
        println(ans);
    }
    return 0;
}