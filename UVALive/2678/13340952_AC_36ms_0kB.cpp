#include<bits/stdc++.h>
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
const int maxn = 1e5+15;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
int n,s;
ll sum[maxn],a[maxn];
bool C(int len){
	for(int i=1;i+len-1<=n;i++){
		if(sum[i+len-1]-sum[i-1]>=s)return 1;
	}
	return 0;
}
int main(){
	while(cin>>n>>s){
		rep(i,1,n)scanf("%lld",&a[i]); 
		rep(i,1,n) sum[i]=sum[i-1]+a[i];
		int l=1,r=n,ans;
		while(l<r){
			int mid=l+(r-l)/2;
			if(C(mid))r=mid;
			else l=mid+1;
		}
		println((C(l)?l:0));
	}
	return 0;
} 