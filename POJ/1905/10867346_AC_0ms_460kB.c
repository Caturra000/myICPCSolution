#include<stdio.h>
#include<math.h>
double L,n,c,now,i;
int main(){
	while(scanf("%lf%lf%lf",&L,&n,&c)!=EOF){
		if(L<0) break;
		now=L*(1+n*c);
		double l=0.0,r=3.14159265358/2,mid;
		for(i = 0; i < 500; i++){
			mid=(l+r)/2;
			if(now*sin(mid)/mid>L) l=mid;
			else r=mid;
		}
		printf("%.3f\n", L/2*tan(mid/2));
	}
	return 0;
}