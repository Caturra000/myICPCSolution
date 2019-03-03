#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		if(n<=2) cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	return 0;
} 