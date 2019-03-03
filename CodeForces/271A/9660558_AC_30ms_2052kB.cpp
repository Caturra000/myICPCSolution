#include<bits/stdc++.h>
using namespace std;
int i,y[6],yy;
int main(){
	cin >> yy;
	for(int i = yy+1; i <= 9999; i++){
		int q,w,e,r;
		q = i%10; w = (i/10)%10; e = (i/100)%10; r =  (i/1000)%10;
		if(q != w && q != e && q != r && w != e && w != r && e != r){
			cout << i << endl;
			return 0;
		}
	}
}