#include<cstdio>
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b); 
	int ans = n-a<b+1?n-a:b+1; 
	printf("%d\n",ans); 
	return 0;
}