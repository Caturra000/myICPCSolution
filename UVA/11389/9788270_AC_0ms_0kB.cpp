#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define scan(a) scanf("%d",&a)
#define f(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
using namespace std;
int a[123],b[123];
int main(){
	 int n,d,r;
	 while(scanf("%d %d %d",&n,&d,&r)){
	 	if(n==0) break;
	 	long long ans = 0;
	 	f(i,0,n)
	 		scanf("%d",&a[i]);
	 	sort(a,a+n);
	 	f(i,0,n){
	 		scanf("%d",&b[i]);
	 		b[i] = -b[i];
	 	}
	 	sort(b,b+n);
	 	f(i,0,n)
	 		ans += max(a[i]-b[i]-d,0);
	 	printf("%d\n",ans*r);
	 }
	 return 0;
} 