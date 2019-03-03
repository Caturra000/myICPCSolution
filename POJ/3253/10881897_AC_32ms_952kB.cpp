#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 1e5+11;
typedef long long ll;
int n,t;
int main(){
	while(scanf("%d",&n)!=EOF){
		priority_queue<int,vector<int>,greater<int> > pq; 
		ll sum=0;
		for(int i = 0; i < n; i++){
			scanf("%d",&t);
			sum+=t;
			pq.push(t);
		}
		if(pq.size()==1){
			printf("0\n");
			continue;
		}
		ll ans=0;
		while(pq.size()!=1){
			int a=pq.top();pq.pop();
			int b=pq.top();pq.pop();
			ans+=a+b;
			pq.push(a+b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}