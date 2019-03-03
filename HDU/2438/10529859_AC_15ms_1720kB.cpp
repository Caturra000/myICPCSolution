#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 3e3+100;
const double eee = 1e-8;
double x,y,L,d,t,lm,rm,l,r;
double val(double t,double x,double y,double L,double d){
	return L*cos(t)+d*sin(t)-(x-d*cos(t))/tan(t);
}
int main(){
	while(scanf("%lf%lf%lf%lf",&x,&y,&L,&d)!=EOF){
		l = 0; r = acos(0);
		while(l+eee<r){
			lm = l+(r-l)/3; rm = r-(r-l)/3;
			if(val(lm,x,y,L,d)<val(rm,x,y,L,d))
				l=lm;
			else
				r=rm;
		}
		if(val(l,x,y,L,d)>y) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}