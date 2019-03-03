#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int a[maxn],n;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		long long sum=0;
		int ans=0;
		for(int i = 1; i <= n; i++){
			if(a[i]>=sum){
				sum+=a[i];
			}
			else{
				ans++;
			}
		}
		printf("%d\n",n-ans);
	}
	return 0;
}