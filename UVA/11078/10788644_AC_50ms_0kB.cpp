#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
int a[maxn];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		memset(a,0,sizeof a);
		for(int i = 0; i < n; i++) scanf("%d",&a[i]);
		int ans=a[0]-a[1];
		int ai=a[0];
		for(int j = 1; j < n; j++){
			ans=max(ans,ai-a[j]);
			ai=max(ai,a[j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}