#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double eee = 1e-9;
double p,q,r,s,t,u;
//e^(-n)可以用math.h里面的exp(-n)表示。
inline double solve(double x){
	return (double)p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main(){
	while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)!=EOF){
		if(solve(0)<0||solve(1)>0) printf("No solution\n");
		else{
			double l = 0, r = 1; 
			while(r-l>eee){
				double x = (l+r)/2;
				if(solve(x)<0) r = x;
				else l = x;
			}
			printf("%.4lf\n",r);
		}
	}

	return 0;
} 