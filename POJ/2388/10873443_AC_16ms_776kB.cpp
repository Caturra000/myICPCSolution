#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
int a[maxn],n;
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