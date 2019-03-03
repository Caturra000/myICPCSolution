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
const ll MOD = 200907;
inline ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline ll mod(ll a){return a%MOD;}
struct Matrix{
	short mt[111][111],r,c;
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
					ans.mt[i][j]+=(mt[i][k]&rhs.mt[k][j]);
					ans.mt[i][j]=ans.mt[i][j]&1;
				}
			}
		}
		return ans;
	}
};
Matrix fpw(Matrix A,ll n){
	Matrix ans;ans.init(A.r,A.c,1);
	while(n){
		if(n&1) ans=ans*A;
		n>>=1;
		A=A*A;
	}
	return ans;
}

int bas[4][4]={
	{0,0,0,0},
	{0,1,2,1},
	{0,1,0,0},
	{0,0,0,1}
};
int bas2[4]={0,2,1,1}; 
ll n;
char str[112];
int main(){
//	Matrix A;A.init(3,3);
//	rep(i,1,3) rep(j,1,3) A.mt[i][j]=bas[i][j];
//	Matrix b; b.init(3,1);
//	rep(i,1,3) b.mt[i][1]=bas2[i];
	while(~iin(n)){
		s1(str);
		int len = strlen(str+1);
		Matrix A; A.init(len,len);
		rep(i,2,len) A.mt[i][i-1]=A.mt[i][i]=1;
		A.mt[1][1]=A.mt[1][len]=1; 
		Matrix b; b.init(len,1);
		rep(i,1,len) b.mt[i][1]=str[i]-'0';
		Matrix res=fpw(A,n); res=res*b;
		rep(i,1,len) str[i]=res.mt[i][1]+'0';
		printf("%s\n",str+1);
	}
	return 0;
}
