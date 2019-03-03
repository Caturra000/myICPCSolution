#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll j[20];
ll jie(ll a){
	if(a==0) return 1;
	return a[j]=a*jie(a-1);
}
ll chai(ll a){
	ll sum=0;
	while(a){
		sum+=jie(a%10);
		a/=10;
	}
	return sum;
}
int main(){
//	jie(9);
//	for(ll i = 1; i <= 1e10; i++){
//		if(chai(i)==i) printf("%lld\n",i);
//	}
	printf("1\n2\n145\n40585\n"); 
	return 0;
}