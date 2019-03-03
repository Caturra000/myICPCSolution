#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll sum,x,n,flag;
int main(){
	while(scanf("%lld",&n)!=EOF){
		sum=0;flag=0;
		for(int i = 0; i < n; i++){
			scanf("%lld",&x);
			if(x%2!=0) flag=1;
			sum+=x;
		}
		if(sum%2) flag = 1;
		if(flag) printf("First\n");
		else printf("Second\n");
	}
	return 0;
} 