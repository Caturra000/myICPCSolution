#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
	while(cin>>s>>t){
		int l=0,flag=0;
		for(int i = 0; i < t.length(); i++){
			if(t[i]==s[l]) l++;
			if(l==s.length()) flag=1;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl; 
	}
	return 0;
} 