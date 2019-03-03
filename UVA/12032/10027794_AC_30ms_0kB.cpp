#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6;
int a[maxn],b[maxn];

int main(){
	ios::sync_with_stdio(false);
	int T,kase=0; cin >> T;
	while(T--){
		int n; cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			b[i] = a[i]-a[i-1];
		}
		int k = -1;
		for(int i = n; i >= 1; i--){
			if(k==b[i]) k++;
			if(k<b[i]) k = b[i]; 
		} 
		cout << "Case " << ++kase << ": " << k << endl;
	}
	return 0;
}