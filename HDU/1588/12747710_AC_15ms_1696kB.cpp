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
ll k,b,n,m;
struct Matrix{
    ll mt[11][11],r,c;
    void init(int rr,int cc,bool flag=0){
        r=rr;c=cc;
        memset(mt,0,sizeof mt);
        if(flag) rep(i,1,r) mt[i][i]=1;
    }
    Matrix operator * (Matrix rhs){
        Matrix ans; ans.init(r,rhs.c);
        rep(i,1,r){
            rep(j,1,rhs.c){
                int t=max(r,rhs.c);
                rep(k,1,t){
                    ans.mt[i][j]+=(mt[i][k]*rhs.mt[k][j])%m;
                    ans.mt[i][j]=(ans.mt[i][j])%m;
                }
            }
        }
        return ans;
    }
    void out(){
    	rep(i,1,r){
    		rep(j,1,c){
    			cout<<mt[i][j]<<" ";
			}
			cout<<endl;
		}
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
int bas[3][3]={
	{0,0,0},
	{0,1,1},
	{0,1,0}
};
int bas2[3]={0,1,0};
int main(){
	Matrix A; A.init(2,2);
	rep(i,1,2)rep(j,1,2) A.mt[i][j]=bas[i][j];
	Matrix C; C.init(2,1);
	rep(i,1,2) C.mt[i][1]=bas2[i];
	while(cin>>k>>b>>n>>m){
		Matrix Ak=fpw(A,k);
		Matrix Ab=fpw(A,b);
		Matrix UNIT; UNIT.init(2,2,1);
		Matrix B; B.init(4,4);	
		rep(i,1,2)rep(j,1,2) B.mt[i][j]=Ak.mt[i][j];
		rep(i,1,2)rep(j,3,4) B.mt[i][j]=UNIT.mt[i][j-2];
		rep(i,3,4)rep(j,3,4) B.mt[i][j]=UNIT.mt[i-2][j-2];
		Matrix res=fpw(B,n);
		B.init(2,2); 
		rep(i,1,2) rep(j,1,2) B.mt[i][j]=res.mt[i][j+2];
		res=Ab*B*C;
		println(res.mt[2][1]);
	}
	return 0;
}