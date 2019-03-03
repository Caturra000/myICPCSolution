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
const double eps = 1e-7;
typedef long long ll;
const int oo = 0x3f3f3f3f;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
stack<int> stk1,stk2;
ll sum[maxn],maxsum[maxn];
int main(){
    int Q,op,x,k;
    char str[50];
    while(~iin(Q)){
        while(!stk1.empty())stk1.pop();
        while(!stk2.empty())stk2.pop();
        memset(sum,0,sizeof sum);
        memset(maxsum,0x80,sizeof maxsum);
        rep(i,1,Q){
            s0(str);
            if(str[0]=='I'){
                x=read();
                stk1.push(x);
                int size=stk1.size();
                sum[size]=sum[size-1]+x;
                maxsum[size]=max(sum[size],maxsum[size-1]);
            }else if(str[0]=='D'){
                stk1.pop();
            }else if(str[0]=='L'){
                if(stk1.empty())continue;
                int t=stk1.top();
                stk2.push(t);
                stk1.pop();
            }else if(str[0]=='R'){
                if(stk2.empty())continue;
                int t=stk2.top();
                stk1.push(t);
                stk2.pop();
                int size=stk1.size();
                sum[size]=sum[size-1]+t;
                maxsum[size]=max(sum[size],maxsum[size-1]);
            }else{
                k=read();
                println(maxsum[k]);
            }
        }
    }
    return 0;
}