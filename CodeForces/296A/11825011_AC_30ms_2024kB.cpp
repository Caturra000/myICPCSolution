#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 1e3+11;
int num[maxn],x,n;
int main(){
	while(cin>>n){
		memset(num,0,sizeof num); 
		rep(i,1,n){
			cin>>x;
			num[x]++;
		}
		sort(num,num+maxn,greater<int>());
		printf("%s\n",num[0]>(n+1)/2?"NO":"YES");
	}
	return 0;
}