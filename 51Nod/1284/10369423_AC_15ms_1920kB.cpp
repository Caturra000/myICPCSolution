#include<cstdio>
long long n,t;
int main(){
	while(scanf("%lld",&n)!=EOF){
		t=0;
		t+=n/2+n/3+n/5+n/7;
		t-=n/2/3;t-=n/2/5;t-=n/2/7;t-=n/3/5;t-=n/3/7;t-=n/5/7;
		t+=n/2/3/5;t+=n/2/3/7;t+=n/2/5/7;t+=n/3/5/7; 
		t-=n/2/3/5/7;
		printf("%lld\n",n-t);
	}
	return 0;
}