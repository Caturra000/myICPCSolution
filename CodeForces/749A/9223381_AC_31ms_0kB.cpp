#include<cstdio>
int n,s,a=2;
int main(){
	scanf("%d",&n);
	printf("%d\n",n/2);
	if(n%2) a=3;
	for(int i = 1; i <= n/2-1; i++)
		printf("2 ");
	printf("%d\n",a);
	return 0;
}