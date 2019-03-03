#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+11;
int f(int n){
	return n==1?1:f(n/2)+1;
} 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",f(n));
	}
	return 0;
}