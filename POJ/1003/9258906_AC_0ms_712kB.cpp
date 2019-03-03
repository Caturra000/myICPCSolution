#include<iostream>
using namespace std;
int main(){
	//int T; cin >> T;
	double que;
	while(cin>>que&&que!=0){
		double ans=0;
		long long counter = 0;
		while(que>ans){
			ans += (double)1/(counter+2);//注意double 
			counter++;
		}
		cout << counter << " card(s)" << endl; 
	} 
	return 0;
} 