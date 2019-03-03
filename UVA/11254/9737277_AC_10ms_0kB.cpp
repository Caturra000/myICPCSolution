#include<cstdio>
#include<cmath>

int main(){
	int Sn,a1,an;
	while(scanf("%d",&Sn)==1){
		if(Sn == -1)
			break;
		else{
			int sqr = sqrt(2*Sn);
			for(int n = sqr; n > 0; n--){
				if((2*Sn-n*(n-1))%(2*n) == 0){
				 //2Sn = 2na1 + n(n-1)   ===> a1 = .....
				 a1 = (2*Sn-n*(n-1))/(2*n);
				 an = a1+n-1;
				 break;
				}
			}
			
		}
		printf("%d = %d + ... + %d\n",Sn,a1,an);
	}
	return 0;
}