#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
string str;
int k;
int main(){
	while(cin>>k>>str){
		long long sum=0;
		for(int i = 0; i < str.length(); i++) sum+=str[i]-'0';
		if(sum>=k){cout<<0<<endl;continue;}
		sort(str.begin(),str.end());
		int cnt=0;
		for(int i = 0;i < str.length(); i++){
			sum+=9-(str[i]-'0');cnt++;
			if(sum>=k){cout<<cnt<<endl;break;}
		}
	}
	return 0;
}