#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1000005;
int book[maxn];
int b[maxn];
int main(){
	int n,m,ans;
	while(scanf("%d",&n)!=EOF){
		memset(book,0,sizeof book);
		for(int i = 0; i < n; i++){
			scanf("%d",&b[i]);
			book[b[i]]++;
		}
		sort(book,book+n);
		scanf("%d",&m);
		for(int i = (m+1)/2; i >= 0; i--){
			if(book[i]&&book[m-i]){
				ans = i;
				break;
			}
		}
		int t = m-ans;if(t<ans) swap(t,ans);
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans,t);
	}
	return 0;
}