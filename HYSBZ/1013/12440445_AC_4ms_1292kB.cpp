#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 1e5+11;
const double eps = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;
vec gauss(const mat& A,const vec& b){
	int n=A.size();
	mat B(n,vec(n+1));
	rep(i,0,n-1)rep(j,0,n-1)B[i][j]=A[i][j];
	rep(i,0,n-1) B[i][n]=b[i];
	rep(i,0,n-1){
		int now=i;
		rep(j,i,n-1){
			if(abs(B[j][i])>abs(B[now][i])){
				now=j;
			}
		}
		swap(B[i],B[now]);
		if(abs(B[i][i])<eps)return vec();
		rep(j,i+1,n) B[i][j]/=B[i][i];
		rep(j,0,n-1) if(i!=j){
			rep(k,i+1,n){
				B[j][k]-=B[j][i]*B[i][k];
			}
		} 
	}
	vec x(n);
	rep(i,0,n-1) x[i]=B[i][n];
	return x; 
}
int main(){
	int n;
	double a0[22];
	while(scanf("%d",&n)!=EOF){
		mat A(n,vec(n));
		vec b(n);
		rep(i,0,n-1) scanf("%lf",&a0[i]);
		double dis0=0;
		rep(i,0,n-1) dis0+=a0[i]*a0[i];
		rep(i,0,n-1){
			double dis2=0;
			rep(j,0,n-1){
				scanf("%lf",&A[i][j]);
				dis2+=A[i][j]*A[i][j];
				A[i][j]=2*(A[i][j]-a0[j]);
			}
			b[i]=dis2-dis0;
		}
		vec x=gauss(A,b);
		for(int i=0;i<x.size();i++){
			if(i==x.size()-1) printf("%.3lf\n",x[i]);
			else printf("%.3lf ",x[i]);
		}
	}
	return 0;
}