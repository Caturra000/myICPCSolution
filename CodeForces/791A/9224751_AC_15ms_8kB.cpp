#include<iostream>
using namespace std;

int main(){
	__int64  a,b;
	cin >> a >> b;
	if(a==b)
		cout << "1" << endl;
	else{
		int i = 0;
		while(a <= b){
			a *= 3; b *= 2; i++; 
		}
		cout << i << endl;
	} 
	return 0;
}