#include<bits/stdc++.h>
using namespace std;

char BG[53];
bool haveswaped[52]; 
int main(){
	int n,t; cin >> n >> t;
	for(int i = 0; i < n; i++)
		cin >> BG[i];
	for(int i = 0; i < t; i++){
		memset(haveswaped,false,sizeof haveswaped);
		for(int j = 1; j < n; j++){
			if(BG[j-1] == 'B' && BG[j] == 'G' && !haveswaped[j-1]){
				swap(BG[j-1],BG[j]);
				haveswaped[j] = true;
			}
				
		}
	}
		for(int i = 0; i < n; i++)
			cout << BG[i];
		cout << endl;
		return 0; 
}