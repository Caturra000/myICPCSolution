#include<iostream>
using namespace std;
int main(){
	int n,a,f=0; cin>>n;
	while(n--){
		cin>>a;
		if(a==1) f = 1;
	}
	cout<<(f?-1:1)<<endl;
	return 0; 
} 