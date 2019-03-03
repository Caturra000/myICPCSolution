#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e6+11;
int main(){
	int n,m;
	while(cin>>n>>m){
		double ans=0;
		for(int i = 1; i < n; i++){
			double pos=(double)i/n*(n+m);
			ans+=fabs(pos-floor(pos+0.5))/(n+m);
		}
		printf("%.4f\n",ans*10000);
	}
	return 0;
}