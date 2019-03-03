#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)^-1){
		printf("%.20lf\n",(1.0*b-a)/(c+d));
	}
	return 0;
}