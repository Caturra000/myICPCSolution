#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[123456];
//int sum[12345];//sumi = a0+....ai-1

int main(){
	int n,S,T; scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&S);
		//memset(sum,0,sizeof sum);
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
			//sum[i+1] = sum[i]+a[i];
		}
		/*solution1 O（nlogn）
		if(sum[n]<S){//failed
			printf("0\n");
		}
		else{
			int ans = n;
			for(int s = 0; sum[s]+S<=sum[n]; s++){
				int t = lower_bound(sum+s,sum+n,sum[s]+S)-sum;
				ans = min(ans,t-s);
			}
			printf("%d\n",ans);
		}
		*/
		
		int ans = n+1;
		int s = 0, t = 0, sum = 0;
		while(1){
			while(t<n && sum<S){//起点不变，后端不断取at 
				sum+=a[t];t++;
			}
			if(sum<S) break;
			ans = min(ans,t-s);
			sum -= a[s]; s++;//起点前进一位 
		}
		if(ans>n) ans = 0;
		printf("%d\n",ans);
	}
	return 0;
} 

/************************************************Core
while(1){
	while(t<n && sum<S){
		sum+=a[t];t++
	}
	if(sum<S) break;
	ans = min(ans,t-s);
	sum-=a[s];s++;
} 
if(ans>n) printf("0\n");
else printf("%d\n",ans);
****************************************************/