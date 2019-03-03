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
int MOD = 9973;
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
ll fpw(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=mod(ans*mod(a));
		n>>=1;
		a=mod(mod(a)*mod(a));
	}
	return mod(ans);
}
// 4 7 -> 9绉?->O fff_(m|f) fmf_(m|f) fff fmf
//dp[1][i]:fff dp[1][i+1]=0dp[1][i]+0dp[2][i] 0
//dp[2][i]:mff dp[2][i+1]=dp[3][i]+dp[5][i] 2
//dp[3][i]:fmf dp[3][i+1]=0dp[4][i]+0dp[6][i] 0
//dp[4][i]:ffm dp[4][i+1]=dp[1][i]+dp[2][i] 1
//dp[5][i]:mmf dp[5][i+1]=dp[7][i]+dp[8][i] 4
//dp[6][i]:mfm dp[6][i+1]=dp[3][i]+dp[5][i] 2
//dp[7][i]:fmm dp[7][i+1]=dp[4][i]+dp[6][i] 2
//dp[8][i]:mmm dp[8][i+1]=dp[7][i]+dp[8][i] 4
//dp[i][j]:j缁撳熬绗﹀悎O-鏉′欢鐨勬柟妗堟暟 
int bas[9][9]={
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,1,0,0,0},
	{0,0,0,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,1,1},
};
int bas2[9]={0,0,2,0,1,4,2,2,4}; 
int main(){
	int n,m;
	Matrix A;A.init(8,8);
	rep(i,1,8) rep(j,1,8) A.mt[i][j]=bas[i][j];
	Matrix b; b.init(8,1);
	rep(i,1,8) b.mt[i][1]=bas2[i];
	while(cin>>n>>m){
		MOD=m;
		if(n<=4){
			switch(n){
				case 0 :println(0%MOD);break;
				case 1 :println(2%MOD);break;
				case 2 :println(4%MOD);break;
				case 3 :println(6%MOD);break;
				case 4 :println(9%MOD);break; 
			} 
			continue;
		}
		Matrix res=fpw(A,n-5); res=res*b;
		ll ans=0;
//		rep(i,1,8) cout<<res.mt[i][1]<<" ";cout<<endl;
		rep(i,1,8) ans=mod(ans+res.mt[i][1]+m);
		println(ans);
	}
	return 0;
}
