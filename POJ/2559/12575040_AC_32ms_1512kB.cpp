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
int main(){
    int n,h[maxn],w[maxn];
    stack<int> stk;
    while(~iin(n)){
        if(n==0)break;
        rep(i,1,n) h[i]=read();
        while(!stk.empty()) stk.pop();
        h[n+1]=0;
        ll ans=0;
        rep(i,1,n+1){
            if(stk.empty()||stk.top()<h[i]){
                stk.push(h[i]);
                w[stk.size()]=1;
            }else{
                int width=0;
                while(!stk.empty()&&stk.top()>h[i]){
                    int t=stk.top();
                    width+=w[stk.size()];
                    stk.pop();
                    ans=max(ans,1ll*t*width);
                }
                stk.push(h[i]);
                w[stk.size()]=width+1;
            }
        }
        println(ans);
    }
    return 0;
}