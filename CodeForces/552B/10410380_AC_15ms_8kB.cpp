#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e5+1e2; 
typedef long long ll;
ll n,num,len,cha,sum;
int ipow(int a,int n){
	int sum = 1;
	for(int i = n; i > 0; i--)
		sum *= a;
	return sum;
}
int main(){
	while(scanf("%lld",&n)!=EOF){
		sum=0;
		while(n){
			//cout<<sum<<endl;
			if(n==1e9){
				sum+=10;
				n--;
			}
			else if(n>=1e8){
				sum+=9*(n-1e8+1);
				n=1e8-1;
			}
			else if(n>=1e7){
				sum+=8*(n-1e7+1);
				n=1e7-1;
			}
			else if(n>=1e6){
				sum+=7*(n-1e6+1);
				n=1e6-1;
			}
			else if(n>=1e5){
				sum+=6*(n-1e5+1);
				n=1e5-1;
			} 
			else if(n>=1e4){
				sum+=5*(n-1e4+1);
				n=1e4-1;
			}
			else if(n>=1e3){
				sum+=4*(n-1e3+1);
				n=1e3-1;
			}
			else if(n>=1e2){
				sum+=3*(n-1e2+1);
				n=1e2-1;
			}
			else if(n>=1e1){
				//cout<<n-1-10<<"ss"<<2*(n-1e1-1)<<endl;
				sum+=2*(n-1e1+1);
				n=1e1-1;
			}
			else{
				sum+=n;
				n=0;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}