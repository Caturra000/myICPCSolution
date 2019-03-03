#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6;
int a[maxn]; 
int main(){
	int T,kase=0; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		int mmax = 0;
		//memset(a,0,sizeof a);
		for(int i = 1; i <= n; i++){ //缺少对第一列的判断 
			scanf("%d",&a[i]);
			mmax = max(mmax,a[i]);
		}
		long long l = 0, r = mmax+n, mid, ans;
		while(l<=r){ // =
			mid = (l+r)/2;
			int remain = mid,flag = 0;
			for(int i = 0; i <= n; i++){
				if(a[i]-a[i-1]==remain){
					remain--;
				}
				else if(a[i]-a[i-1]>remain){
					flag = 1;
					break;
				}
			}
			if(flag==1) l = mid+1;
			else{
				//
				ans = mid;
				//if(r==l) break;
				r = mid-1;
				//
			}	 
		}
		printf("Case %d: %d\n",++kase,ans);	
	}
	return 0;
}