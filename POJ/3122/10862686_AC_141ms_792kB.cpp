#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e4+11;
const double pi = 2*acos(0.0); 
const double oo = 1e12;
int n,f,a[maxn];
bool C(double x){
	long long tmp=0;
	for(int i = 0; i < n; i++){
		tmp+=a[i]*a[i]/x/x;
	}
	return tmp>f?1:0;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&f);
		for(int i = 0; i < n; i++) scanf("%d",&a[i]);
		double l = 0, r = oo, mid;
		for(int i = 0; i < 100; i++){
			mid=l+(r-l)/2.0;
			if(C(mid)) l=mid;
			else r=mid;
		}
		printf("%.4f\n",pi*mid*mid);
	}
	return 0;
}