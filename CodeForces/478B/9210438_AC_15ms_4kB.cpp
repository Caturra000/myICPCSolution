#include<iostream>
using namespace std;
int main(){
	long long n,m; cin >> n >> m;
	long long ans1,ans2;
	ans1 = (n-m+1)*(n-m)/2;
	long long delta = n-(long long)m*(n/m);
	//d:C(2,n/m+1) m-d:C(2,n/m) 
	ans2 = delta*(long long)(n/m+1)*(n/m)/2 + (m-delta)*(long long)(n/m)*(n/m-1)/2;
	cout << ans2 << " " << ans1 << endl;
	return 0;
}