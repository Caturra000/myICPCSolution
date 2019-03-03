#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
bool isPrime[1000005];
int prime[123456];
int num; 
int pointer;
ll sum(ll n){
	ll ans = 0;
	for(int i = n; i > 0; i/=10){
		ans += i%10;
	}
	return ans;
}
ll fact(ll n){
	ll ans = 0;
	for(int i = 0; prime[i]*prime[i] <= n; i++){
		while(n%prime[i] ==0){
			ans += sum(prime[i]);
			n/=prime[i];
		}
	}
	if(ans == 0) return -1;
	if(n > 1) ans+= sum(n);
	return ans;
}
int main(){
	int n = 1e6+3;
	memset(isPrime,true,sizeof isPrime);
	num = -1;
	for(int i = 2; i < n+1; i++){
		if(isPrime[i]){
			prime[++num] = i;
		}
		for(int j = 0; j < num+1; j++){
			int cur = prime[j]*i;
			if(cur > n) break;
			isPrime[cur] = false;
			if(i%prime[j] == 0) break;//?
		}
	}
	//cout << num << endl;
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		int query; cin >> query;
		for(ll j = query+1;;j++){ //素数只是用于分解因子，所求的数不要求一定是素数 
			if(sum(j) == fact(j)){
				cout << j << endl;
				break;
			}
		}
	}
	return 0;
	
}