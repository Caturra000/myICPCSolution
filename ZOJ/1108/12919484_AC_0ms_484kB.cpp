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
const int maxn = 1e4+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,dp[maxn],pre[maxn],aa,bb;
struct A{
	int fat,speed,pos;
}a[maxn];
bool cmp(A a,A b){
	return a.fat<b.fat;
}
int main(){
	while(cin>>aa>>bb){
		a[++n].fat=aa;
		a[n].speed=bb;
		a[n].pos=n;
	}
	sort(a+1,a+1+n,cmp);
	rep(i,1,n) dp[i]=1;
	rep(i,1,n){
		rep(j,1,i-1){
			if(a[i].fat>a[j].fat&&a[i].speed<a[j].speed){
				if(dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
					pre[i]=j;
				}
			}
		}
	}
	ll ans=1,st=1;
	rrep(i,n,1) if(dp[i]>ans){
		ans=dp[i];
		st=i;
	}
	println(ans);
	stack<int> stk;
	while(st){
		stk.push(st);
		st=pre[st];
	} 
	while(!stk.empty()){
		println(a[stk.top()].pos);
		stk.pop();
	}
	return 0;
}