#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll; 
const int maxn = 1e5+1e2;
ll n,a[maxn],pos,flag;
int main(){
	while(scanf("%lld",&n)!=EOF){
		for(int i = 0; i < n; i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);flag=0;
		for(int i = 0; i < n-2; i++){
			if(a[i]+a[i+1]>a[i+2]) flag=1;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}