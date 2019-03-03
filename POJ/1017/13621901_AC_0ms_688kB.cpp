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
const int MAXN = 1e5+11;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
typedef long long ll;
const ll MOD = 1e9+7; 
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[66];
int main(){
	while(cin>>a[1]){
		rep(i,2,6)a[i]=read();
		ll sum=0; rep(i,1,6)sum+=a[i];
		if(sum==0)break;
		sum=0;
		sum+=a[6];
		sum+=a[5];a[1]-=11*a[5];
		sum+=a[4];a[2]-=5*a[4];if(a[2]<0)a[1]+=4*a[2];
		double tmp=a[3];int tmp2=max(EPS,ceil(tmp/4-EPS)+EPS);
		sum+=tmp2;a[3]%=4;
		if(a[3]>0){
			int area=36-9*a[3];
			a[2]=max(0,a[2]);
			if(area==27){
				a[2]-=5;
				a[1]-=7-(a[2]<0?4*a[2]:0);
			}else if(area==18){
				a[2]-=3;
				a[1]-=6-(a[2]<0?4*a[2]:0);
			}else if(area==9){
				a[2]-=1;
				a[1]-=5-(a[2]<0?4*a[2]:0);
			}
//			while(1){
//				if(a[2]<=0)break;
//				if(area<=3)break;
//				a[2]--;area-=4;
//			}
//			while(1){
//				if(a[1]<=0)break;
//				if(area<=0)break;
//				a[1]--;area-=1;
//			}
		}
		if(a[2]>0){
			tmp=a[2];tmp2=max(EPS,ceil(tmp/9-EPS)+EPS);
			sum+=tmp2;
			a[2]%=9;
			if(a[2]>0){
				int area=36-4*a[2];
				while(1){
					if(a[1]<=0)break;
					if(area<=0)break;
					a[1]--;area-=1;
				}
			}
		}
		if(a[1]>0) sum+=max(0.0,ceil(1.0*a[1]/36-EPS)+EPS);
//		rep(i,1,6)cout<<a[i]<<" ";cout<<endl;
		println(sum); 
	}
	return 0;
}