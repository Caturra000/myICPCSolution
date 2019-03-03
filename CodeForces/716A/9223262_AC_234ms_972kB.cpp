#include<iostream>
#include<algorithm>
using namespace std;
long long typ[123004];
int main(){
	long long n,sec; cin >> n >> sec;
	for(int i = 1; i <= n; i++){
		cin >> typ[i]; 
	}
	bool flag = false;
	long long sum = 1;
	for(int i = n; i >= 1; i--){
		if(flag){
			break; 
		}
		if(typ[i]-typ[i-1] > sec){
			flag = 1;
		}
		else{
			sum += 1;
		}
	}
	if(sum > n) sum = n;//多了个1 
	cout << sum << endl;
	return 0;
}