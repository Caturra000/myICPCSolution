#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long  player[1000+5];

int main(){
	int n,m,k; cin >> n >> m >> k;
	int sum = 0;
	for(int i = 1; i <= m+1; i++){
		cin >> player[i];
	}
	for(int i = 1; i <= m; i++){
		int ksum = 0;
		for(int j = 0; j < n/*log2(player[i])*/; j++){
			if( (player[m+1]^player[i]) & (1<<j) ){
				ksum++;
			}
		}
		if(ksum <= k){
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}