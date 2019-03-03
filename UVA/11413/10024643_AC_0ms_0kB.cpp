#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[100000];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int sum=0,mmax=0;
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			mmax=max(mmax,a[i]);
		}
		int l = mmax, r = sum,mid,x;
		while(l<=r){//二分枚举范围 
			mid = (l+r)/2;
			int add = 0, cnt = 1;//满足中值的container 
			for(int i = 0; i < n; i++){
				add+=a[i];
				if(add>mid){//超过就要另取 
					cnt++;
					add = a[i]; //满了就从下一个开始 
				}
			}
			if(cnt<=m){
				x = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}