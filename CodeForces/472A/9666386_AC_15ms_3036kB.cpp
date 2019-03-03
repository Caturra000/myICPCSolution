#include<bits/stdc++.h>
using namespace std;
bool isPrime[1000005];
//int prime[1000000];
int main(){
	memset(isPrime,true,sizeof isPrime);
	isPrime[0] = false;isPrime[1] = false; 
	int n; cin >> n;
	for(int i = 2; i*i <= n;i++){
		if(isPrime[i]){
			for(int j = 2*i; j <= n; j += i){
				isPrime[j] = false;
			}
		}
	}
	//int j = 0;
	//for(int i = 1; i <= n; i++){
	//	if(isPrime[i])
	//		prime[++j] = i;//1-based
	//}
	for(int i = 3; i <= n; i++){
		if(!isPrime[i] && !isPrime[n-i]){
			cout << i << " " << n-i << endl;
			return 0;
		}
	}
} 