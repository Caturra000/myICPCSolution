#include<bits/stdc++.h>
using namespace std;
int a[1011],n,pos,flag;
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof a);flag=0;
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		n=unique(a,a+n)-a;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				pos=lower_bound(a+j+1,a+n,-a[i]-a[j])-a;
				if(pos!=n&&a[pos]==-a[i]-a[j]){
					printf("%d %d %d\n",a[i],a[j],a[pos]);
					flag=1;
				}
			}
		}
		if(!flag) printf("No Solution\n");
	}
	return 0;
}