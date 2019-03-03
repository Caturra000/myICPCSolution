#include<bits/stdc++.h>
using namespace std;
int f[12345];   //O(nlogn)
int main(){
	int n,m; cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> f[i];
	sort(f,f+m);
	int ans = 99999999;
	for(int i = n-1; i < m; i++){
		ans = min(ans,f[i]-f[i-n+1]);
	}
	cout << ans << endl;
	return 0;
}