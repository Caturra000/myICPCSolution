#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
//ll gcd(ll a,ll b){
//	return b==0?a:gcd(b,a%b);
//}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	b = min(a,b);
	int ans = 1;
	for(int i = 1; i <= b; i++) ans=ans*i;
	printf("%d\n",ans);
	return 0; 
}