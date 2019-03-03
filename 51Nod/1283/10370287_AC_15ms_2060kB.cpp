#include<bits/stdc++.h>
const double eee = 1e-5;
long long S;
int main(){
	while(scanf("%lld",&S)!=EOF){
		double x = sqrt(S)+0.5;//std::cout<<x;
		if(x*x==S) printf("%lld\n",4*(long long)x);
		else{
			for(int i = x; i > 0; i--){
				if(S/(i*1.0)==S/i){
					printf("%lld\n",2*(i+S/i));//2ab
					break;
				}
			}
		}
	}
	return 0;
}