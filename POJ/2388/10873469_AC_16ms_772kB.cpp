#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10010],n;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
		}
		nth_element(a+1,a+(n+1)/2,a+n+1);
		printf("%d\n",a[(n+1)/2]);
	}
	return 0;
}