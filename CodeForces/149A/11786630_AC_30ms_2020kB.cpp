#include<bits/stdc++.h>
using namespace std;
const int maxn = 111;
int a[maxn],k;
int main(){
	while(cin>>k){
		for(int i = 0; i < 12; i++) cin>>a[i];
		sort(a,a+12,greater<int>());
		int flag=0;
		int sum=0;
		if(k==0){cout<<0<<endl;continue;}
		for(int i = 0; i < 12; i++){
			sum+=a[i];
			if(sum>=k){
				flag=i+1;
				break;
			}
		}
		if(flag)cout<<flag<<endl;
		else cout<<-1<<endl;
	}
}