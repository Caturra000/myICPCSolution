#include<cstdio>
#include<cmath>
const double pi = acos(-1.0);
double L,n,c,now;
bool C(double x){
	return now*sin(x)/x>L;
} 
int main(){
	while(scanf("%lf%lf%lf",&L,&n,&c)!=EOF){
		if(L<0) break;
		now=L*(1+n*c);
		double l=0.0,r=pi/2,mid;
		for(int i = 0; i < 500; i++){
			mid=(l+r)/2;
			if(C(mid)) l=mid;
			else r=mid;
		}
		printf("%.3f\n", L/2*tan(mid/2));
	}
	return 0;
}