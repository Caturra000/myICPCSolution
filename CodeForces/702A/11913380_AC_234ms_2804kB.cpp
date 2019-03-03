#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int a[maxn],b[maxn],n;
int main(){
	while(cin>>n){
		for(int i = 1; i <= n; i++) cin>>a[i];
		for(int i = 1; i <= n; i++) b[i]=1;
		for(int i = 2; i <= n; i++){
			if(a[i]>a[i-1]) b[i]=b[i-1]+1;
		}
		int mx=-10086;
		for(int i = 1; i <= n; i++) mx=max(mx,b[i]);
		cout<<mx<<endl;
	}
	return 0;
}