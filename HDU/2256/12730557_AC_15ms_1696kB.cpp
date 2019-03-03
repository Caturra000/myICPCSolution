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
const ll MOD = 1024;
inline ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline ll mod(ll a){return a%MOD;}
struct Matrix{
	ll mt[22][22],r,c;
	void init(int rr,int cc,bool flag=0){
		r=rr;c=cc;
		memset(mt,0,sizeof mt);
		if(flag) rep(i,1,r) mt[i][i]=1;
	}
	Matrix operator * (const Matrix &rhs)const{
		Matrix ans; ans.init(r,rhs.c);
		rep(i,1,r){
			rep(j,1,rhs.c){
				int t=max(r,rhs.c);
				rep(k,1,t){
					ans.mt[i][j]+=mod(mt[i][k]*rhs.mt[k][j]);
					ans.mt[i][j]=mod(ans.mt[i][j]);
				}
			}
		}
		return ans;
	}
};
Matrix fpw(Matrix A,int n){
	Matrix ans;ans.init(A.r,A.c,1);
	while(n){
		if(n&1) ans=ans*A;
		n>>=1;
		A=A*A;
	}
	return ans;
}

int bas[3][3]={
	{0,0,0},
	{0,5,12},
	{0,2,5},
};
int bas2[]={0,5,2}; 
int main(){
	Matrix A;A.init(2,2);
	rep(i,1,2) rep(j,1,2) A.mt[i][j]=bas[i][j];
	Matrix b; b.init(2,1);
	rep(i,1,2) b.mt[i][1]=bas2[i];
	int T=read();
	while(T--){
		int n=read();
		Matrix res=fpw(A,n-1); res=res*b;
		ll ans=mod(2*res.mt[1][1]-1+MOD);
		println(ans);
	}
	return 0;
}
