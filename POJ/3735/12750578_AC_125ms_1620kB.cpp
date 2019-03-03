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
struct Matrix{
    ll mt[110][110],r,c;
    void init(int rr,int cc,bool flag=0){
        r=rr;c=cc;
        memset(mt,0,sizeof mt);
        if(flag) rep(i,1,r) mt[i][i]=1;
    }
    Matrix operator * (Matrix rhs){
        Matrix ans; ans.init(r,rhs.c);
        int t=max(r,rhs.c);
        rep(k,1,t){
        	rep(i,1,r){
        		if(!mt[i][k]) continue;
            	rep(j,1,rhs.c){
                    ans.mt[i][j]+=(mt[i][k]*rhs.mt[k][j]);
                    ans.mt[i][j]=(ans.mt[i][j]);
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
ll n,m,k;
char str[6];
int main(){
	while(cin>>n>>m>>k){
		if(n==0&&m==0&&k==0)break;
		Matrix A; A.init(n+1,n+1,1);
		while(k--){
			s1(str);
			if(str[1]=='g'){
				int x=read();
				A.mt[x][n+1]++;
			}else if(str[1]=='s'){
				int x=read();
				int y=read();
				rep(i,1,n+1) swap(A.mt[x][i],A.mt[y][i]);
			}else{
				int x=read();
				rep(i,1,n+1) A.mt[x][i]=0;
			}
		}
		Matrix b; b.init(n+1,1);b.mt[n+1][1]=1;
		Matrix res=fpw(A,m)*b;
		rep(i,1,n){
			if(i==n) println(res.mt[i][1]);
			else printf("%lld ",res.mt[i][1]);
		}
	}
	return 0;
}
