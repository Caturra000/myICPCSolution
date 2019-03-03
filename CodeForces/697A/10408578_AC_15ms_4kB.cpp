#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+1e2; 
typedef long long ll;
ll t,s,x; 
int main(){
	while(scanf("%lld%lld%lld",&t,&s,&x)!=EOF){
		if(x==t) printf("YES\n");
		else if(x-t-s>=0&&(x-t-s)%s==0) printf("YES\n");
		else if(x-t-s-1>=0&&(x-t-s-1)%s==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}