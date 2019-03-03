#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long  a,b,ans=0; cin >> a >> b;
	while(1){//gcd
		ans += a/b;
		if(a%b)
			a = a-(a/b)*b;
		else
			break;
		if(a < b)
			swap(a,b);
	}
	cout << ans << endl;
	return 0;
}