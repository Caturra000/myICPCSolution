#include<bits/stdc++.h>
std::string s,t;
int main(){
	while(std::cin>>s>>t){
		int l=0,flag=0;
		for(int i = 0; i < t.length(); i++){
			if(t[i]==s[l]) l++;
			if(l==s.length()) flag=1;
		}
		std::cout<<(flag?"Yes\n":"No\n");
	}
	return 0;
} 