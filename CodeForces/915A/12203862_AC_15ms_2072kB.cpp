#include<bits/stdc++.h>
using namespace std;
int a[11111],n,k;
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n,greater<int>());
		int ans=k;
		for(int i = 1; i <= n; i++){
			if(k%a[i]==0){
				ans=k/a[i];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}