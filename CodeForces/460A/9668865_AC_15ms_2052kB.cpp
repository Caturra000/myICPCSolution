#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,d=0; cin >> n >> m;
	for(int i = n; i > 0; i--){
		if(++d % m == 0)
			i++;
	}
	cout << d << endl;
	return 0;
}