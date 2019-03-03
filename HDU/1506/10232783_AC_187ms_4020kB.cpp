#include<iostream>
#include<algorithm>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100010;
ll a[maxn],l[maxn],r[maxn];
ll n,tl,tr,ans;
int main(){
	while(scanf("%lld",&n),n){
		for(int i = 1; i <= n; i++){
			scanf("%lld",&a[i]);
			l[i]=i;r[i]=i;
		}
		for(int i = 2; i <= n; i++){//找出连续比自身高度大的区间 
			tl = l[i];
			while(tl>1&&a[i]<=a[tl-1]) tl = l[tl-1]; //NOTE:tl>1 && 记忆化 
			l[i] = tl; 
		}
		for(int i = n-1; i >= 1; i--){
			tr = r[i];
			while(tr<n&&a[i]<=a[tr+1]) tr = r[tr+1];
			r[i] = tr;
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			ans = max(ans,a[i]*(r[i]-l[i]+1));
		}
		printf("%lld\n",ans);
	}
	return 0;
} 