#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 150;
int a[maxn];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,last,x;
	while(cin>>n){
		if(n==0) break;
		memset(a,0,sizeof a);
		last=0;
		for(int i = 0; i < n; i++){
			cin>>x;
			a[x]++;
			last=max(last,x);
		}
		for(int i = 0; i <= last; i++){
			while(a[i]){
				a[i]--;
				if(i==last&&!a[i]) cout<<i<<endl;
				else cout<<i<<" ";
			}
		}
	}
	return 0;
}