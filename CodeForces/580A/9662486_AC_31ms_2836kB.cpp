#include<bits/stdc++.h>
using namespace std;
long long n,a[100006],ans = 1;
int main(){
	cin >> n;
	long long l = 0,r = 0;
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]); 
	for(int i = 1; i < n; i++){
		if(a[i-1] <= a[i]){
			r++;
		}
		else{
			l = i; r = i;
		}
		ans = max(ans,r-l+1);
	}
	cout << ans << endl;
	return 0;
}