#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
typedef unsigned long long ll;
ll sum(ll a1,ll n,ll d){
	return n*a1+n*(n-1)*d/2;
}
int main(){
	int T,n; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);n--; 
		ll a=n/3*3,b=n/5*5,c=n/15*15;
		ll n1=a/3,n2=b/5,n3=c/15;
		printf("%llu\n",sum(3,n1,3)+sum(5,n2,5)-sum(15,n3,15));
	}
	return 0;
}