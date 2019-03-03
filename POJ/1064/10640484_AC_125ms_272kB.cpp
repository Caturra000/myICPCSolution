#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e4+11;
const double esp = 1e-8;
double a[maxn];
int n,m;
bool check(double x){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum+=(int)(a[i]/x);
	}
	return sum>=m;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		double maxx=0;
		for(int i = 0; i < n; i++){
			scanf("%lf",&a[i]);
			maxx=max(maxx,a[i]);
		}
		double l = 0, r = maxx, mid;
		while(r-l>esp){
			mid = (l+r)/2;
			if(check(mid)) l=mid;
			else r=mid;
		}
		printf("%.2lf\n",floor(r*100)/100);//注意不是四舍五入的!!! 
	}
	return 0;
} 