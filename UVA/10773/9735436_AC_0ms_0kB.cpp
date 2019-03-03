#include<cstdio>
#include<cmath>
int main(){
	int T = 0, kase = 0;
	scanf("%d",&T);
	double d,v,u;
	for(int i = 0; i < T; i++){
		scanf("%lf %lf %lf",&d,&v,&u);
		printf("Case %d: ",++kase);
		if(u > v && v){
			printf("%.3lf\n",d/sqrt(u*u-v*v)-d/u);
		}
		else{
			printf("can't determine\n");
		}
	}
	return 0;
} 