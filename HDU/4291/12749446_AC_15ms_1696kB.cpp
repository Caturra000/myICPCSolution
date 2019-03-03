#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
typedef long long ll;
ll mod = 183120;
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
ll n;
ll base[3][3]={
	{0,0,0},
	{0,3,1},
	{0,1,0}
};
int main(){
	while(cin>>n){
		mod=183120;
		Matrix A; A.init(2,2);
		rep(i,1,2)rep(j,1,2) A.mt[i][j]=base[i][j];
		Matrix res=fpw(A,n);
		mod=222222224;
		res=fpw(A,res.mt[1][2]%183120);
		mod=1e9+7;
		res=fpw(A,res.mt[1][2]%222222224);
		println(res.mt[1][2]); 
	}
	return 0;
}
