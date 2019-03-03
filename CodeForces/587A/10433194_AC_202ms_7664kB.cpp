#include<stdio.h>
#include<string.h>
int w[2005001],m,x,n;
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(w,0,sizeof w);
		int i;
		for(i = 0; i < n; i++){
			scanf("%d",&x);
			w[x]++;
		}
		for(i = 1; i <= 2005001-5; i++){
			w[i]+=(w[i-1]/2);
			w[i-1]%=2;
		}
		int sum = 0;
		for(i = 0; i < 2005001; i++){
			sum+=w[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}