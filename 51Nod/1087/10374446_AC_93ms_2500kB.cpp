#include<bits/stdc++.h>
using namespace std;
int a[111100];
int main(){
	memset(a,0,sizeof a);a[1]=1;int k,nn,n = 110000;
	for(int i = 2;i<=1e5+1e4;i++) a[i]=a[i-1]+i-1;
	while(scanf("%d",&nn)!=EOF){
		for(int i = 0; i < nn; i++){
			scanf("%d",&k);
			int ans = lower_bound(a+1,a+111100,k)-a;
			if(ans!=n&&a[ans]==k) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}