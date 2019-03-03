#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
int a,b,c,x,y;
double C(double X){
	double Y=(double)a*X*X+b*X+c;
	return (X-x)*(X-x)+(Y-y)*(Y-y);
}
int main(){
	while(cin>>a>>b>>c>>x>>y){
		double l=-1e3,r=1e3;
		while(r-l>1e-4){
			double lm=(l+r)/2;
			double rm=(lm+r)/2;
			if(C(lm)<C(rm)){
				r=rm;
			}else{
				l=lm;
			}
		}
		printf("%.3lf\n",(sqrt(C(l))));
	} 
	return 0; 
} 