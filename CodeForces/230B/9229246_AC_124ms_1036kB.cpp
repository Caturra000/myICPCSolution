#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
bool isPrime[1<<20];
__int64 mmax,inp,rang,r,a;
int main(){
	//aishishaixuan
	for(int i = 2; i <= 1e6; i++){
		isPrime[i] = true;
	}
	for(int i = 2; i*i <= 1e6; i++){
		if(isPrime[i]){
			for(int j = 2*i; j <= 1e6; j+=i){
				isPrime[j] = false;
			}
		}
	}
	//prove:isPrime[a] N
	int n; scanf("%d",&n);
	for(int i = 0; i < n; i++){
			scanf("%I64d",&a);
			r = sqrt(a);
			if(r*r==a && isPrime[r]){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
	}
	return 0;
}
 