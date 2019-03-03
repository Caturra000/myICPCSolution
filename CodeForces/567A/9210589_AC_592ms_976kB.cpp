#include<iostream>
#include<algorithm>
using namespace std;
long long a[123456];
int main(){
	int n,ans1,ans2; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		if(!i) ans1 = (-1)*(a[0]-a[1]);
		else if(i==n-1) ans1 = a[n-1]-a[n-2];
		else ans1 = min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]));
		cout << ans1 << " ";
		if(!i) ans2 = a[n-1]-a[0];
		else if(i==n-1) ans2 = a[n-1]-a[0];
		else ans2 = max(abs(a[i]-a[n-1]),abs(a[i]-a[0]));
		cout << ans2 << endl;
	}
	return 0;
} 