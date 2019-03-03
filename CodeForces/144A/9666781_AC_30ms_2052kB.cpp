#include<bits/stdc++.h>
using namespace std;
int a[123];
int main(){
	int n; cin >> n;
	int mmin = 0,mmax = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		if(a[i] <= a[mmin]) mmin = i;
		if(a[i] > a[mmax]) mmax = i;
	}
	mmin++;mmax++;
	if(mmin > mmax)
		cout << n-mmin + mmax-1 << endl;
	else
		cout << n-mmin + mmax-1 -1 << endl;
	return 0;
}