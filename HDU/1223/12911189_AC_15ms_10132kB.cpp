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
const int maxn = 1e3+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read()
{
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct BigInt{
	const static int mod = 10000;
	const static int DLEN = 4;
	int a[600],len;
	BigInt(){
		memset(a,0,sizeof(a));
		len = 1;
	}
	BigInt(int v){
		memset(a,0,sizeof(a));
		len = 0;
		do{
			a[len++] = v%mod;
			v /= mod;
		}while(v);
	}
	BigInt(const char s[]){
		memset(a,0,sizeof(a));
		int L = strlen(s);
		len = L/DLEN;
		if(L%DLEN)len++;
		int index = 0;
		for(int i = L-1;i >= 0;i -= DLEN){
			int t = 0;
			int k = i - DLEN + 1;
			if(k < 0)k = 0;
			for(int j = k;j <= i;j++)
				t = t*10 + s[j] - '0';
			a[index++] = t;
		}
	}
	BigInt operator +(const BigInt &b)const{
		BigInt res;
		res.len = max(len,b.len);
		for(int i = 0;i <= res.len;i++)
			res.a[i] = 0;
		for(int i = 0;i < res.len;i++){
			res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
			res.a[i+1] += res.a[i]/mod;
			res.a[i] %= mod;
		}
		if(res.a[res.len] > 0)res.len++;
		return res;
	}
	BigInt operator *(const BigInt &b)const{
		BigInt res;
		for(int i = 0; i < len;i++){
			int up = 0;
			for(int j = 0;j < b.len;j++){
				int temp = a[i]*b.a[j] + res.a[i+j] + up;
				res.a[i+j] = temp%mod;
				up = temp/mod;
			}
			if(up != 0)
				res.a[i + b.len] = up;
		}
		res.len = len + b.len;
		while(res.a[res.len - 1] == 0 &&res.len > 1)res.len--;
		return res;
	}
	void output(){
		printf("%d",a[len-1]);
		for(int i = len-2;i >=0 ;i--)
			printf("%04d",a[i]);
		printf("\n");
	}
};
BigInt dp[60][60],UNIT(1);
int main(){
	dp[1][1]=UNIT;
	rep(i,2,50)rep(j,1,i) dp[i][j]=dp[i-1][j-1]*j+dp[i-1][j]*j;
	int T=read();
	while(T--){
		int n=read();
		BigInt ans(0);
		rep(i,1,n) ans=ans+dp[n][i];
		ans.output();
	}
	return 0;
}