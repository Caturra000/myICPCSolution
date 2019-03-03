#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
const ll MOD = 1000000007;
inline ll mod(ll a){return a%MOD;}
int b[3][3]={
	{0,0,0},
	{0,1,1},
	{0,1,0},
};
ll c[3]={0,2,1};
struct Mat{
	ll m[7][7],r,c;
	void node(int rr,int cc,bool unit=0){
		r=rr;c=cc;
		memset(m,0,sizeof m);
		if(unit) for(int i = 1; i <= rr; i++) m[i][i]=1;
	}
};
Mat operator * (Mat a,Mat b){
	Mat ans;ans.node(a.r,b.c);
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= 2; j++){
			for(int k = 1; k <= 2; k++){
				ans.m[i][k]=(ans.m[i][k]+a.m[i][j]*b.m[j][k])%(MOD-1);
			}
		}
	}
	return ans;
}
Mat qmod(Mat a,ll n){
	Mat ans;ans.node(2,2,1);
	while(n){
		if(n&1) ans=ans*a;
		n>>=1;
		a=a*a;
	}
	return ans;
}
ll qmod(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=mod(mod(ans)*mod(a));
		n>>=1;
		a=mod(mod(a)*mod(a));
	}
	return mod(ans);
}
int main(){
	Mat base,base2; base.node(2,2); base2.node(2,1);
	for(int i = 1; i <= 2; i++) for(int j = 1; j <= 2; j++) 
		base.m[i][j]=b[i][j];
	for(int i = 1; i <= 2; i++) base2.m[i][1]=c[i];
	ll aa,bb,n;
	while(cin>>aa>>bb>>n){
		if(n==0){
			cout<<mod(aa)<<endl;
			continue;
		}
		if(n==1){	
			cout<<mod(bb)<<endl;
			continue;
		}
		if(n==2){
			cout<<mod(mod(aa)*mod(bb))<<endl;
			continue;
		}
		Mat tmp=qmod(base,n-3);
		Mat res=tmp*base2;
		ll ans1=res.m[1][1];//a
		ll ans2=res.m[2][1];//b
		ans1%=MOD-1;ans2%=MOD-1;
		cout<<mod(mod(qmod(aa,ans2))*mod(qmod(bb,ans1)))<<endl;
	}
	return 0;
}