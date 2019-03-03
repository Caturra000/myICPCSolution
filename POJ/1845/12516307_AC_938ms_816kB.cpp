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
const int MOD = 9901;
const double eps = 1e-7;
typedef long long ll;
typedef pair<int,int> P;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline int mod(ll a){
	return a%MOD;
}
int fpw(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=mod(ans*a);
		a=mod(a*a);
		n>>=1; 
	}
	return mod(ans);
	
}
int sum(int p,int n){
	if(n==0)return 1;
	if(n&1) return mod(mod(1+fpw(p,n+1>>1))*mod(sum(p,n-1>>1)));
	else return mod(mod(1+fpw(p,n>>1))*mod(sum(p,(n>>1)-1))+mod(fpw(p,n)));
}
ll n,cnt;
ll prime[maxn],num[maxn];
void chai(ll a){
    cnt=0;
    memset(num,0,sizeof num);
    memset(prime,0,sizeof prime);
    for(ll i = 2; i <= a; i++){
        if(a%i==0){
            cnt++;
            prime[cnt]=i;num[cnt]++;
            a/=i;
            while(a%i==0){
                num[cnt]++;
                a/=i;
            }
        }
    }
    // if(a>1){
    //     cnt++;
    //     prime[cnt]=cnt;
    //     num[cnt]=1;
    // }
}
int main(){
	ll a,b;
	while(~lin(a)){
		b=read();
		chai(a);
		rep(i,1,cnt) num[i]*=b;
//		rep(i,1,cnt) cout<<i<<" "<<prime[i]<<" "<<num[i]<<endl;
		ll ans=1;
		rep(i,1,cnt){
			int tmp=sum(prime[i],num[i]);
			ans=mod(ans*mod(tmp));
		}
		println(ans);
	}
	return 0;
}