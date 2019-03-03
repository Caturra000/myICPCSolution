#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 ll;
ll sum,x,n,flag;
char str[233];
int main(){
	while(scanf("%I64d",&n)!=EOF){
		sum = 1ll<<n;sum--;
		scanf("%s",str);
		for(int i = 0; i < n; i++){
			if(str[i]=='R') sum=sum-(1ll<<i);
		}
		printf("%I64d\n",sum);
	}
	return 0;
}