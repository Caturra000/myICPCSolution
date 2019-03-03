#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Matrix{
    ll mt[9][9],r,c;
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
                    ans.mt[i][j]+=(mt[i][k]*rhs.mt[k][j])%mod;
                    ans.mt[i][j]=(ans.mt[i][j])%mod;
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
ll a0,ax,ay,b0,bx,by;
ll n;
ll bas2[8],base[8][8];
int main(){
	while(cin>>n){
		cin>>a0>>ax>>ay;
		cin>>b0>>bx>>by;
		if(n==0){
			println(0);
			continue;
		}
		bas2[1]=(a0%mod)*(b0%mod)%mod;bas2[2]=a0%mod;bas2[3]=b0%mod;bas2[4]=(ay%mod)*(by%mod)%mod;
		bas2[5]=ay%mod;bas2[6]=by%mod;    bas2[7]=0;
		memset(base,0,sizeof base);
		base[1][1]=(ax%mod)*(bx%mod)%mod;base[1][2]=(ax%mod)*(by%mod)%mod;base[1][3]=(ay%mod)*(bx%mod)%mod;base[1][4]=1;
		base[2][2]=ax%mod;base[2][5]=1;
		base[3][3]=bx%mod;base[3][6]=1;
		base[4][4]=1;
		base[5][5]=1;
		base[6][6]=1;
		base[7][1]=1;base[7][7]=1;
		Matrix A; A.init(7,7);
		rep(i,1,7)rep(j,1,7) A.mt[i][j]=base[i][j];
		Matrix b; b.init(7,1);
		rep(i,1,7) b.mt[i][1]=bas2[i];
		Matrix res=fpw(A,n)*b;
		println(res.mt[7][1]);
	}
	return 0;
}
