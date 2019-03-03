#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h> 
#include <stdio.h>
using namespace std;
int s1[100];
int s2[100];

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		long long a;
		long long b;
		scanf("%lld%lld",&a,&b); 
		if(a==b){
			printf("%lld\n",a);
		}
		else{
			memset(s1,0,sizeof(s1));
			memset(s2,0,sizeof(s2));
			int i=0;
			int j=0;
			while(a!=0){
				int t=a%2;
				s1[i++]=t;
				a/=2;
			}
			while(b!=0){
				int t=b%2;
				s2[j++]=t;
				b/=2;
			}
			long long sum=0;
			int maxlen=max(i,j);
			for(int k=maxlen-1;k>=0;k--){
				if(s1[k]==s2[k]){
					if(s1[k]==1)
						sum+=(long long)pow(2,k);
				}
				else{
					sum+=(long long)pow(2,k+1)-1;
					break;
				}
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
} //tessttt