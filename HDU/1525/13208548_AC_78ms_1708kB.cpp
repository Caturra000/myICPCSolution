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
ll f[233],n,a,b;
int main(){
    while(cin>>a>>b){
        if(a==0&&b==0) break;
        if(a<b) swap(a,b);
        if(a==0){
            printf("Ollie wins\n");
            continue;
        }
        if((a%b==0)||(a%b!=0&&a/b>1)){
            printf("Stan wins\n");
            continue;
        }
        bool flag=0;
        while(1){
            if(a<b) swap(a,b);
            a=a-b;
            if(a<b) swap(a,b);
            if(a==0){
                printf("%s wins\n",flag?"Ollie":"Stan");
                break;
            }
            if((a%b==0)||(a%b!=0&&a/b>1)){
                printf("%s wins\n",flag==0?"Ollie":"Stan");
                break;
            }
            flag^=1;
        }
    }
    return 0;
}