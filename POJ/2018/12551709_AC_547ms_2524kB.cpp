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
int n,L;
double a[maxn],b[maxn],c[maxn];
bool C(double x){
	rep(i,1,n) b[i]=a[i]-x;
	rep(i,1,n) c[i]=c[i-1]+b[i];
	double ans=-1e12;
	double mn=1e12;
	rep(i,L,n){
		mn=min(mn,c[i-L]);
		ans=max(ans,c[i]-mn);
	}
	return ans>=0;
} 
int main(){
	while(~iin(n)){
		iin(L);
		rep(i,1,n) din(a[i]);
		double l=-1e6,r=1e6;
		while(r-l>1e-5){
			double mid=(l+r)/2;
			if(C(mid)) l=mid;
			else r=mid;
		}
		printf("%lld\n",(ll)(r*1000));
	}
	return 0;
} 