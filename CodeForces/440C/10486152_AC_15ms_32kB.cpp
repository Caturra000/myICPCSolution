#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#define next n%one[now] 
#define num n/one[now]
using namespace std;
typedef __int64 ll;
ll bit[100],one[100];
map<ll,ll> memo[1000];
ll sum,x,n,flag,now;
ll dfs(ll n,ll now){
//	if(memo[now].count(n)) return memo[now][n];
	if(next==0||now==-1) return num*now;
//	return memo[now][n] = num*now+min(dfs(one[now]-next,now-1)+now,dfs(next,now-1));
	return num*now+min(dfs(one[now]-next,now-1)+now,dfs(next,now-1));
} 
int main(){
	ios::sync_with_stdio(false);
	one[1]=1;for(int i = 2; i <= 17; i++) one[i]=10*one[i-1]+1;
	while(cin>>n){
		memset(bit,0,sizeof bit);
		memset(memo,0,sizeof memo);
		ll n2 = n;
		sum=0;now=0;
//		while(n2){
//			bit[now++]=n2%10;
//			n2/=10;
//		}
		cout<<dfs(n,17)<<endl;
	}
	return 0;
}